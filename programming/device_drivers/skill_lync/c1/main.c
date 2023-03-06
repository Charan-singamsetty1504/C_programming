#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("CHARAN");
MODULE_DESCRIPTION("FIRST_HELLO_WORLD_MODULE");

static int __init hello_start()
{
   printk(KERN_INFO,  
