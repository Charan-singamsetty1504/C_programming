#include<linux/device.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/device.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>

dev_t dev = 0;

static int __init dev_init(void);
static void __exit dev_exit(void);


static int __init dev_init(void)
{
	if(alloc_chrdev_region(&dev, 0, 1, "Charan")<0)
	{
		pr_err("This is the first module\n");
		return -1;
	}
	pr_info("Module inserted success and created major and minor numbers for the driver \n");
	return 0;
}
static void __exit dev_exit(void)
{
	unregister_chrdev_region(dev, 1);
	pr_info("The Module Removed Successfully\n");
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
