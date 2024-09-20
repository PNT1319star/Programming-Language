//
// Created by Choi Soo Jong on 9/14/2024.
//

#ifndef BITMAP_H
#define BITMAP_H
#include<stdint.h>

struct __attribute__((packed)) bitmap_file_header {
    uint16_t fType;
    uint32_t fSize;
    uint32_t fReserved; //Unused memory
    uint32_t fOffBits;
    uint32_t hSize;
    uint32_t imgWidth;
    uint32_t imgHeight;
    uint16_t colorPlanes;
    uint16_t bitPerPx;
    uint32_t compressed;
    uint32_t imgSize;
    uint32_t xRes;
    uint32_t yRes;
    uint32_t nColors;
    uint32_t impColors;
};
#endif
