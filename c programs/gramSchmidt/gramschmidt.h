#ifndef GRAMSCHMIDT_H
#define GRAMSCHMIDT_H

struct vector{

    double size;
    float *data;

};
struct vector vect(int size);
void dispVect(struct vector v);
float innerProduct(struct vector *v1, struct vector *v2);


struct vectorSpace {

    int dimension;             
    int count;                 
    struct vector* vectors;    

};
struct vectorSpace createVectorSpace(int count, int dimension);
void dispVS(struct vectorSpace V);
void freeVectorSpace(struct vectorSpace* vs);
struct vectorSpace gs(struct vectorSpace V);

#endif