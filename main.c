#include "ludecomposition.h"
#include "cholesky.h"


int main(void) {
    srand(time(NULL));

    int a_size = 5;

    float ** A = creatematrix(a_size);
    float * b = createvector(a_size);

    printsystem(A, b, a_size);
    ludecomposition(A, b, 0, a_size);
    float * x = solveludecomposition(A, b, a_size);
    printcompletesystem(A, x, b, a_size);

    float ** A2 = malloc(sizeof(float*)*3);
    for (int i = 0; i < 3; i++)
        A2[i] = malloc(sizeof(float)*3);
    A2[0][0] = 1; A2[0][1] = 1; A2[0][2] = 1;
    A2[1][0] = 1; A2[1][1] = 2; A2[1][2] = 2;
    A2[2][0] = 1; A2[2][1] = 2; A2[2][2] = 3;

    printmatrix(A2, 3);
    float ** R = choleskeydecomposition(A2, 3);

    printmatrix(R, 3);
    float ** RT = copymatrix(R, 3);
    squarematrixtranspose(RT, 3);
    printmatrix(RT, 3);

    float ** A3 = matrixmultiplication(RT, R, 3);
    printmatrix(A3, 3);

    freematrix(A, 3);
    freevector(b, 3);
    freevector(x, 3);
    return 0;
}