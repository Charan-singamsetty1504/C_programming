#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Addition in module parameters example");

static int value1 = 0;
static int value2 = 0;
module_param(value1, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
module_param(value2, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

static int __init addition_init(void)
{
    printk(KERN_INFO "Addition in module parameters example loaded\n");
    printk(KERN_INFO "Value1: %d\n", value1);
    printk(KERN_INFO "Value2: %d\n", value2);
    printk(KERN_INFO "Result: %d\n", value1 + value2);
    return 0;
}

static void __exit addition_exit(void)
{
    printk(KERN_INFO "Addition in module parameters example unloaded\n");
}

module_init(addition_init);
module_exit(addition_exit);

