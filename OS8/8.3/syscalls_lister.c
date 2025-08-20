#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>
#include <linux/unistd.h>

MODULE_LICENSE("GPL");

static unsigned long (*kallsyms_lookup_name_fn)(const char *name);
static struct kprobe kp = { .symbol_name = "kallsyms_lookup_name" };
static unsigned long *syscall_table;
static size_t num_syscalls;

static size_t detect_syscall_count(void)
{
#if defined(NR_syscalls)
    return NR_syscalls;
#elif defined(__NR_syscalls)
    return __NR_syscalls;
#else
    return 512;
#endif
}

static int __init syslist_init(void)
{
    int i;
    num_syscalls = detect_syscall_count();

    register_kprobe(&kp);
    kallsyms_lookup_name_fn = (void *)kp.addr;
    unregister_kprobe(&kp);

    syscall_table = (unsigned long *)kallsyms_lookup_name_fn("sys_call_table");

    for (i = 0; i < num_syscalls; i++)
        if (syscall_table[i])
            printk("syscalls_lister: syscall[%d] = %px (%pS)\n",
                   i, (void *)syscall_table[i], (void *)syscall_table[i]);

    return 0;
}

static void __exit syslist_exit(void)
{
    printk("syscalls_lister: module unloaded.\n");
}

module_init(syslist_init);
module_exit(syslist_exit);
