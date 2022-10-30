#ifndef __CHECK_H__
#define __CHECK_H__

#include "matrix.h"

// Checking function declarations are here 
int checkCreate(type rows, type cols, float * ptrData, Matrix * ptrMat);
int checkDelete(Matrix * ptrMat);
int checkPointer(void * ptr, char * name);
int checkCopy(Matrix * ptrMatSrc, Matrix * ptrMatDest);
int checkAddSubMats(Matrix * ptrMat1, Matrix * ptrMat2);
int checkScalarArithmetic(Matrix * ptrMat);
int checkMulMats(Matrix * ptrMat1, Matrix * ptrMat2, Matrix * ptrMat3);
#endif