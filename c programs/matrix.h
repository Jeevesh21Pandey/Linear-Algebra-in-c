#ifndef MATRIX_H
#define MATRIX_H
#endif

#include <stdio.h>
#include <stdlib.h>

struct Matrix{

    int rows;
    int cols;
    float **data;
};

struct Matrix createMatrix(int row, int col);
void printMatrix(struct Matrix* m);
void solve(struct Matrix aug);
int first_nonzero_element(float arr[], int size);
int first_nonzero_index(float arr[], int size);
void freeMatrix(struct Matrix* m);