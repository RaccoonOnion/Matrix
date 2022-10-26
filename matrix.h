#ifndef __MATRIX_H__
#define __MATRIX_H__

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