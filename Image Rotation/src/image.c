//
// Created by Choi Soo Jong on 9/14/2024.
//
#include <stdint.h>
#include "image.h"

#include <stdlib.h>

struct image create_image(uint64_t w, uint64_t h) {
    return (struct image) {
        .width = w, .height = h, .pixels = malloc(sizeof(struct color_pixel) * w * h)
    };
}

void delete_image(struct image* img) {
    free(img->pixels);
}
