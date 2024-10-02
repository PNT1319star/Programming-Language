//
// Created by Choi Soo Jong on 9/14/2024.
//
#include <stdint.h>
#include "image.h"

#include <stdlib.h>

struct image create_image(uint64_t w, uint64_t h) {
    return (struct image){
        .width = w, .height = h, .pixels = malloc(sizeof(struct color_pixel) * w * h)
    };
}

struct image_2d convert_to_image_2d(struct image *img) {
    struct color_pixel **array_2d = malloc(img->height * sizeof(struct color_pixel *));
    for (uint64_t i = 0; i < img->height; i++) {
        array_2d[i] = malloc(sizeof(struct color_pixel) * img->width);
    }
    return (struct image_2d){.w = img->width, .h = img->height, .pixels_2d = array_2d};
}

struct image convert_to_image_1d(struct image_2d *img) {
    struct color_pixel *array_1d = malloc(sizeof(struct color_pixel *) * img->w * img->h);
    uint64_t n = 0;
    for (uint64_t i = 0; i < img->h; i++) {
        for (uint64_t j = 0; j < img->w; j++) {
            array_1d[n++] = img->pixels_2d[i][j];
        }
    }
    return (struct image){.width = img->w, .height = img->h, .pixels = array_1d};
}

void delete_image(struct image *img) {
    free(img->pixels);
}

void delete_image_2d(struct image_2d *img) {
    for (uint64_t i = 0; i < img->h; i++) {
        free(img->pixels_2d[i]);
    }
    free(img->pixels_2d);
}
