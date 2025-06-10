#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    return matrix;
}

void printMatrix(int **A, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

int** augmentedMatrix(int** A,int** b){

    int row = *(&A + 1) - A;
    int col = *(&A[0] + 1) - A[0];
    col++;
    int** aug[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i != row - 2){
                aug[i][j] = A[i][j];
            }
            else{
                aug[i][j] = b[i][1];
            }
        }
    }

}

int main() {
    int row = 0;
    int col = 0;
    printf("Enter the coefficient matrix :-\n");
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);
    int **A = createMatrix(row, col);
    printMatrix(A, row, col);

    printf("Enter the RHS matrix :-\n");
    int **b = createMatrix(row, 1);
    printMatrix(b, row, 1);
    
    int **aug = augmentedMatrix(A,b);
    printMatrix(aug,row,col+1);

    for (int i = 0; i < row; i++) {
        free(A[i]);
        free(b[i]);
        free(aug[i]);
    }
    free(A);
    free(b);

    return 0;
}
