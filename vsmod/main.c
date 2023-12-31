#include<linux/init.h>
#include<linux/module.h>


static int __init hello_init_module(void)
{
    pr_info("This is a module entry\n");
    return 0;
}

static void __exit hello_exit_module(void)
{
    pr_info("This is a module exit\n");
}

module_init(hello_init_module);
module_exit(hello_exit_module);

MODULE_LICENSE("GPL");