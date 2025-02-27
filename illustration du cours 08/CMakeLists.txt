cmake_minimum_required(VERSION 3.30)
project(illustration_du_cours_08 C)

set(CMAKE_C_STANDARD 11)

add_executable(illustration_du_cours_08 main.c
        complexes.h
        complexes.c
)

target_link_libraries(illustration_du_cours_08 m)
