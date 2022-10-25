#include "matrix.h"
#include "check.h"
#include <stdio.h>
#include <stdlib.h>
// macro definition for bool
typedef char bool;
#define true 1
#define false 0

// type defn for datatype used for rows and cols
typedef long long type;

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

// Function to create a matrix
bool createMatrix(type rows, type cols, float * ptrData, Matrix * ptrMat)
{
    ptrMat->rows = rows;
    ptrMat->cols = cols;
    ptrMat->pData = (float *) malloc(rows*cols*sizeof(float));
    type num = rows * cols;
    // check if the number of elements in ptrData is the same as the valid number of the matrix (which equals to rows*cols)
    //TODO!!

    // copy the element in ptrData to pData in the matrix one by one
    for (int i = 0; i < num; i++)
    {
        float tmp = ptrData[i];
        ptrMat->pData[i] = tmp;
    }
    return true;
}

// Function to delete a matrix
bool deleteMatrix(Matrix * ptrMat)
{
    if (ptrMat == NULL) return false;
    free(ptrMat->pData);
    return true;
}

// Function to copy matrixSrc to matrixDest
bool copyMatrix(Matrix * ptrMatSrc, Matrix * ptrMatDest)
{
    deleteMatrix(ptrMatDest);
    type rows = ptrMatSrc->rows;
    type cols = ptrMatSrc->cols;
    float * ptrData = ptrMatSrc->pData;
    createMatrix(rows, cols, ptrData, ptrMatDest);
    return true;
}

// Funciton to add matrix2 to matrix1
bool addMatrix(Matrix * ptrMat1, Matrix * ptrMat2)
{
    // check if two matrices have the same size!!
    // TODO!!!!!
    type rows = ptrMat1->rows;
    type cols = ptrMat1->cols;
    type num = rows * cols;
    for (int i = 0; i < num; i++)
    {
        // check!!!
        float value1 = ptrMat1->pData[i];
        float value2 = ptrMat2->pData[i];
        ptrMat1->pData[i] = value1 + value2;
    }
    return true;
}

// Funciton to subtract matrix2 from matrix1
bool subtractMatrix(Matrix * ptrMat1, Matrix * ptrMat2)
{
    // check if two matrices have the same size!!
    // TODO!!!!!
    type rows = ptrMat1->rows;
    type cols = ptrMat1->cols;
    type num = rows * cols;
    for (int i = 0; i < num; i++)
    {
        // check!!!
        float value1 = ptrMat1->pData[i];
        float value2 = ptrMat2->pData[i];
        ptrMat1->pData[i] = value1 - value2;
    }
    return true;
}

// Function to add a scalar to a matrix
bool addScalar(float a, Matrix * ptrMat)
{
    type rows = ptrMat->rows;
    type cols = ptrMat->cols;
    type num = rows*cols;

    Matrix mat = {};

    float ptrData[num];
    for (int i = 0; i < num; i++)
    {
        ptrData[i] = a;
    } 

    createMatrix(rows, cols, ptrData, &mat);
    addMatrix(ptrMat, &mat);
    deleteMatrix(&mat);

    return true;
}

// Function to subtract a scalar from a matrix
bool subtractScalar(float a, Matrix * ptrMat)
{
    addScalar(-a, ptrMat);
    return true;
}

// Function to multiply a matrix with a scalar
bool multiplyScalar(float k, Matrix * ptrMat)
{
    type rows = ptrMat->rows;
    type cols = ptrMat->cols;
    type num = rows*cols;

    for (int i = 0; i < num; i++)
    {
        ptrMat->pData[i] *= k;
    } 

    return true;
}

// Function to multiply two matrices
bool multiplyMatrices()
{
    return true;
}

// Function to find minimal value of a matrix
float findMin(Matrix * ptrMat, float * ptrMin)
{
    float currMin = __FLT_MAX__;

    type rows = ptrMat->rows;   
    type cols = ptrMat->cols;
    type num = rows*cols;

    for (int i = 0; i < num; i++)
    {
        float tmp = ptrMat->pData[i];
        currMin = (currMin > tmp) ? tmp : currMin;
    } 
    *ptrMin = currMin;
    return true;
}

// Function to find maximal value of a matrix
long long findMax()
{
    return 0ll;
}

int main()
{

    Matrix mat = {};

    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);

    float ptrData[2] = {1.0f, 2.0f};
    bool flagCreate = createMatrix(1ll,2ll,ptrData,&mat);

    printf("create is success? %d\n", flagCreate);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);

    // bool flagDelete = deleteMatrix(&mat);

    // printf("delete is success? %d\n", flagDelete);

    Matrix mat2 = {};
    bool flagCopy = copyMatrix(&mat, &mat2);

    printf("copy is success? %d\n", flagCopy);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat2.rows, mat2.cols, mat2.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat2.pData[0], mat2.pData[1]);

    bool flagAdd = addMatrix(&mat, &mat2);
    printf("addition is success? %d\n", flagAdd);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);

    bool flagSub = subtractMatrix(&mat, &mat2);
    printf("subtraction is success? %d\n", flagSub);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);

    bool flagAddScalar = addScalar(1.0, &mat);
    printf("adding scalar is success? %d\n", flagAddScalar);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);

    bool flagSubScalar = subtractScalar(1.0, &mat);
    printf("subtracting scalar is success? %d\n", flagSubScalar);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);

    bool flagMulScalar = multiplyScalar(2.0, &mat);
    printf("multiplying scalar is success? %d\n", flagMulScalar);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);

    float min;
    bool flagFindMin = findMin(&mat, &min);
    printf("finding min is success? %d\n", flagFindMin);
    printf("min is %f\n", min);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
}


