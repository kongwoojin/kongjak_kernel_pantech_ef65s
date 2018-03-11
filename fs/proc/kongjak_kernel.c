#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <generated/compile.h>

static int kongjak_kernel_proc_show(struct seq_file *m, void *v)
{
	seq_printf(m, "%s", KONGJAK_KERNEL_VERSION);
	return 0;
}

static int kongjak_kernel_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, kongjak_kernel_proc_show, NULL);
}

static const struct file_operations kongjak_kernel_proc_fops = {
	.open		= kongjak_kernel_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_kongjak_kernel_init(void)
{
	proc_create("kongjak_kernel", 0, NULL, &kongjak_kernel_proc_fops);
	return 0;
}
module_init(proc_kongjak_kernel_init);

