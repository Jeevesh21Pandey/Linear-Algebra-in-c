#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct polynomial {

    int degree;
    float *data;

};

struct polynomial poly(int degree);

void printPoly(struct polynomial *p);

int check4root(struct polynomial p,float LL,float UL);

int findMinAbsValueIndex(float arr[], int size);

float findRoot(struct polynomial p, float LL, float UL, float tolerance);

#endif
