/*
 * SPDX-License-Identifier: MIT License
 */

#include <zephyr/shell/shell.h>

SHELL_SUBCMD_SET_CREATE(ew25_commands, (ew25));
SHELL_CMD_ARG_REGISTER(ew25, &ew25_commands, "EW25 Commmands", NULL, 1, 0);
