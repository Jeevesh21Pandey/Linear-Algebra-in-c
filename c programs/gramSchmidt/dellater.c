#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct vector{

    double size;
    float *data;

};

struct vector vect(int size){

    struct vector v;
    v.size = size;
    v.data = (float*)malloc(sizeof(float) * v.size);

    for (int i = 0 ; i < v.size; i++) {
        printf("Enter the %d th element: ", i+1);
        scanf("%f", &v.data[i]);
    }
    return v;

}
void dispVect(struct vector v){

    int size = v.size;

    for(int i = 0; i < size; i++){
        printf("%f",v.data[i]);
        if(i != size) printf(",");
    }
    printf("\n");

}

float innerProduct(struct vector *v1, struct vector *v2){

    int size = v1->size;
    float ip = 0;

    for(int i = 0; i < size; i++){

        ip += v1->data[i] * v2->data[i];
    }

    return ip;

}

struct vectorSpace {

    int dimension;             
    int count;                 
    struct vector* vectors;    

};

struct vectorSpace createVectorSpace(int count, int dimension) {

    struct vectorSpace vs;
    vs.count = count;
    vs.dimension = dimension;
    vs.vectors = (struct vector*)malloc(sizeof(struct vector) * count);
    
    for (int i = 0; i < count; i++) {
        printf("Enter the %d th vector\n",i+1);
        vs.vectors[i] = vect(dimension);
    }

    return vs;

}

void dispVS(struct vectorSpace V){

    int count = V.count;
    int dim = V.dimension;

    printf("{");
    for(int i = 0; i < count; i++){
        printf("(");
        dispVect(V.vectors[i]);
        printf("),");
    }
    printf("}");
    printf("\n");
}

void freeVectorSpace(struct vectorSpace* vs) {

    for (int i = 0; i < vs->count; i++) {
        free(vs->vectors[i].data);
    }
    free(vs->vectors);
    vs->vectors = NULL;
    vs->count = 0;
    vs->dimension = 0;

}

struct vectorSpace gs(struct vectorSpace V){

    struct vectorSpace v;
    v.count = V.count;
    v.dimension = V.dimension;
    v.vectors = (struct vector*)malloc(sizeof(struct vector) * v.count);
    struct vector v1 = V.vectors[0];

    //Obtaining the first orthagonal vector
    float mod = sqrt(innerProduct(&v1,&v1));
    for(int i = 0; i < v.dimension; i++){
        v1.data[i] = v1.data[i]/mod;
    }
    v.vectors[0] = v1;

    //Using the first orthogonal vector to find the rest
    //V = {b_1,b_2,...,b_n} forms the basis and v = {a_1,a_2,...,a_n} forms the orthonormal basis
    //
    //Gram Schmidt process -
    //a_i = (b_i - (b_i.a_i-1)*a_i-1)/mod(b_i - (b_i.a_i-1)*a_i-1)
    for(int i = 1; i < v.dimension; i++){
        struct vector Vx = V.vectors[i]; //Stores the i th vector from vs V
        struct vector vx = v.vectors[i-1];//Stores the i-1 th vector from vs v
        struct vector vy;
        vy.size = v.dimension;
        vy.data = (float*)malloc(sizeof(float) * vy.size);

        //Subtract the projection
        float ip = innerProduct(&Vx,&vx);
        for(int k = 0; k < v.dimension; k++){
            vy.data[k] = (Vx.data[k] - (ip * vx.data[k]));
        }

        //Normalize the vectors
        float mod = sqrt(innerProduct(&vy,&vy));
        for(int k = 0; k < v.dimension; k++){
            vy.data[k] = vy.data[k] / mod;
        }

        v.vectors[i] = vy;
    }

    return v;
}

int main(){

    struct vectorSpace V;
    V = createVectorSpace(2,2);
    dispVS(V);

    struct vectorSpace v;
    v = gs(V);
    printf("The orthagonalized basis of the given Vector Space is :\n");
    dispVS(v);

    freeVectorSpace(&v);
    freeVectorSpace(&V);

    return 0;
}