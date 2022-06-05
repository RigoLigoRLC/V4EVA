cmake_minimum_required(VERSION 3.15)
project(V4EVA)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Executable V4EVA
add_executable(V4EVA ${SOURCE_FILES})

# Dependencies
# Libraries from Sleepwalking has a FP_TYPE macro that we need to define here
set(SWLIBS_FP_TYPE float)
add_subdirectory(thirdparty/libgvps)
add_subdirectory(thirdparty/libpyin)
add_subdirectory(thirdparty/ciglet)
add_subdirectory(thirdparty/libllsm2)

add_definitions(-DFP_TYPE=${SWLIBS_FP_TYPE})
target_link_libraries(V4EVA pyin llsm2)


