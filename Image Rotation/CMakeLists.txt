cmake_minimum_required(VERSION 3.29)
project(Image_Rotation C)

set(CMAKE_C_STANDARD 11)
file(GLOB_RECURSE sources CONFIGURE_DEPENDS
        src/*.c
        include/*.h
)
add_executable(Image_Rotation src/main.c
        src/image.c
        include/image.h
        include/bitmap.h
        include/file.h
        src/file.c
        include/validator.h
        src/validator.c
        include/rotator.h
        src/rotator.c)
target_include_directories(Image_Rotation PRIVATE src include)
