#include "matrix.h"
#include "check.h"
#include <stdio.h>

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
bool createMatrix(type rows, type cols, float * pData, Matrix * mat)
{
    mat->rows = rows;
    mat->cols = cols;
    mat->pData = pData;
    return true;
}

// Function to delete a matrix
bool deleteMatrix()
{
    return true;
}

// Function to copy a matrix
bool copyMatrix()
{
    return true;
}

// Funciton to add two matrces together
bool addMatrix()
{
    return true;
}

// Function to do matrix subtraction
bool subtractMatrix()
{
    return true;
}

// Function to add a scalar to a matrix
bool addScalar()
{
    return true;
}

// Function to subtract a scalar from a matrix
bool subtractScalar()
{
    return true;
}

// Function to multiply a matrix with a scalar
bool multiplyScalar()
{
    return true;
}

// Function to multiply two matrices
bool multiplyMatrices()
{
    return true;
}

// Function to find minimal value of a matrix
long long findMin()
{
    return 0ll;
}

// Function to find maximal value of a matrix
long long findMax()
{
    return 0ll;
}

int main()
{
    Matrix mat = {};
    // printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    float pData[2] = {1.0f, 2.0f};
    createMatrix(1ll,2ll,pData,&mat);
    // printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    // printf("Data 1 is %f, data 2 is %f\n", pData[0], pData[1]);

}


