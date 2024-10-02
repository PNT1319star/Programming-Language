//
// Created by Choi Soo Jong on 9/15/2024.
//
#include "image.h"
#include "rotator.h"
#include "matrix_converter.h"

#include <math.h>

struct image rotate_image_by_90(struct image *in_img) {
    struct image rotated_img = create_image(in_img->width, in_img->height);

    for (uint32_t y = 0; y <= in_img->height; y++) {
        for (uint32_t x = 0; x <= in_img->width; x++) {
            rotated_img.pixels[x * rotated_img.width + rotated_img.height - y - 1] = in_img->pixels[
                y * in_img->width + x];
        }
    }

    delete_image(in_img);
    return rotated_img;
}

// struct image rotate_image_by_angle(struct image* in_img, int32_t angle) {
//     uint16_t rotations = angle / 90;
//     if (angle == 0) rotations = 4;
//
//     struct image rotated_img = *in_img;
//     for(uint16_t i = 0; i< rotations; ++i) {
//         rotated_img = rotate_image_by_90(&rotated_img);
//     }
//     return rotated_img;
// }

double convert_from_matrix_to_Oxy(uint64_t coord, uint64_t center) {
    return (coord + 1 - center) - 0.5;
}

uint64_t convert_from_Oxy_to_matrix(double coord, uint64_t center) {
    return (uint64_t) ceil(coord + center - 1);
}

struct pair rotate_image_on_Oxy(double oldX, double oldY, double angle) {
    double rad = angle * M_PI / 180;
    double newX = cos(rad) * oldX - sin(rad) * oldY;
    double newY = sin(rad) * oldX + cos(rad) * oldY;
    return (struct pair){.x = newX, .y = newY};
}

struct image_2d rotate_image_by_angle(struct image_2d *in_img, double angle) {
    uint64_t width = ceil(sqrt(pow(in_img->w, 2) + pow(in_img->h, 2)));
    uint64_t center = width / 2;
    struct image result_1d = create_image(width, width);
    struct image_2d result_2d = convert_to_image_2d(&result_1d);

    for (uint64_t i = 0; i < in_img-> h; i++) {
        for (uint64_t j = 0; j < in_img->w; j++) {
            double x = convert_from_matrix_to_Oxy(j, center);
            double y = convert_from_matrix_to_Oxy(i, center);
            struct pair new_coord = rotate_image_on_Oxy(x, y, angle);
            uint64_t newX = convert_from_Oxy_to_matrix(new_coord.x, center);
            uint64_t newY = convert_from_Oxy_to_matrix(new_coord.y, center);
            result_2d.pixels_2d[newX][newY] = in_img -> pixels_2d[i][j];
        }
    }
    return result_2d;
}
