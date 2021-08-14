
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
#include<asm/errno.h>
#define DEVICE_NAME "chardev"
#define BUF_LEN 80
#define MODULE
#define LINUX
#define __KERNEL__

int init_module(void);
void cleanup_module(void);

static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);

static ssize_t device_read(struct file*, char*, size_t, loff_t*);
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);

static int Major;
static int Device_Open = 0;

static char msg[BUF_LEN];
static char *msg_Ptr;

static struct file_operations fops ={
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release,
};

int init_module(void)
{
	Major = register_chrdev(0, DEVICE_NAME, &fops);
	if(Major < 0){
		printk("Registering the character device failed with %d", Major);
	}

	printk("<1> I was assigned major number %d.\n", Major);


}


void cleanup_module(void)
{
	pr_info("this is cleanup in chardev.\n");
	unregister_chrdev(Major, DEVICE_NAME);
	//if(ret<0) printk("Error in unregister chardev. %d", ret);
	}

static int device_open(struct inode *inode, struct file *file)
{
	static int counter = 0;
	if(Device_Open) return -EBUSY;

	Device_Open++;
	sprintf(msg,"I already told you %d times hello\n", Device_Open);
	msg_Ptr = msg;
	return 0;
}

static int device_release(struct inode *inode, struct file*file){

	Device_Open --;
//	MOD_DEC_USE_COUNT;
	return 0;
}

static ssize_t device_read(struct file* filep, char* buffer, size_t length, loff_t* offset)
{
	if(*msg_Ptr ==0) return 0;
	int bytes_read = 0;
	while(length && *msg_Ptr){
		put_user(*(msg_Ptr++), buffer++);
		length--;
		bytes_read++;
	}
	return bytes_read;
}


static ssize_t device_write(struct file *filep, const char *buffer, size_t len, loff_t *off)
{
	printk("sorry this operation is not supported now.\n");
	return -EINVAL;
}


MODULE_LICENSE("GPL");
