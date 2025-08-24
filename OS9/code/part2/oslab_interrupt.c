#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/interrupt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Elina Hozhabri and Melika Alizadeh");
MODULE_DESCRIPTION("add new software interrupt");

static struct proc_dir_entry *proc_entry;

static void oslab_func(struct tasklet_struct *t) {
    printk(KERN_INFO "OSLAB SoftIRQ executed!\n");
}

DECLARE_TASKLET(oslab_tasklet, oslab_func);

static ssize_t proc_write(struct file *file, const char __user *buffer,
                          size_t count, loff_t *pos) {
    printk(KERN_INFO "trigger OSLAB softirq\n");
    tasklet_schedule(&oslab_tasklet);
    return count;
}

static const struct proc_ops proc_fops = {
    .proc_write = proc_write,
};

static int __init oslab_interrupt_init(void) {
    proc_entry = proc_create("oslab_interrupt", 0666, NULL, &proc_fops);
    if (!proc_entry) {
        printk(KERN_ALERT "failed to create OSLAB init\n");
        return -ENOMEM;
    }
    printk(KERN_INFO "OSLAB interrupt loaded\n");
    return 0;
}

static void __exit oslab_interrupt_exit(void) {
    proc_remove(proc_entry);
    tasklet_kill(&oslab_tasklet);
    printk(KERN_INFO "OSLAB interrupt unloaded\n");
}

module_init(oslab_interrupt_init);
module_exit(oslab_interrupt_exit);
