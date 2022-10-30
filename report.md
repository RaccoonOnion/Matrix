# Project3 - Library for Matrix Operations in C
Arthur: Yunxiang Yan (Student id: 11912525)

## Part I Functionality
### Methods: 

`bool createMatrix(type rows, type cols, float * ptrData, Matrix * ptrMat);`

`bool deleteMatrix(Matrix * ptrMat);`

`bool copyMatrix(Matrix * ptrMatSrc, Matrix * ptrMatDest);`

`bool addMatrix(Matrix * ptrMat1, Matrix * ptrMat2);`

`bool subtractMatrix(Matrix * ptrMat1, Matrix * ptrMat2);`

`bool addScalar(float a, Matrix * ptrMat);`

`bool subtractScalar(float a, Matrix * ptrMat);`

`bool multiplyScalar(float k, Matrix * ptrMat);`

`bool multiplyMatrices(Matrix * ptrMat1, Matrix * ptrMat2, Matrix * ptrMat3);`

`float findMin(Matrix * ptrMat, float * ptrMin);`

`bool findMax(Matrix * ptrMat, float * ptrMax);`

## Part II Checking

For all pointers we check if it is a null pointer or if it is not the right pointer we need.

For operations that require matrices to have certain size requirements, we check if they are satisfied.

