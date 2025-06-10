#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int degree = 0;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    struct polynomial p;
    p = poly(degree);

    printPoly(&p);

    //printf("%f",polyval(p,1.618033));

    float UL = 0;
    float LL = 0;
    printf("Enter the lower bound of the range: ");
    scanf("%f",&LL);
    printf("Enter the upper bound of the range: ");
    scanf("%f",&UL);

    check4root(p,LL,UL);

    printf("\nNow we find the root of the polynomial in the given range\n");

    printf("The root of the given polynomial in the given range is:\n");
    float x = findRoot(p,LL,UL,0.01);
    printf("%f",x);

    free(p.data);
    return 0;

}
