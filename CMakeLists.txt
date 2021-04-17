cmake_minimum_required(VERSION 3.0.0)
project(culkan-v1 VERSION 0.1.0)

find_package(Vulkan REQUIRED FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
include_directories(
	external
	)

add_subdirectory(external/glfw-3.3.4)
add_subdirectory(external/glm)

add_executable(culkan-v1 main.cpp)

find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS /VulkanSDK/1.2.170.0/Lib)

target_link_libraries (culkan-v1 ${VULKAN_LIB_LIST} ${Vulkan_LIBRARY} glfw glm)


