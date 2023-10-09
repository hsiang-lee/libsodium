cmake_minimum_required(VERSION 3.20)
project(sodium)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-fPIC)

# 控制符号的可见性
set(CMAKE_C_FLAGS_RELEASE     "${CMAKE_C_FLAGS_RELEASE}   -fvisibility=hidden")
set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -fvisibility=hidden")
set(CMAKE_C_FLAGS_RELEASE     "${CMAKE_C_FLAGS_RELEASE}   -fvisibility-inlines-hidden")
set(CMAKE_CXX_FLAGS_RELEASE   "${CMAKE_CXX_FLAGS_RELEASE} -fvisibility-inlines-hidden")

# 使用gc-section优化
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    -Wl,--gc-sections")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -Wl,--gc-sections")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--gc-sections")


file(GLOB_RECURSE Source ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_library(sodium STATIC ${Source})
target_include_directories(sodium PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include/sodium)
