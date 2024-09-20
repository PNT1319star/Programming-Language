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
    struct color_pixel* pixels;
};

struct image create_image(uint64_t w, uint64_t h);
void delete_image(struct image* img);
#endif //IMAGE_H
