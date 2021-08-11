
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

static int __init hello2_init(void){
	pr_info("hello2 .\n");
	return 0;
}

static void __exit hello2_exit(void){

	pr_info("hello2 bye.\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

MODULE_LICENSE("GPL");
