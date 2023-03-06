#include <linux/module.h>
#include <linux/netdevice.h>

#define DRIVER_NAME "my_network_driver"

static struct net_device *my_dev;

static int my_open(struct net_device *dev)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}

static int my_release(struct net_device *dev)
{
    printk(KERN_INFO "Device released\n");
    return 0;
}

static const struct net_device_ops my_ops = {
    .ndo_open = my_open,
    .ndo_stop = my_release,
};

static void my_setup(struct net_device *dev)
{
    ether_setup(dev);
    dev->netdev_ops = &my_ops;
}

static int __init my_init(void)
{
    my_dev = alloc_netdev(0, DRIVER_NAME, my_setup);
    if (!my_dev)
        return -ENOMEM;

    register_netdev(my_dev);

    printk(KERN_INFO "%s loaded\n", DRIVER_NAME);
    return 0;
}

static void __exit my_exit(void)
{
    unregister_netdev(my_dev);
    free_netdev(my_dev);

    printk(KERN_INFO "%s unloaded\n", DRIVER_NAME);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("My network device driver");
MODULE_LICENSE("GPL");

