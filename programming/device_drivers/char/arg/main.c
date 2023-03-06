#include<linux/module.h>
#include<linux/init.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>

int var_one, var_arr[4];
char *var_name="This is my Device";
int var_two=0;

module_param(var_one, int, S_IRUSR|S_IWUSR);
module_param(var_name, charp, S_IRUSR | S_IWUSR);
module_param_array(var_arr, int, NULL, S_IRUSR | S_IWUSR);

int notify_param(const char *val, const struct kernel_param *kops)
{
	int res = param_set_int(val, kops);
	if(res==0)
	{
		pr_info("Callback Function is Called\n");
		pr_info("The Value of the second variable is %d\n", var_two);
		return 0;
	}
	return -1;
}

const struct kernel_param_ops fops =
{
	.set = &notify_param,
	.get = &param_get_int,
};

module_param_cb(var_two, &fops, &var_two, S_IRUSR | S_IWUSR);

static int __init dev_init(void)
{
	int i;
	printk(KERN_INFO"The Value of the first variable is %d\n", var_one);
        printk(KERN_INFO"The Value of the second variable is %d\n", var_two);
  	printk(KERN_INFO"Tha Name of the variable is %s\n", var_name);
	for( i=0;i<4;i++)
	{
	printk(KERN_INFO"The Array Value is [%d]\n", var_arr[i]);
	}
pr_info("The Module is inserted successfully\n");
return 0;
}
static void __exit dev_exit(void)
{
	printk("The Module is Removed successfully\n");
}

module_init(dev_init);
module_exit(dev_exit);

MODULE_LICENSE("GPL");

			


