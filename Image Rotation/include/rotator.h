//
// Created by Choi Soo Jong on 9/15/2024.
//

#ifndef ROTATOR_H
#define ROTATOR_H

#include "image.h"

struct image rotate_image_by_90(struct image* in_img);
struct image rotate_image_by_angle(struct image* in_image, int32_t rotation_angle);
#endif //ROTATOR_H
