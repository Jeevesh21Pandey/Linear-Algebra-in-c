#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial {

    int degree;
    float *data;

};

struct polynomial poly(int degree) {

    struct polynomial p;
    p.degree = degree + 1;
    p.data = malloc(sizeof(float) * p.degree);
    for (int i = p.degree - 1 ; i>=0 ; i--) {
        printf("Enter the %d th degree coefficient: ", i);
        scanf("%f", &p.data[i]);
    }
    return p;

}

void printPoly(struct polynomial *p) {

    int deg = p->degree;
    for (int i = deg - 1; i>=0 ; i--){
        printf(" %f *x^%d", p->data[i], i);
        if(i != 0) printf(" + ");
    }
    printf("\n");

}

float polyval(struct polynomial p, float val) {

    float result = 0;
    for (int i = 0; i < p.degree; i++) {
        result += p.data[i] * pow(val, i);
    }
    return result;

}

int check4root(struct polynomial p,int LL,int UL){

    if(polyval(p,0) == 0){
        printf("The root exists at x = 0");
        return 1;
    }

    float ulVal = polyval(p,UL);
    float llVal = polyval(p,LL);

    if((ulVal > 0 && llVal < 0)||(ulVal < 0 && llVal > 0)){
         printf("A root exists in the given range!\n");
         return 1;
    }
    else if ((ulVal > 0 && llVal > 0) || (ulVal < 0 && llVal < 0))
    {
        printf("We cannot be sure if a root exists!\n");
        return -1;
    }
    
    else {
        printf("NO root exists!\n");
        return -1;
    }

}

int findMinAbsValueIndex(float arr[], int size) {
    if (size <= 0 || arr == NULL) {
        return -1; // Return -1 to indicate error
    }

    double min = fabs(arr[0]);
    int minIndex = 0;
    
    for (int i = 1; i < size; i++) {
        double currentAbs = fabs(arr[i]);
        if (currentAbs < min) {
            min = currentAbs;
            minIndex = i;
        }
    }
    
    return minIndex;
}

float findRoot(struct polynomial p, float LL, float UL) {
    
    int flag = check4root(p, LL, UL);
    if (flag != 1) {
        printf("No root in [%.2f, %.2f].\n", LL, UL);
        return NAN;
    }

    if (fabs(polyval(p, LL)) < 1e-6) return LL;
    if (fabs(polyval(p, UL)) < 1e-6) return UL;

    float M, m;
    const float tolerance = 1e-6;

    while ((UL - LL) > tolerance) {
        M = (LL + UL) / 2.0f;
        m = polyval(p, M);

        if (fabs(m) < tolerance) return M;

        if (polyval(p, LL) * m < 0) {
            UL = M;  
        } else {
            LL = M;
        }
    }

    return M;
}

int main(){

    int degree = 0;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    struct polynomial p;
    p = poly(degree);

    printPoly(&p);
    
    //printf("%f",polyval(p,1.618033));

    int UL = 0;
    int LL = 0;
    printf("Enter the lower bound of the range: ");
    scanf("%d",&LL);
    printf("Enter the upper bound of the range: ");
    scanf("%d",&UL);

    check4root(p,UL,LL);
    
    printf("\nNow we find the root of the polynomial in the given range\n");

    printf("The root of the given polynomial in the given range is:\n");
    float x = findRoot(p,UL,LL);
    printf("%f",x);

    free(p.data);
    return 0;
    
}