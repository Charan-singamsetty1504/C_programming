#include<linux/fs.h>
#include<linux/kernel.h>
#include<linux/device.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/init.h>
dev_t dev=0;
static struct class *dev_class;

static int __init dev_init(void);
static void __exit dev_exit(void);


static int __init dev_init(void)
{
	if(alloc_chrdev_region(&dev, 0, 1, "My_Device")<0)
	{
		pr_err("Cannot Create the Device Number\n");
		return -1;
	}
	pr_info("Device Number is Successfully created\n");
	dev_class = class_create(THIS_MODULE, "My_Device_Class");
	if(IS_ERR(dev_class))
	{
		pr_err("Cannot create the class\n");
		goto r_class;
	}
	if(IS_ERR(device_create(dev_class, NULL, dev, NULL, "My_Device")))
	{
			pr_err("Cannot Create the device\n");
			goto r_device;
	}
	pr_info("Module is inserted successfully\n");
	return 0;
	goto r_class:
		class_destroy(dev_class);
	goto r_device:
		unregister_chrdev_region(dev, 1);
return -1;

}
static void __exit dev_exit(void)
{
	device_destroy(dev_class, dev);
	class_destroy(dev_class);
	unregister_chrdev_region(dev);

}
module_init(dev_init);
module_exit(dev_exit);

ODULE_LICENSE("GPL");
