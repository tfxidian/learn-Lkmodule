
#include<linux/kernel.h>
#include<linux/module.h>

int init_module(void){
	pr_info("hello module.\n");
	return 0;
}

void cleanup_module(void){
	pr_info("hello end.\n");
}


