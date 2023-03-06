#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/module.h>

static int __init hello_init(void)
{
	pr_info(KERN_INFO"This is an entry point\n");
	return 0;
}
static void __exit hello_exit(void)
{
	pr_info(KERN_INFO"This is an exit point\n");
	
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
