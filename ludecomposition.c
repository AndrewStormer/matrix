#include "ludecomposition.h"


/*
Solve x for the system Ax = b using Gaussian elimination
Col is the column in which the algorithm is working on, to start the algorithm, use col = 0 (by def of lucomposition, you must start on the first column [0th column indexing from 0])
*/
float ** ludecomposition(float ** A, float * b, int col, int size) {
    if (col == size - 1)
        return A;
    if (A[col][col] == 0) {
        printf("Value in diagonal 0, cannot divide by 0!\n"); //handle exception
        return A;
    }
    float m;
    for (int i = col+1; i < size; i++) {
        m = (A[i][col] / A[col][col]);
        for (int j = col; j < size; j++) {
            A[i][j] -= m*A[col][j];
        }      
        b[i] -= m*b[col];
        A[i][col] = m;
    }
    ludecomposition(A, b, col+1, size);
    
    return A;
}


//Solves the upper triangular matrix formed with LU Decomposition for the equation Ax = b, and returns x
float * solveludecomposition(float ** A, float * b, int size) {
    float * x = malloc(sizeof(float)*size); if (!x) return NULL;
    float solvedvalues;
    
    x[size - 1] = (b[size-1])/A[size-1][size-1];
    for (int i = size-2; i >= 0; i--) {
        solvedvalues = 0;
        for (int j = i + 1; j < size; j++) {
            solvedvalues += A[i][j]*x[j];
        }
        x[i] = (b[i]-solvedvalues) / A[i][i];
    }
    return x;
}