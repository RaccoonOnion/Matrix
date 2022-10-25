#include "matrix.h"
#include "check.h"

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
Matrix * createMatrix(type rows, type cols, float * pData)
{
    Matrix mat = {};
    return &mat;
}

// Function to delete a matrix
bool createMatrix()
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


