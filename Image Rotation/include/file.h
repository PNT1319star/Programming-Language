//
// Created by Choi Soo Jong on 9/14/2024.
//

#ifndef FILE_H
#define FILE_H
#include<stdio.h>
#include "image.h"

//Enum for input status
enum in_stt {
    IN_SUCCESS = 0,
    BMP_SIGN_INVALID,
    PIXEL_INVALID,
    HEADER_INVALID,
    BIT_UNSUPPORTED
};

// Enum for output status
enum out_stt {
    OUT_SUCCESS = 0 ,
    OUT_FAILURE
};

//Function to convert a bitmap format to an image
enum in_stt convert_bmp_to_image(FILE* input, struct image* image);

//Function to convert an image to a bitmap
enum out_stt convert_image_to_bmp(FILE* output, struct image const* image);
#endif //FILE_H
