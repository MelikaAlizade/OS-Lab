#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/skbuff.h>
#include <linux/ip.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");

static struct nf_hook_ops netfilter_ops;

void log_packet(const char *data);

void log_packet(const char *data) {
    struct file *file;
    loff_t pos = 0;
    file = filp_open("../packet_log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (!IS_ERR(file)) {
        kernel_write(file, data, strlen(data), &pos);
        filp_close(file, NULL);
    } else {
        printk(KERN_ERR "%ld\n", PTR_ERR(file));
    }
}

static unsigned int packet_handler(void *priv, struct sk_buff *skb, const struct nf_hook_state *state) {
    struct iphdr *ip_header;
    char log_entry[256];
    if (!skb)
        return NF_ACCEPT;
    ip_header = ip_hdr(skb);
    if (ip_header) {
        snprintf(log_entry, sizeof(log_entry), "SRC: %pI4, DST: %pI4\n", &ip_header->saddr, &ip_header->daddr);
        log_packet(log_entry);
    }
    return NF_ACCEPT;
}

static int __init nets_init(void) {
    netfilter_ops.hook = packet_handler;
    netfilter_ops.pf = PF_INET;
    netfilter_ops.hooknum = NF_INET_PRE_ROUTING;
    netfilter_ops.priority = NF_IP_PRI_FIRST;
    nf_register_net_hook(&init_net, &netfilter_ops);
    printk(KERN_INFO "driver init\n");
    return 0;
}

module_init(nets_init);
