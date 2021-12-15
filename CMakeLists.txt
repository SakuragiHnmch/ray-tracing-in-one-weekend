cmake_minimum_required(VERSION 3.17)
project(ray_tracing_in_one_weekend)

set(CMAKE_CXX_STANDARD 11)

add_executable(ray src/main.cpp)

target_include_directories(ray
            PUBLIC
                ${PROJECT_SOURCE_DIR}/include
        )