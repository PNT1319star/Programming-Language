//
// Created by Choi Soo Jong on 9/14/2024.
//
#include<stdio.h>
#include<stdlib.h>
#include "file.h"
#include "bitmap.h"

#define BMP_HEADER 0x4D42
#define BMP_HEADER_SIZE 40
#define BMP_RESERVED 0
#define BMP_PLANES 1
#define BMP_BIT_DEPTH 24
#define BMP_COMPRESSED 0
#define BMP_DPI 2835
#define BMP_USED_COLORS 0
#define BMP_IMP_COLORS 0

// Calculate the padding's size
static inline uint32_t calculate_padding_size(const struct image *image) {
    return (4 - ((image->width * sizeof(struct color_pixel)) % 4)) % 4;
}

// Read image from file
enum in_stt convert_bmp_to_image(FILE *input, struct image *image) {
    struct bitmap_file_header *bfh;

    if (bfh->fType != BMP_HEADER) return BMP_SIGN_INVALID;
    if (bfh->bitPerPx != BMP_BIT_DEPTH) return BIT_UNSUPPORTED;
    if (fread(&bfh, sizeof(struct bitmap_file_header), 1, input) != 1) return HEADER_INVALID;

    *image = create_image(bfh->imgWidth, bfh->imgHeight);
    uint32_t padding_size = calculate_padding_size(image);

    if (!(image->pixels)) return PIXEL_INVALID;
    for (uint32_t row = 0; row < bfh->imgHeight; row++) {
        fread(&(*image).pixels[row * bfh->imgWidth], sizeof(struct color_pixel), bfh->imgWidth, input);
        fseek(input, (long) padding_size, SEEK_CUR);
    }
    return IN_SUCCESS;
}

//Write image to file
enum out_stt convert_image_to_bmp(FILE *output, const struct image *img) {
    uint32_t padding_size = calculate_padding_size(img);
    uint32_t row_size = img->width * sizeof(struct color_pixel) + padding_size;

    struct bitmap_file_header header = {
        .fType = BMP_HEADER,
        .fSize = sizeof(struct bitmap_file_header) + row_size * img->height,
        .fReserved = BMP_RESERVED,
        .fOffBits = sizeof(struct bitmap_file_header),
        .hSize = BMP_HEADER_SIZE,
        .imgWidth = img->width,
        .imgHeight = img->height,
        .colorPlanes = BMP_PLANES,
        .bitPerPx = BMP_BIT_DEPTH,
        .compressed = BMP_COMPRESSED,
        .imgSize = row_size * img->height,
        .xRes = BMP_DPI,
        .yRes = BMP_DPI,
        .nColors = BMP_USED_COLORS,
        .impColors = BMP_IMP_COLORS
    };
    if (fwrite(&header, sizeof(struct bitmap_file_header), 1, output) != 1) {
        return OUT_FAILURE;
    }

    for (uint32_t row = 0; row < img->height; row++) {
        if (fwrite(&img->pixels[img->width * row], sizeof(struct color_pixel), img->width, output) != img->width) {
            return OUT_FAILURE;
        }
        fseek(output, padding_size, SEEK_CUR);
    }
    return OUT_SUCCESS;
}
