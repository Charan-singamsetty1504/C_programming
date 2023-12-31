#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int sensorID;
char *sensorName;


module_param(sensorID, int, S_IRUSR|S_IWUSR);
module_param(sensorName, charp, S_IRUSR|S_IWUSR);


static int __init entry_init(void)
{
    pr_info("Module Param driver is loaded");
    pr_info("The Sensor ID passed is: %d", sensorID);
    printk(KERN_INFO "The Sensor Name passed is %s", sensorName);
    return 0;
}
static void __exit entry_exit(void)
{
    printk(KERN_INFO "This module is unloaded");
}
module_init(entry_init);
module_exit(entry_exit);

MODULE_LICENSE("GPL");