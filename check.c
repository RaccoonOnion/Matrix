#include "check.h"
// Constants
const int MATSIZE = sizeof(type)*2 + 8 + sizeof(bool); 

//function to check pointer
int checkPointer(void * ptr, char * name)
{
    int errNum = 0;
    if(ptr == NULL)
    {
        errNum = 1;
        printf("The pointer of %s is a null pointer!\n", name);
        return errNum;
    }
    return errNum;
}

//function to check create
int checkCreate(type rows, type cols, float * ptrData, Matrix * ptrMat)
{

    int errNum = 0;
    int flag1 = checkPointer(ptrData, "data");
    int flag2 = checkPointer(ptrMat, "matrix");
    if(flag1 != 0 || flag2 != 0)
    {
        errNum = 1;
        return errNum;
    }
    if (rows <= 0 || cols <= 0)
    {
        printf("The number of rows and columns must be positive!");
        errNum = 2;
        return errNum;
    }
    return errNum;
}

int checkDelete(Matrix * ptrMat)
{
    int errNum = 0;
    errNum = checkPointer(ptrMat, "matrix");
    if(errNum != 0 )
    {
        return errNum;
    }
    if (ptrMat->create == 0)
    {
        errNum = 2;
        printf("The matrix has not been created yet! Check if you have called the method \"createMatrix\"!\n");
        return errNum;
    }
    return errNum;
}

//function to check copymatrix
int checkCopy(Matrix * ptrMatSrc, Matrix * ptrMatDest)
{
    int errNum = 0;
    int flag1 = checkPointer(ptrMatSrc, "source");
    int flag2 = checkPointer(ptrMatDest, "destination");
    int flag3 = checkPointer(ptrMatSrc->pData, "data array in source matrix");
    if (flag1 != 0 || flag2 != 0 || flag3 != 0)
    {
        errNum = 1;
        return errNum;
    }
    if(ptrMatSrc->create == 0)
    {
        printf("The source matrix is empty!\n");
        errNum = 2;
        return errNum;
    }
    if (ptrMatDest->create == 1)
    {
        printf("The destination matrix has data from previous creation. We will remove them!\n");
        deleteMatrix(ptrMatDest);
    }
    return errNum;
}

int checkAddSubMats(Matrix * ptrMat1, Matrix * ptrMat2)
{
    int errNum = 0;
    int flag1 = checkPointer(ptrMat1, "matrix1");
    int flag2 = checkPointer(ptrMat2, "matrix2");
    int flag3 = checkPointer(ptrMat1->pData, "data array in matrix1");
    int flag4 = checkPointer(ptrMat2->pData, "data array in matrix2");
    if (flag1 != 0 || flag2 != 0 || flag3 != 0 || flag4 != 0)
    {
        errNum = 1;
        return errNum;
    }
    if(ptrMat1->create == 0 || ptrMat2->create == 0 )
    {
        printf("One or both of the matrices is (are) empty!\n");
        errNum = 2;
        return errNum;
    }
    if (ptrMat1->rows != ptrMat2->rows || ptrMat1->cols != ptrMat2->cols)
    {
        printf("The sizes of two matrices are not consistent!\n");
        errNum = 3;
        return errNum;
    }
    return errNum;
}

int checkScalarArithmetic(Matrix * ptrMat)
{
    int errNum = 0;
    int flag = checkPointer(ptrMat, "matrix");
    if(flag != 0)
    {
        errNum = 1;
        return errNum;
    }
    if(ptrMat->create == 0)
    {
        printf("The matrix has not been created yet!\n");
        errNum = 2;
        return errNum;
    }
    return errNum;
}

int checkMulMats(Matrix * ptrMat1, Matrix * ptrMat2, Matrix * ptrMat3)
{
    int errNum = 0;
    int flag1 = checkPointer(ptrMat1, "matrix1");
    int flag2 = checkPointer(ptrMat2, "matrix2");
    int flag3 = checkPointer(ptrMat1->pData, "data array in matrix1");
    int flag4 = checkPointer(ptrMat2->pData, "data array in matrix2");
    if (flag1 != 0 || flag2 != 0 || flag3 != 0 || flag4 != 0)
    {
        errNum = 1;
        return errNum;
    }
    if(ptrMat1->create == 0 || ptrMat2->create == 0 )
    {
        printf("One or both of the matrices is (are) empty!\n");
        errNum = 2;
        return errNum;
    }
    int flag5 = checkPointer(ptrMat3, "destination matrix");
    if (flag5 != 0)
    {
        printf("The destination matrix could not be a null pointer!");
        errNum = 3;
        return errNum;
    }
    if(ptrMat3->create == 1)
    {
        printf("The destination matrix has data from previous creation. We will remove them!\n");
        deleteMatrix(ptrMat3);
    }
    if(ptrMat1->cols != ptrMat2->rows)
    {
        printf("The sizes of the two multiplied matrices are not consistent!\n");
        errNum = 4;
        return errNum;
    }
    return errNum;
}