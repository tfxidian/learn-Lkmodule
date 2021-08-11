
#include<linux/kernel.h>
#include<linux/module.h>

void cleanup_module(){
	pr_info("this is the end part.\n");
}


MODULE_LICENSE("GPL");
