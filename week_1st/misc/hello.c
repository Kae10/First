#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <asm/uaccess.h>

static ssize_t read_hello(struct file* file, char* buf, size_t count, loff_t *ppos)
{
	char* hello_str = "Hello, World!\n";
	int len = strlen(hello_str);

	if (count < len)
		return -EINVAL;

	if (*ppos != 0)
		return 0;

	if (copy_to_user(buf, hello_str, len))
		return -EINVAL;

	*ppos = len;

	return len;
}

static const struct file_operations fops_hello = {
	.owner		= THIS_MODULE,
	.read		= read_hello,
};

static struct miscdevice dev_hello = {
	MISC_DYNAMIC_MINOR,
	"hello",
	&fops_hello
};

int __init init_hello(void)
{
	int ret;

	ret = misc_register(&dev_hello);

	if (ret)
		printk(KERN_ALERT "[Module Message] Unable to register.\n");

	return ret;
}

void __exit exit_hello(void)
{
	misc_deregister(&dev_hello);
	printk(KERN_ALERT "[Module Message] Deregister Complete.\n");
}

module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
