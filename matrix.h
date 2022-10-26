#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>

// macro definition for bool
typedef char bool;
#define true 1
#define false 0

/* 
Structure definition for matrix

Name: Matrix

rows: # of rows in the matrix, type: long long int
cols: # of columns in the matrix, type: long long int
pData: the pointer to the an array of matrix data, type: float pointer

*/
typedef struct _Matrix
{
    long long rows;
    long long cols;
    float * pData;
} Matrix;

// type defn for datatype used for rows and cols
typedef long long type;

// Matrix operation declarations are here 
bool createMatrix(type rows, type cols, float * ptrData, Matrix * ptrMat);
bool deleteMatrix(Matrix * ptrMat);
bool copyMatrix(Matrix * ptrMatSrc, Matrix * ptrMatDest);
bool addMatrix(Matrix * ptrMat1, Matrix * ptrMat2);
bool subtractMatrix(Matrix * ptrMat1, Matrix * ptrMat2);
bool addScalar(float a, Matrix * ptrMat);
bool subtractScalar(float a, Matrix * ptrMat);
bool multiplyScalar(float k, Matrix * ptrMat);
bool multiplyMatrices(Matrix * ptrMat1, Matrix * ptrMat2, Matrix * ptrMat3);
float findMin(Matrix * ptrMat, float * ptrMin);
bool findMax(Matrix * ptrMat, float * ptrMax);
#endif