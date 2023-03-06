#include<linux/module.h>
#include<linux/moduleparam.h>

static int param = 0;
static char *paramc = "charan";

module_param(param, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(param, "An integer parameter");
module_param(paramc, charp, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(paramc, "A string parameter");

static int __init my_module_init(void)
{
	printk(KERN_INFO"My param1 %d\n", param);
	printk(KERN_INFO"my param2 %s\n", paramc);
	return 0;
}

static void __exit my_module_exit(void)
{
	printk(KERN_INFO"Exiting my module\n");
}
module_init(my_module_init);
module_exit(my_module_exit);
MODULE_LICENSE("GPL");
