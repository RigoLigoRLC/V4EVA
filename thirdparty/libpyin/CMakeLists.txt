cmake_minimum_required(VERSION 3.15)
project(libpyin)

file(GLOB SOURCE_FILES *.c)
add_library(pyin STATIC ${SOURCE_FILES})
add_definitions(-DFP_TYPE=${SWLIBS_FP_TYPE})
target_link_libraries(pyin gvps)

add_custom_command(TARGET pyin POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "include")
add_custom_command(TARGET pyin POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/pyin.h" "include/pyin.h")
target_include_directories(pyin INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
