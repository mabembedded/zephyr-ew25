/*
 * SPDX-License-Identifier: MIT License
 */

#include "firmware.h"

firmware_state_e current_fw_state = FIRMWARE_STATE_IDLE;

firmware_ret_e firmware_init(void)
{
	/* TODO: Error checking to determine if we're in the middle of an upgrade
	 * and set the state appropriately */
	/* For now, just restart the state machine */
	current_fw_state = FIRMWARE_STATE_IDLE;
	return FIRMWARE_RET_SUCCESS;
}

firmware_ret_e firmware_start(void)
{
	firmware_ret_e ret = FIRMWARE_RET_SUCCESS;

	switch (current_fw_state) {
		case FIRMWARE_STATE_IDLE:
			current_fw_state = FIRMWARE_STATE_ONGOING;
			break;
		case FIRMWARE_STATE_ONGOING:
			ret = FIRMWARE_RET_ERROR_INVALID_STATE;
			break;
		case FIRMWARE_STATE_FAILURE:
			ret = FIRMWARE_RET_ERROR_HARDWARE;
			break;
	}

	return ret;
}

firmware_state_e firmware_get_current_state(void)
{
	return current_fw_state;
}
