# 项目信息
project(algorithms)
cmake_minimum_required(VERSION 2.6)

# 增加cunit头文件所在目录
include_directories(/usr/local/include)

# 增加cunit链接库所在目录
link_directories(/usr/local/lib)

# 用于构建静态链接库的源码的所在目录
aux_source_directory(./chap02 DIR_SRCS)
aux_source_directory(./chap04 DIR_SRCS)
aux_source_directory(./chap06 DIR_SRCS)
aux_source_directory(./chap07 DIR_SRCS)
aux_source_directory(./chap08 DIR_SRCS)
aux_source_directory(./chap09 DIR_SRCS)
aux_source_directory(./chap15 DIR_SRCS)
add_library(algo ${DIR_SRCS})

# 定义可执行目标
add_executable(algorithms main.c utils.c)
add_executable(test_algorithms test_main.c utils.c)

# 可执行目标需要链接的库
target_link_libraries(algorithms algo)
target_link_libraries(test_algorithms algo cunit)

