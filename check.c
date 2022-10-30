#include "check.h"

// Constants
const int MATSIZE = sizeof(type)*2 + 8 + sizeof(bool); 

//function to check create
int checkCreate(type rows, type cols, float * ptrData, Matrix * ptrMat)
{
    int errNum = 0;
    if (rows <= 0 || cols <= 0)
    {
        errNum = 1;
        return errNum;
    }
    int elementNum = rows * cols;
    if (ptrMat == NULL)
    {
        errNum = 2;
        printf("The matrix pointer you give is a null pointer! Check if the this matrix has been deleted!\n");
        return errNum;
    }
    return errNum;
}