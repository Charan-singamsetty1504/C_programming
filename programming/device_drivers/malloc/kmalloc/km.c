#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/device.h>
#include<linux/kdev_t.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>

#define DEVICE_NAME "mydevice"
#define BUFFER_SIZE 1024

static int major_number = 0;
static char *device_buffer;

static int device_open(struct inode *inode, struct file *filp)
{
	printk(KERN_INFO"Device Opened\n");
	return 0;
}
static int device_release(struct inode *inode, struct file *filp)
{
	printk(KERN_INFO"Device released\n");
	return 0;
}
static ssize_t device_read(struct file *filp, char __user *buf, size_t count, loff_t *off)
{
	int bytes_read = 0;
	if(*off >= BUFFER_SIZE)
	{
		return 0;
	}
	if(*off + count > BUFFER_SIZE) {
		count = BUFFER_SIZE - *off;
	}
	if(copy_to_user(buf, device_buffer + *off, count)) {
		
		return -EFAULT;
	}
	*off += count;
	bytes_read = count;
	printk(KERN_INFO"Read %d bytes from device\n", bytes_read);
	return bytes_read;
}
static ssize_t device_write(struct file *filp, const char __user *buf, size_t count, loff_t *off)
{
	int bytes_written = 0;
	if(*off >= BUFFER_SIZE)
	{
		return -ENOSPC;
	}
	if(*off + count > BUFFER_SIZE)
	{
        	count=BUFFER_SIZE - *off;
	}
	if(copy_from_user(device_buffer + *off, buf, count))
	{
		return -EFAULT;
	}
	*off += count;
	bytes_written = count;
	printk(KERN_INFO"Wrote %d bytes to device\n", bytes_written);
	return bytes_written;
}
static struct file_operations fops = 
					{
						.owner = THIS_MODULE, 
						.open  = device_open, 
						.release = device_release, 
						.read = device_read, 
						.write = device_write, 
					};
static int __init device_init(void)
{
	major_number = register_chrdev(0, DEVICE_NAME, &fops);
	if(major_number < 0)
	{
		printk(KERN_INFO"Failed to Register Major number\n");
		return major_number;
	}
	device_buffer = kmalloc(BUFFER_SIZE, GFP_KERNEL);

	if(!device_buffer)
	{
		unregister_chrdev(major_number, DEVICE_NAME);
		printk(KERN_ALERT"Failed to allocate memory\n");
		return -ENOMEM;
	}
	memset(device_buffer, 0, BUFFER_SIZE);
	printk(KERN_INFO"Kmalloc Device initialized\n");
	return 0;
}
static void __exit device_exit(void)
{
	unregister_chrdev(major_number, DEVICE_NAME);
	kfree(device_buffer);
	printk(KERN_INFO"Device Removed\n");
}
module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
