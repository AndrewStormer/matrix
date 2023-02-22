#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MATRIX_SIZE 3 //Matrix is square iff its dimensions are MATRIX_SIZE x MATRIX_SIZE (MATRIX_SIZE is in the set of integers)


float ** mallocsquarematrix();
float ** copymatrix(float ** A, int size);
void printmatrix(float ** A, int size);
void printvector(float * b, int size);
void printsystem(float ** A, float * b, int size);
void printcompletesystem(float ** A, float * x, float * b, int size);
void freematrix(float ** A, int size);
float ** creatematrix(int size);
void freevector(float * b, int size);
float * createvector(int size);
void squarematrixtranspose(float ** A, int size);
float ** matrixmultiplication(float ** A1, float ** A2, int size);
