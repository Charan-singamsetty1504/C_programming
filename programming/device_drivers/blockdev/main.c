#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/blkdev.h>

#define DEVICE_NAME "myblockdev"
#define SECTOR_SIZE 512
#define NUM_SECTORS 1024

static int major_number = 0;
static struct request_queue *queue = NULL;
static struct gendisk *disk = NULL;
static char block_data[NUM_SECTORS * SECTOR_SIZE];

static int blockdev_open(struct block_device *device, fmode_t mode)
{
    return 0;
}

static void blockdev_release(struct gendisk *disk, fmode_t mode)
{
    return;
}

static struct block_device_operations blockdev_ops = {
    .owner = THIS_MODULE,
    .open = blockdev_open,
    .release = blockdev_release,
};

static void blockdev_request(struct request_queue *queue)
{
    struct request *req;
    while ((req = blk_fetch_request(queue)) != NULL) {
        if (req == NULL || (req->cmd_type != REQ_TYPE_FS)) {
            printk(KERN_INFO "skipping non-CMD request\n");
            __blk_end_request_all(req, -EIO);
            continue;
        }
        if (req->sector >= NUM_SECTORS) {
            printk(KERN_INFO "skipping out-of-bounds request\n");
            __blk_end_request_all(req, -EIO);
            continue;
        }
        switch (rq_data_dir(req)) {
            case WRITE:
                memcpy(block_data + (req->sector * SECTOR_SIZE), req->buffer, SECTOR_SIZE);
                break;
            case READ:
                memcpy(req->buffer, block_data + (req->sector * SECTOR_SIZE), SECTOR_SIZE);
                break;
            default:
                printk(KERN_INFO "unknown request data direction\n");
                __blk_end_request_all(req, -EIO);
                continue;
        }
        __blk_end_request_all(req, 0);
    }
    return;
}

static int __init blockdev_init(void)
{
    major_number = register_blkdev(0, DEVICE_NAME);
    if (major_number < 0) {
        printk(KERN_ALERT "failed to register major number\n");
        return -EBUSY;
    }
    queue = blk_init_queue(blockdev_request, NULL);
    if (queue == NULL) {
        unregister_blkdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "failed to initialize queue\n");
        return -ENOMEM;
    }
    disk = alloc_disk(1);
    if (disk == NULL) {
        blk_cleanup_queue(queue);
        unregister_blkdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "failed to allocate disk\n");
        return -ENOMEM;
    }
    strcpy(disk->disk_name, DEVICE_NAME);
    disk->major = major_number;
    disk->first_minor = 0;
    disk->fops = &blockdev_ops;
    set_capacity(disk, NUM_SECTORS);
    add_disk(disk);
    return 0;
}

static void __exit blockdev_exit(void)
{
    del_gendisk(disk);
    put_disk(disk);
    blk_cleanup_queue(queue);
    unregister_blkdev(major_number, DEVICE_NAME);
    return;
}

module_init(blockdev_init);
module_exit(blockdev_exit);

