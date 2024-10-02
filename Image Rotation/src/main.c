#include <stdio.h>
#include "image.h"
#include "file.h"
#include "rotator.h"
#include "validator.h"


enum input_stt read(FILE* in, struct image* img) {
    enum in_stt rs = convert_bmp_to_image(in, img);

    if (rs != IN_SUCCESS) {
        enum input_stt stt_to_msg[] = {
            VALID, SIGNATURE_ERROR, PIXEL_INVALID_ERROR, HEADER_ERROR, BIT_UNSUPPORTED_ERROR
        };
        return process_error(stt_to_msg[rs]);
    }
    return close_file(in);
}

enum input_stt write(FILE* out,const struct image* img) {
    enum out_stt ws = convert_image_to_bmp(out, img);
    if (ws != OUT_SUCCESS) {
        close_file(out);
        return process_error(SAVING_ERROR);
    }
    return close_file(out);
}

int main(int argc, char** argv) {
    if (argc < 4) return process_error(ARGS_ERROR);

    struct input_data input = process_input(argv);
    printf(&input);
    if(input.stt != 0) {
        return process_error(input.stt);
    }

    struct image image;
    enum input_stt rs = read(input.in, &image);
    if (rs != IN_SUCCESS) return rs;

    struct image_2d image_2d = convert_to_image_2d(&image);
    struct image_2d new_img = rotate_image_by_angle(&image_2d, input.angle);
    struct image result = convert_to_image_1d(&new_img);

    enum input_stt ws = write(input.out, &result);
    if(ws == OUT_SUCCESS)   printf("Success\n");
    printf("Failed");

    delete_image_2d(&image_2d);
    delete_image_2d(&new_img);
    delete_image(&result);
    return ws;

}
