#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/delay.h>
#include<linux/mutex.h>
#include<linux/err.h>
#include<linux/fs.h>

struct mutex etx_mutex;
unsigned long etx_global_variable = 0;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev etx_cdev;

static int __init etx_driver_init(void);
static void __exit etx_driver_exit(void);

static struct task_struct *etx_thread1;
static struct task_struct *etx_thread2;

static int etx_open(struct inode *inode, struct file *filp);
static int etx_release(struct inode *inode, struct file *filp);
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off);

int thread_function1(void *pv);
int thread_function2(void *pv);

int thread_function1(void *pv)
{
	while(!kthread_should_stop())
	{
		mutex_lock(&etx_mutex);
		etx_global_variable++;
		pr_info("This is thread function one \n");
		mutex_unlock(&etx_mutex);
		msleep(1000);
	}
	return 0;
}
int thread_function2(void *pv)
{
	while(!kthread_should_stop())
	{
		mutex_lock(&etx_mutex);
		etx_global_variable++;
		pr_info("This is thread function two \n");
		mutex_unlock(&etx_mutex);
		msleep(1000);
	}
	return 0;
}
static struct file_operations fops =
{
	.owner = THIS_MODULE, 
	.read = etx_read, 
	.write = etx_write, 
	.open = etx_open, 
	.release = etx_release,
};
static int etx_open(struct inode *inode, struct file *filp)
{
	pr_info("Device File is Created\n");
	return 0;
}
static int etx_release(struct inode *inode, struct file *filp)
{
	pr_info("Device File is closed\n");
	return 0;
}
static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
	pr_info("Read Function\n");
	return 0;
}
static ssize_t etx_write(struct file *filp,  const char __user *buf, size_t  len, loff_t *off)
{
	 pr_info("Write function \n");
	 return 0;
}

static int __init etx_driver_init(void)
{
	if((alloc_chrdev_region(&dev, 0, 1, "etx_Dev"))<0)
	{
		pr_info("Cannot allocate the major number \n");
		return -1;
	}
	pr_info("Major = %d Minor = %d\n", MAJOR(dev), MINOR(dev));

	cdev_init(&etx_cdev, &fops);

	        if((cdev_add(&etx_cdev,dev,1)) < 0){
            pr_info("Cannot add the device to the system\n");
            goto r_class;
        }
		if(IS_ERR(dev_class = class_create(THIS_MODULE, "etx_class")))
		{
			pr_info("cannot create the struct class \n");
			goto r_class;
		}
if(IS_ERR(device_create(dev_class, NULL, dev, NULL, "etx_device")))
{
pr_info("Cannot create the struct class\n");
goto r_device;
}
mutex_init(&etx_mutex);
etx_thread1 = kthread_run(thread_function1, NULL, "etx Thread1");
if(etx_thread1)
{
	pr_err("Kthread1 created successfully\n");
}else
{
	pr_err("Cannot Create Kthread\n");
	goto r_device;
}
etx_thread2 = kthread_run(thread_function2, NULL, dev, NULL, "etx Thread2");
if(etx_thread2)
{
	pr_err("Kthread2 created succesfully\n");
}
else
{
	pr_err("Cannot create kthread\n");
	goto r_device;
}

pr_info("Device Driver Insert...Done!!!\n");
return 0;

r_device:
	class_destroy(dev_class);
r_class:
	unregister_chrdev_region(dev, 1);
	cdev_del(&etx_cdev);
	return -1;
}

static void __exit etx_driver_exit(void)
{
	kthread_stop(etx_thread1);
	kthread_stop(etx_thread2);
	device_destroy(dev_class, dev);
	class_destroy(dev_class);
	cdev_del(&etx_cdev);
	unregister_chrdev_region(dev, 1);
	pr_info("Device Driver Remove..Done!!\n");
}
module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CHARAN.");
MODULE_DESCRIPTION("A SIMPLE DRIVER");


