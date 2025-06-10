#include "gramSchmidt.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    struct vectorSpace V;
    int dim,count;
    printf("Enter the dimension of the basis : ");
    scanf("%d",dim);
    printf("Enter the number of vectors in the basis : ");
    scanf("%d",count);
    V = createVectorSpace(count,dim);
    dispVS(V);

    struct vectorSpace v;
    v = gs(V);
    dispVS(v);

    return 0;
}