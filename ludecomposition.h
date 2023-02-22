#include "matrixfuncs.h"


float ** ludecomposition(float ** A, float * b, int col, int size);
float * solveludecomposition(float ** A, float * b, int size);