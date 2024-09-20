//
// Created by Choi Soo Jong on 9/15/2024.
//
#include "image.h"
#include "rotator.h"
struct image rotate_image_by_90(struct image* in_img) {
    struct image rotated_img = create_image(in_img -> width, in_img ->height);

    for (uint32_t y = 0; y <= in_img -> height; y++) {
        for (uint32_t x = 0; x <= in_img -> width; x++ ) {
            rotated_img.pixels[x * rotated_img .width + rotated_img.height - y - 1] = in_img->pixels[ y * in_img -> width + x];
        }
    }

    delete_image(in_img);
    return rotated_img;
}

struct image rotate_image_by_angle(struct image* in_img, int32_t angle) {
    uint16_t rotations = angle / 90;
    if (angle == 0) rotations = 4;

    struct image rotated_img = *in_img;
    for(uint16_t i = 0; i< rotations; ++i) {
        rotated_img = rotate_image_by_90(&rotated_img);
    }
    return rotated_img;
}
