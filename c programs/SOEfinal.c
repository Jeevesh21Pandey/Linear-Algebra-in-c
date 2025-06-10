#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    float** data;
};

void printMatrix(struct Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
}

struct Matrix createMatrix(int row, int col) {
    struct Matrix A;
    A.rows = row;
    A.cols = col;
    A.data = malloc(A.rows * sizeof(float*));
    for (int i = 0; i < A.rows; i++) {
        A.data[i] = malloc(A.cols * sizeof(float));
    }

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            printf("Enter the [%d][%d] value: ", i + 1, j + 1);
            scanf("%f", &A.data[i][j]);
        }
    }

    printMatrix(&A);
    return A;
}

int first_nonzero_element(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            return arr[i];
        }
    }
    return 0;
}

int first_nonzero_index(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            return i;
        }
    }
    return -1;
}

struct Matrix  solve(struct Matrix aug) {

    int row = aug.rows;
    int col = aug.cols;

    for (int i = 0; i < row; i++) {

        int pivot_index = first_nonzero_index(aug.data[i], col);
        if (pivot_index == -1) {
            continue;
        }

        float pivot = aug.data[i][pivot_index];
        for (int j = 0; j < col; j++) {
            aug.data[i][j] /= pivot;
        }

        for (int k = 0; k < row; k++) {
            if (k == i) continue;
            float factor = aug.data[k][pivot_index];
            for (int l = 0; l < col; l++) {
                aug.data[k][l] -= factor * aug.data[i][l];
            }
        }
    }
    printf("The matrix after Gaussian elimination is:\n");
    printMatrix(&aug);

    return aug;

}

void infsol(struct Matrix m){//logical inconsistency

    int row = m.rows;
    int col = m.cols;

    for(int i = 0; i<row; i++){
        int flag = 1;
        for(int j = 0; j<col; j++){
            if(m.data[i][j] != 0) {
                flag = 0;
            }
            else continue;
        }
    }

    //if(flag == 1) 
    //else printf("No infinitely many solution");

}

void freeMatrix(struct Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

int main() {
    struct Matrix A;
    int dimension;
    int unknowns = 0;

    printf("Enter the number of equations present: ");
    scanf("%d", &dimension);
    printf("Enter the number of unknowns: ");
    scanf("%d", &unknowns);

    printf("Enter the augmented matrix:\n");
    A = createMatrix(dimension, unknowns + 1);

    struct Matrix aug = solve(A);
    infsol(aug);

    freeMatrix(&A);

    return 0;
}
