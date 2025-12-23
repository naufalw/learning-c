#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Naufal");
MODULE_DESCRIPTION("henlo");
MODULE_VERSION("1.0");

static int __init hello_init(void) {
  printk(KERN_INFO "Hello kernal\n");
  return 0;
}

static void __exit hello_exit(void) { printk(KERN_INFO "Goodbye kernal\n"); }

module_init(hello_init);
module_exit(hello_exit);