//
// Created by Choi Soo Jong on 10/2/2024.
//

#ifndef MATRIX_CONVERTER_H
#define MATRIX_CONVERTER_H

struct pair {
    double x, y;
};

double convert_from_matrix_to_Oxy(uint64_t coord, uint64_t center);
uint64_t convert_from_Oxy_to_matrix(uint64_t coord, uint64_t center);
#endif //MATRIX_CONVERTER_H
