/*
 * SPDX-License-Identifier: MIT License
 */

#include <zephyr/ztest.h>
#include "firmware.h"

extern firmware_state_e current_fw_state;

ZTEST(ew25_firmware, test_init)
{
	/* Confirm the state after init */
	firmware_ret_e ret = firmware_init();
	zassert_equal(ret, FIRMWARE_RET_SUCCESS, "Initialization should always be successful");
	zassert_equal(current_fw_state, FIRMWARE_STATE_IDLE);
	//zassert_equal(current_fw_state, FIRMWARE_STATE_ONGOING);
}

ZTEST(ew25_firmware, test_start)
{
	firmware_ret_e ret = firmware_init();
	zassert_equal(ret, FIRMWARE_RET_SUCCESS, "Initialization should always be successful");
	zassert_equal(current_fw_state, FIRMWARE_STATE_IDLE);
	/* Confirm state after starting */
	ret = firmware_start();
	zassert_equal(ret, FIRMWARE_RET_SUCCESS, "Start should not fail");
	zassert_equal(current_fw_state, FIRMWARE_STATE_ONGOING, "Should have started firmware update");
}

ZTEST(ew25_firmware, test_double_start)
{
	firmware_ret_e ret = firmware_init();
	zassert_equal(ret, FIRMWARE_RET_SUCCESS, "Initialization should always be successful");
	zassert_equal(current_fw_state, FIRMWARE_STATE_IDLE);
	ret = firmware_start();
	zassert_equal(ret, FIRMWARE_RET_SUCCESS, "Start should not fail");
	zassert_equal(current_fw_state, FIRMWARE_STATE_ONGOING, "Should have started firmware update");

	/* Confirm failure after starting twice */
	ret = firmware_start();
	zassert_not_equal(ret, FIRMWARE_RET_SUCCESS, "Start SHOULD fail");
}

ZTEST_SUITE(ew25_firmware, NULL, NULL,  NULL, NULL, NULL);
