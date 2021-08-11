#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/stat.h>
#include<linux/moduleparam.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("FTANG");

static int myint = 100;


module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
static int __init hello_param_init(void){
	pr_info("hello param.\n");
	pr_info("myint value is : %d", myint);
	return 0;
}

static void __exit hello_param_exit(void){
	pr_info("param exit.\n");
}


module_init(hello_param_init);
module_exit(hello_param_exit);
