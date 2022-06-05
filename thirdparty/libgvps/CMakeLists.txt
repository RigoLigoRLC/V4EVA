cmake_minimum_required(VERSION 3.15)
project(gvps)

file(GLOB_RECURSE SOURCE_FILES *.c)
add_library(gvps STATIC ${SOURCE_FILES})
add_definitions(-DFP_TYPE=${SWLIBS_FP_TYPE})

add_custom_command(TARGET gvps POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "include/libgvps")
add_custom_command(TARGET gvps POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/gvps.h" "include/libgvps/gvps.h")
target_include_directories(gvps INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
