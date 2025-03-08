/*
 * SPDX-License-Identifier: MIT License
 */

#include <zephyr/kernel.h>

#include "firmware.h"

int main(void)
{
	firmware_ret_e ret = firmware_init();
	// TODO: error checking?

	while (1)
		k_sleep(K_FOREVER);

	return 0;
}
