
cmake_minimum_required (VERSION 2.8)

project (CPU)

aux_source_directory(. DIR_SRCS)

add_executable(CpuOp ${DIR_SRCS})