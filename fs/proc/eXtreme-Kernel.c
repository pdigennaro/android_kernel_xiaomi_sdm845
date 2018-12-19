#include <linux/fs.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <generated/compile.h>

static int eXtreme_kernel_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "{\"kernel-name\": \"eXtreme-Kernel\","
			"\"version\": \"7.0\","
			"\"buildtime\": \"%s\"}\n", eXtreme_KERNEL_TIMESTAMP);
	return 0;
}

static int eXtreme_kernel_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, eXtreme_kernel_proc_show, NULL);
}

static const struct file_operations eXtreme_kernel_proc_fops = {
	.open		= eXtreme_kernel_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_eXtreme_kernel_init(void)
{
	proc_create("eXtreme-Kernel", 0, NULL, &eXtreme_kernel_proc_fops);
	return 0;
}
module_init(proc_eXtreme_kernel_init);
