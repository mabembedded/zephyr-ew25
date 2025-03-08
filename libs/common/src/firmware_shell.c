/*
 * SPDX-License-Identifier: MIT License
 */

#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>
#include <sys/errno.h>

#include "firmware.h"

static int cmd_fw_start(const struct shell *sh, size_t argc, char **argv)
{
	firmware_ret_e ret = firmware_start();
	int ret_n = 0;
	if (ret == FIRMWARE_RET_SUCCESS) {
		shell_print(sh, "Successfully started firmware update");
		ret_n = 0;
	} else {
		shell_print(sh, "Failed to start firmware update (%u)", ret);
		ret_n = -1;
	}

	return -1;
}

static int cmd_fw_state(const struct shell *sh, size_t argc, char **argv)
{
	firmware_state_e state = firmware_get_current_state();
	switch (state) {
		case FIRMWARE_STATE_IDLE:
			shell_print(sh, "State: Idle");
			break;
		case FIRMWARE_STATE_ONGOING:
			shell_print(sh, "State: Ongoing");
			break;
		case FIRMWARE_STATE_FAILURE:
			shell_print(sh, "State: Failure");
			break;

	}

	return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(ew25_fw_cmds,
		SHELL_CMD_ARG(start, NULL,
			"ew25 fw start",
			cmd_fw_start, 1, 0),
		SHELL_CMD_ARG(status, NULL,
			"ew25 fw status",
			cmd_fw_state, 1, 0),
		SHELL_SUBCMD_SET_END
);

SHELL_SUBCMD_ADD((ew25), fw, &ew25_fw_cmds,
		"EW25 FW commands",
		NULL, 1, 0);
