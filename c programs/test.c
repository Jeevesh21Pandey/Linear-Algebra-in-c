#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

float findMinimum(float arr[], int size) {
    if (size <= 0) {
        // Handle empty array case (return maximum possible integer or any other suitable error value)
        return LONG_MAX; // Or you could return an error code, or exit.
    }

    float min = arr[0]; // Initialize min with the first element

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i]; // Update min if a smaller element is found
        }
    }

    return min;
}

int main(){
    
    float valArr[20];//size = (UL-LL)/threshold
    for(float i=0;i<2;i=i+0.1){
        float sum = pow(i,2)-(i)-1;
        printf("%f",sum);
        int j = 10*i;
        valArr[j] = sum;
        printf("\t iteration {%f}",i);
        printf("\n");
    }
    printf("The root in this range is %f",findMinimum(arr,20));
    return 0;

}
