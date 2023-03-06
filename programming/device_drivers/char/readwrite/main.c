#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>

dev_t dev=0;

static struct class *dev_class;
static struct cdev dev_cdev;

static int __init dev_init(void);
static void __exit dev_exit(void);
static int dev_open(struct inode *inode, struct file *filp);
static int dev_release(struct inode *inode, struct file *filp);
static ssize_t dev_read(struct file *filp, char __user *buf, size_t length, loff_t *off);
static ssize_t dev_write(struct file *filp, const char __user *buf, size_t length, loff_t *off);

static struct file_operations fops = 
					{
						.owner = THIS_MODULE,
						.open = dev_open, 
						.release = dev_release, 
						.read = dev_read, 
					        .write = dev_write, 
					};

static int dev_open(struct inode *inode, struct file *filp)
{
	pr_info("Device is opened\n");
	return 0;
}
static int dev_release(struct inode *inode, struct file *filp)
{
	pr_info("Device is released\n");
	return 0;
}
static ssize_t dev_read(struct file *filp, char __user *buf, size_t length, loff_t *off)
{
	pr_info("Device reader function is called\n");
	return 0;
}
static ssize_t dev_write(struct file *filp, const char __user *buf, size_t length, loff_t *off)
{
	pr_info("Device Writer function is called\n");
	return length;
}
static int __init dev_init(void)
{
	if(alloc_chrdev_region(&dev, 0, 1, "My_Device")<0)
	{
		pr_err("Allocating the device is Failed\n");
		return -1;
	}
	cdev_init(&dev_cdev, &fops);

	if(cdev_add(&dev_cdev, dev, 1)<0)
	{
		pr_err("Cannot add the device to the system\n");
		goto r_class;
	}
	dev_class = class_create(THIS_MODULE, "My_Device");
	if(IS_ERR(dev_class))
	{
		pr_err("Cannot create the class\n");
		goto r_class;
	}
	if(IS_ERR(device_create(dev_class, NULL, dev, NULL, "My_Device")))
	{
		pr_err("Cannot create the device \n");
		goto r_device;
	}
	goto r_class:
		class_destroy(dev_class);
	goto r_device:
		unregister_chrdev_region(dev, 1);
		return -1;
	pr_info("The Device is Created Successfully\n");
	return 0;
}
static void __exit dev_exit(void)
{
	device_destroy(dev_class, dev);
	class_destroy(dev_class);
	cdev_del(&dev_cdev);
	unregister_chrdev_region(dev, 1);
	
	pr_info("Device is removed successfully\n");
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
