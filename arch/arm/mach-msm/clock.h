/* arch/arm/mach-msm/clock.h
 *
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2007-2012, Code Aurora Forum. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __ARCH_ARM_MACH_MSM_CLOCK_H
#define __ARCH_ARM_MACH_MSM_CLOCK_H

#include <linux/clkdev.h>

struct clock_init_data {
	struct clk_lookup *table;
	size_t size;
	void (*pre_init)(void);
	void (*post_init)(void);
	int (*late_init)(void);
};

extern struct list_head clk_enable_list;
extern spinlock_t clk_enable_list_lock;
extern int is_xo_src(struct clk *);
extern void clk_ignor_list_add(const char *dev_id, const char *con_id, struct clock_init_data *msm_clock_init_data);

extern struct clock_init_data msm9615_clock_init_data;
extern struct clock_init_data apq8064_clock_init_data;
extern struct clock_init_data apq8064_clock_init_data_r2;

extern struct clock_init_data fsm9xxx_clock_init_data;
extern struct clock_init_data msm7x01a_clock_init_data;
extern struct clock_init_data msm7x27_clock_init_data;
extern struct clock_init_data msm7x27a_clock_init_data;
extern struct clock_init_data msm7x30_clock_init_data;
extern struct clock_init_data msm8960_clock_init_data;
extern struct clock_init_data msm8x60_clock_init_data;
extern struct clock_init_data qds8x50_clock_init_data;
extern struct clock_init_data msm8625_dummy_clock_init_data;
extern struct clock_init_data msm8930_clock_init_data;
extern struct clock_init_data msm8974_clock_init_data;

int msm_clock_init(struct clock_init_data *data);
void keep_dig_voltage_low_in_idle(bool on);
int find_vdd_level(struct clk *clk, unsigned long rate);

#ifdef CONFIG_DEBUG_FS
int clock_debug_init(void);
int clock_debug_register(struct clk_lookup *t, size_t s);
void clock_debug_print_enabled(void);
#else
static inline int clock_debug_add(struct clk *clock) { return 0; }
static inline int clock_debug_init(void) { return 0; }
static inline int clock_debug_register(struct clk_lookup *t, size_t s)
{
	return 0;
}
static inline void clock_debug_print_enabled(void) { return; }
#endif

#endif

