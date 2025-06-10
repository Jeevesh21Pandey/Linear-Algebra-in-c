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

struct Matrix augmentedMatrix(struct Matrix A, struct Matrix b){

    struct Matrix aug;
    aug.rows = A.rows;
    aug.cols = A.cols + 1;
    
    aug.data = malloc(aug.rows * sizeof(float*));
    for(int i  = 0; i < aug.rows; i++){
        aug.data[i] = malloc(aug.cols * sizeof(float));
    }

    for(int i = 0; i < aug.rows; i++){
        for(int j = 0; j < aug.cols; j++){
            if(j != aug.cols - 1) aug.data[i][j] = A.data[i][j];
            else aug.data[i][j] = b.data[i][0];
        }
    }

    return aug;

}

void freeMatrix(struct Matrix* m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
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

struct Matrix solve(struct Matrix aug) {
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

    return aug;
}

int main(){

    struct Matrix A;
    int dimension, unknowns;

    printf("Enter the number of rows: ");
    scanf("%d", &dimension);
    printf("Enter the number of columns: ");
    scanf("%d", &unknowns);

    printf("Enter the  matrix:\n");
    A = createMatrix(dimension, unknowns);

    struct Matrix invA;
    invA.rows = dimension;
    invA.cols = unknowns;
    invA.data = malloc(invA.rows * sizeof(float*));
    for (int i = 0; i < invA.rows; i++) {
        invA.data[i] = malloc(invA.cols * sizeof(float));
    }
    
    for(int i = 0; i < A.rows; i++){
        
        struct Matrix e;
        e.rows = A.rows;
        e.cols = 1;
        e.data = malloc(e.rows * sizeof(float*));
        for(int k = 0; k < e.rows; k++){
            e.data[k] = malloc(sizeof(float));
        }
        for(int k = 0; k < e.rows; k++){
            if(k == i)e.data[k][0] = 1;
            else e.data[k][0] = 0; 
        }

        struct Matrix aug = augmentedMatrix(A,e);
        aug = solve(aug);
        for(int j = 0; j < aug.rows; j++){
            invA.data[j][i] = aug.data[j][aug.cols - 1];
        }
    }

    printf("The inverse matrix is:\n");
    printMatrix(&invA);

    return 0;

}
