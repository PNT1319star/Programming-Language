//
// Created by Choi Soo Jong on 9/14/2024.
//

#ifndef IMAGE_H
#define IMAGE_H

#include<stdint.h>

struct __attribute__((packed)) color_pixel {
    uint8_t blue, green, red;
};

struct image {
    uint64_t width, height;
    struct color_pixel *pixels;
};

struct image_2d {
    uint64_t w, h;
    struct color_pixel** pixels_2d;
};

struct image create_image(uint64_t w, uint64_t h);
struct image_2d convert_to_image_2d(struct image* img);
struct image convert_to_image_1d(struct image_2d* img);

void delete_image(struct image *img);
void delete_image_2d(struct image_2d *img);
#endif //IMAGE_H
