//
// Created by Choi Soo Jong on 9/15/2024.
//

#include "validator.h"

#include <stdlib.h>

const char *err_msg[] = {
    "Success!" // VALID
    "Unable to open the file!" // OPENING_ERROR
    "Unable to close the file!" // CLOSING_ERROR
    "Image can not be saved!" //SAVING_ERROR
    "Insufficient number of arguments provided!" // ARGS_ERROR
    "Rotation failed: Angle could not be parsed!" //PARSING_ERROR
    "Rotation failed: Angle must be one of [-270, -180, -90, 0, 90, 180, 270]!" //ANGLE_ERROR
    "Image loading failed: Incorrect signature!" // SIGNATURE_ERROR
    "Image loading failed: Invalid header" // HEADER_ERROR
    "Image loading failed: Invalid bit" //PIXEL_INVALID_ERROR
    "Image loading failed: Unsupported bit count" // BIT_UNSUPPORTED_ERROR
};

struct input_data process_input(char **argv) {
    FILE *f_in = fopen(argv[1], "rb");
    FILE *f_out = fopen(argv[2], "wb");

    if (f_in == NULL || f_out == NULL) {
        return (struct input_data){.stt = OPENING_ERROR};
    }

    char *endptr;
    double angle_val = strtod(argv[3], &endptr);
    if (*endptr != '\0' || angle_val > 1e9 || angle_val < -1e9) {
        return (struct input_data){.stt = PARSING_ERROR};
    }

    double rotation_angle = -((double) angle_val);
    if (rotation_angle < 0) rotation_angle += 360;

        return (struct input_data){
            .stt = VALID,
            .angle = (uint64_t) rotation_angle % 360 + (rotation_angle - (uint64_t) rotation_angle),
            .in = f_in,
            .out = f_out,
        };
}

enum input_stt process_error(enum input_stt stt) {
    printf("%s", err_msg[stt]);
    return stt;
}

enum input_stt close_file(FILE* f) {
    if (fclose(f) != 0) {
        return process_error(CLOSING_ERROR);
    }
    return VALID;
}
