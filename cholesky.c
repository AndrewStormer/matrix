#include "cholesky.h"


//Finds the cholesky factor R of A, A must be positive definite (will return NULL else)
float ** choleskeydecomposition(float ** A, int size) {
    float ** R = mallocsquarematrix(3); if (!R) return NULL;
    int i,j, k;

    float r;
    for (i = 0; i < size; i++) {
        for (j = 0; j < i; j++)
            R[i][j] = 0.0F;

        r = A[i][i];
        for (j = 0; j < i; j++)
            r -= (R[j][i]*R[j][i]);
        R[i][i] = sqrt(r);

        for (j = i+1; j < size; j++) {
            r = A[i][j];
            for (k = 0; k < i; k++) {
                r -= R[k][i]*R[k][j];
            }
            R[i][j] = r / R[i][i];
        }
    }
    return R;
}