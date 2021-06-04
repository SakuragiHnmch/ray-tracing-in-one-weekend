cmake_minimum_required(VERSION 3.17)
project(ray_tracing_in_one_weekend)

set(CMAKE_CXX_STANDARD 11)

add_executable(ray_tracing_in_one_weekend src/main.cpp include/hittable.h include/sphere.h include/hittable_list.h include/rtweekend.h include/camera.h include/material.h)

target_include_directories(ray_tracing_in_one_weekend
            PUBLIC
                ${PROJECT_SOURCE_DIR}/include
        )