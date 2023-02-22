#include "matrixfuncs.h"


void swap(float * a1, float * a2) {
    float temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}


float ** mallocsquarematrix(int size) {
    float ** A = malloc(sizeof(float*)*size); if (!A) return NULL;
    for (int i = 0; i < size; i++) {
        A[i] = malloc(sizeof(float)*size); if (!A[i]) return NULL;
    }
    return A;
}


float ** copymatrix(float ** A, int size) {
    float ** A1 = mallocsquarematrix(size); if (!A1) return NULL;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A1[i][j] = A[i][j];
        }
    }
    return A1;
}


void printmatrix(float ** A, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%-8.3f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void printvector(float * b, int size) {
    for (int i = 0; i < size; i++) {
        printf("%-8.3f\n", b[i]);
    }
    printf("\n");

}


void printsystem(float ** A, float * b, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%-8.3f ", A[i][j]);
        }
        printf("\t  %-8.3f\n", b[i]);
        printf("\n");
    }
    printf("\n");
}


void printcompletesystem(float ** A, float * x, float * b, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%-8.3f", A[i][j]);
        }
        printf("  *    %-8.3f\t = \t%-8.3f\n", x[i], b[i]);
        printf("\n");
    }
    printf("\n");
}


void freematrix(float ** A, int size) {
     for (int i = 0; i < size; i++)
        free(A[i]);
    free(A);
}


float ** creatematrix(int size) {
    float ** A = mallocsquarematrix(size); if (!A) return NULL;

    int a;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a = rand() % 10;
            while (a == 0 && i == j)
                a = rand() % 20 - 10;

            A[i][j] = a; 
        }
    }
    return A;
}


void freevector(float * b, int size) {
    free(b);
}


float * createvector(int size) {
    float * b = malloc(sizeof(float)*size); if (!b) return NULL;
    for (int i = 0; i < size; i++) {
        int e = rand() % 20 - 10;
        b[i] = e;
    }
    return b;
}


float ** createidentitymatrix(int size) {
    float ** I = mallocsquarematrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i==j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }
    return I;
}


void squarematrixtranspose(float ** A, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            swap(&A[i][j], &A[j][i]);
        }
    }
}


//grade school implementation
float ** matrixmultiplication(float ** A1, float ** A2, int size) {
    float ** A = mallocsquarematrix(size); if (!A) return NULL;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = 0;
            for (int k = 0; k < size; k++) {
                A[i][j] += (A1[i][k]*A2[k][j]);
            }
        }
    }
    return A;
}