
#include<linux/kernel.h>
#include<linux/module.h>

int init_module(void){
	pr_info("hello, this is starting part.\n");
	return 0;
}

MODULE_LICENSE("GPL");
