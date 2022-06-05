cmake_minimum_required(VERSION 3.15)
project(ciglet)

file(GLOB SOURCE_FILES *.c)
add_library(ciglet STATIC ${SOURCE_FILES})
add_definitions(-DFP_TYPE=${SWLIBS_FP_TYPE})

add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "include/ciglet")
#add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/ciglet.h" "include/ciglet/ciglet.h")
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/ciglet.h" CIGLET_HEADER_CONTENT)
file(READ "${CMAKE_CURRENT_SOURCE_DIR}/external/fastapprox-all.h" FASTAPPROX_HEADER_CONTENT)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/ciglet.h.in" "${FASTAPPROX_HEADER_CONTENT}" "\n#define CIGLET_SINGLE_FILE\n" "${CIGLET_HEADER_CONTENT}")
add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "ciglet.h.in" "include/ciglet/ciglet.h")
target_include_directories(ciglet INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
