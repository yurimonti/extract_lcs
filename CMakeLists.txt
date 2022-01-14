cmake_minimum_required(VERSION 3.20)
project(extract_lcs C)

set(CMAKE_C_STANDARD 11)

add_executable(extractlcs main.c table.c table.h extractlcs.c extractlcs.h fileman.c fileman.h)
