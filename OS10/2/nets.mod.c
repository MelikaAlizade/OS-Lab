#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd763ba23, "nf_register_net_hook" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xc8006703, "filp_open" },
	{ 0x43a349ca, "strlen" },
	{ 0xbf2f841f, "kernel_write" },
	{ 0x79a9dee7, "filp_close" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0x40a621c5, "snprintf" },
	{ 0xd272d446, "__fentry__" },
	{ 0x6a9bd73f, "init_net" },
	{ 0xab006604, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd763ba23,
	0xe8213e80,
	0xd272d446,
	0xc8006703,
	0x43a349ca,
	0xbf2f841f,
	0x79a9dee7,
	0xd272d446,
	0x40a621c5,
	0xd272d446,
	0x6a9bd73f,
	0xab006604,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"nf_register_net_hook\0"
	"_printk\0"
	"__x86_return_thunk\0"
	"filp_open\0"
	"strlen\0"
	"kernel_write\0"
	"filp_close\0"
	"__stack_chk_fail\0"
	"snprintf\0"
	"__fentry__\0"
	"init_net\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "2B1A583A0ECDC6CC4635464");
