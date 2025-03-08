# SPDX-License-Identifier: MIT License

cmake_minimum_required(VERSION 3.13.1)

zephyr_include_directories(./include)

zephyr_library_sources(src/firmware.c)
zephyr_library_sources_ifdef(CONFIG_SHELL src/gen_shell.c)
zephyr_library_sources_ifdef(CONFIG_FW_SHELL src/firmware_shell.c)

