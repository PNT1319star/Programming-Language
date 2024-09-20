//
// Created by Choi Soo Jong on 9/15/2024.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include<stdio.h>
#include<stdint.h>

enum input_stt {
    VALID = 0,
    OPENING_ERROR,
    CLOSING_ERROR,
    SAVING_ERROR,
    ARGS_ERROR,
    PARSING_ERROR,
    ANGLE_ERROR,
    SIGNATURE_ERROR,
    HEADER_ERROR,
    PIXEL_INVALID_ERROR,
    BIT_UNSUPPORTED_ERROR
};

struct input_data {
  enum input_stt stt;
    int32_t angle;
    FILE* in;
    FILE* out;
};

struct input_data process_input(char** argv);
enum input_stt process_error(enum input_stt stt);
enum input_stt close_file(FILE* f);

#endif //VALIDATOR_H
