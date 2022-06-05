cmake_minimum_required(VERSION 3.15)
project(llsm2)

file(GLOB SOURCE_FILES *.c)
add_library(llsm2 STATIC ${SOURCE_FILES})
add_definitions(-DFP_TYPE=${SWLIBS_FP_TYPE})
target_link_libraries(llsm2 ciglet)

add_custom_command(TARGET llsm2 POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory "include/libllsm2")
file(GLOB SRC_HEADERS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" *.h)
foreach(SRC_HEADER ${SRC_HEADERS})
    add_custom_command(TARGET llsm2 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_HEADER}" "include/libllsm2/${SRC_HEADER}")
endforeach()
target_include_directories(llsm2 INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/include")
