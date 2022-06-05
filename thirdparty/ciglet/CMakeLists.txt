cmake_minimum_required(VERSION 3.15)
project(ciglet)

file(GLOB SOURCE_FILES *.c)
file(GLOB SOURCE_FILES external/*.c)
add_library(ciglet STATIC ${SOURCE_FILES})
add_definitions(-DFP_TYPE=${SWLIBS_FP_TYPE})

add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "include/ciglet")
add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E rm -f "ciglet.h.in")
add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E touch "ciglet.h.in")
add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E cat "${CMAKE_CURRENT_SOURCE_DIR}/external/fastapprox-all.h" >> "ciglet.h.in")
add_custom_command(TARGET ciglet POST_BUILD COMMAND echo "\\#define CIGLET_SINGLE_FILE" >> "ciglet.h.in") # FUCK WHY?
add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E cat "${CMAKE_CURRENT_SOURCE_DIR}/ciglet.h" >> "ciglet.h.in")
add_custom_command(TARGET ciglet POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "ciglet.h.in" "include/ciglet/ciglet.h")
target_include_directories(ciglet INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
