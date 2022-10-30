#include "matrix.h"
#include "check.h"

// Function to create a matrix
bool createMatrix(type rows, type cols, float * ptrData, Matrix * ptrMat)
{
    int flag = checkCreate(rows, cols, ptrData, ptrMat);
    if (flag != 0)
    {
        printf("Please check your input and create the matrix again!\n");
        return false;
    }
    ptrMat->rows = rows;
    ptrMat->cols = cols;
    ptrMat->pData = (float *) malloc(rows*cols*sizeof(float));
    type num = rows * cols;

    // copy the element in ptrData to pData in the matrix one by one
    for (int i = 0; i < num; i++)
    {
        float tmp = ptrData[i];
        ptrMat->pData[i] = tmp;
    }
    ptrMat->create = 1;
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

// Function to do Matrix1 * Matrix2 and then assign to Matrix3
bool multiplyMatrices(Matrix * ptrMat1, Matrix * ptrMat2, Matrix * ptrMat3)
{
    // check sizes!!!
    // TODO
    type a = ptrMat1->rows;
    type b = ptrMat1->cols;
    type c = ptrMat2->cols;
    type num = a*c;

    float ptrData[num];

    for (int row = 0; row < a; row++)
    {
        for (int col = 0; col < c; col++)
        {
            float sum = 0.0f;
            for (int i = 0; i < b; i++)
            {
                sum += (ptrMat1->pData[b*row+i]) * (ptrMat2->pData[i*c+col]);
            }
            ptrData[c*row+col] = sum;
        }
    }

    createMatrix(a, c, ptrData, ptrMat3);

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
bool findMax(Matrix * ptrMat, float * ptrMax)
{
    float currMax = __FLT_MIN__;

    type rows = ptrMat->rows;   
    type cols = ptrMat->cols;
    type num = rows*cols;

    for (int i = 0; i < num; i++)
    {
        float tmp = ptrMat->pData[i];
        currMax = (currMax < tmp) ? tmp : currMax;
    } 
    *ptrMax = currMax;

    return true;
}



