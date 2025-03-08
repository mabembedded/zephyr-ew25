/*
 * SPDX-License-Identifier: MIT License
 */

#pragma once

typedef enum {
	FIRMWARE_RET_SUCCESS = 0,
	FIRMWARE_RET_ERROR_INVALID_STATE,
	FIRMWARE_RET_ERROR_HARDWARE
} firmware_ret_e;

typedef enum {
	FIRMWARE_STATE_IDLE = 0,
	FIRMWARE_STATE_ONGOING,
	FIRMWARE_STATE_FAILURE,
} firmware_state_e;

firmware_ret_e firmware_init(void);
firmware_ret_e firmware_start(void);
firmware_state_e firmware_get_current_state(void);
