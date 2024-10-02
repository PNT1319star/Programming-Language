//
// Created by Choi Soo Jong on 9/15/2024.
//

#ifndef ROTATOR_H
#define ROTATOR_H

#include "image.h"
#include "matrix_converter.h"


struct image rotate_image_by_90(struct image* in_img);
struct image_2d rotate_image_by_angle(struct image_2d* in_image, double rotation_angle);
struct pair rotate_image_on_Oxy(double oldX, double oldY, double angle);
#endif //ROTATOR_H
