#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/gfp.h>
#include<linux/mm.h>


static struct page *mypage;

static int __init my_init(void)
{
	mypage = alloc_page(GFP_KERNEL);
	if(!mypage)
	{
		printk(KERN_ALERT"Failed to allocate Memory\n");
		return -ENOMEM;
	}
	printk(KERN_INFO"Successfully allocated a page of memory\n");
	return 0;
}
static void __exit my_exit(void)
{
	if(mypage)
	{
		__free_page(mypage);
		printk(KERN_INFO"Memory allocation demo module unloaded\n");		
	}
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");



