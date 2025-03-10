# SPDX-License-Identifier: MIT License

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(ew25_firmware_test)

target_sources(app PRIVATE
                test_firmware.c
               )
