#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
static int __init helloworld_init(void)
{
	pr_info("Hello, World\n");
	return 0;
}

static void __exit helloworld_ex(void)
{
	pr_info("Goodbye\n");
}
module_init(helloworld_init);
module_exit(helloworld_ex);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("A Simple Hello World Kernel Module");
//MODULE_INFO(board, "Beaglebone black REV A5");

