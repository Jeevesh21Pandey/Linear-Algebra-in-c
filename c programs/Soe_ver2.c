#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    struct Matrix* next;
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

struct Matrix createMatrix(int row, int col){
    
    struct Matrix A;
    A.rows = row;
    A.cols = col;
    A.data = malloc(A.rows * sizeof(float*));
    for (int i = 0; i < A.rows; i++) {
        A.data[i] = malloc(A.cols * sizeof(float));
    }
    
    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            printf("Enter the [%d][%d] value: ",i+1,j+1);
            scanf("%f", &A.data[i][j]);
        }
    }

    printMatrix(&A);
    return A;
}
/*
struct Matrix augmentedMatrix(struct Matrix A, struct Matrix b){
    
    struct Matrix aug;
    aug.rows = A.rows;
    aug.cols = b.cols + 1;
    
    aug.data = malloc(aug.rows * sizeof(float*));
    for(int i = 0; i < aug.rows; i++){
        aug.data[i] = malloc(aug.cols * sizeof(float*));
    }

    for(int i = 0; i < aug.rows; i++){
        for(int j = 0; j < aug.cols; j++){
            if(j == aug.cols){
                aug.data[i][j] = b.data[i][0];
            }
            else{
                aug.data[i][j] = A.data[i][j];
            }
        }
    }
    
    printf("The augmented matrix obtained is:\n");
    printMatrix(&aug);
    return aug;

}
*/

int first_nonzero_element(int arr[]) {
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            return arr[i]; 
        }
    } 
    return 0; 
}

int first_nonzero_index(int arr[]){
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) { 
            return i; 
        }
    } 
    return 0;
}

void solve(struct Matrix aug){
    
    int row = aug.rows;
    int col = aug.cols;

    //struct Matrix m = aug;
    for(int i = 0; i < row; i++){
        int index;
        int x = first_nonzero_element(&aug.data[i]);

        for(int j = 0; j < col; j++){
            aug.data[i][j] = aug.data[i][j]/x;
        }
        
        for(int k = 0; k < row; k++){
            for(int l = 0; l < col; l++){
                if(k == i){

                }
                aug.data[k][l] = aug.data[k][l] - (aug.data[k][first_nonzero_index(aug.data[i])] * aug.data[i][l]);
            }
        }
    }
    
    printMatrix(&aug);
}

int main() {
    struct Matrix A;
    int dimension;
    int unknowns = 0;

    printf("Enter the number of equations present: ");
    scanf("%d",&dimension);
    printf("Enter the number of unknowns: ");
    scanf("%d",&unknowns);
    
    printf("Enter the augmented matrix:\n");
    A = createMatrix(dimension,unknowns + 1);
    
    //printf("Enter the RHS matrix:\n");
    //struct Matrix b;    
    //b = createMatrix(dimension,1);

    //struct Matrix aug;
    //aug = augmentedMatrix(A,b);
    
    solve(A);
    return 0;
}
