#include "matrix.h"

void test()
{
    Matrix mat = {};
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("-------------------------------------------------------------------------------------------------\n");

    float ptrData[2] = {1.0f, 2.0f};
    bool flagCreate = createMatrix(1ll,2ll,ptrData,&mat);

    printf("create is success? %d\n", flagCreate);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    Matrix mat2 = {};
    bool flagCopy = copyMatrix(&mat, &mat2);

    printf("copy is success? %d\n", flagCopy);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat2.rows, mat2.cols, mat2.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat2.pData[0], mat2.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    bool flagAdd = addMatrix(&mat, &mat2);
    printf("addition is success? %d\n", flagAdd);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    bool flagSub = subtractMatrix(&mat, &mat2);
    printf("subtraction is success? %d\n", flagSub);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    bool flagAddScalar = addScalar(1.0, &mat);
    printf("adding scalar is success? %d\n", flagAddScalar);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    bool flagSubScalar = subtractScalar(1.0, &mat);
    printf("subtracting scalar is success? %d\n", flagSubScalar);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    bool flagMulScalar = multiplyScalar(2.0, &mat);
    printf("multiplying scalar is success? %d\n", flagMulScalar);
    printf("rows is %lld, cols is %lld, pData is %p\n", mat.rows, mat.cols, mat.pData);
    printf("Data 1 is %f, data 2 is %f\n", mat.pData[0], mat.pData[1]);
    printf("-------------------------------------------------------------------------------------------------\n");

    float min;
    bool flagFindMin = findMin(&mat, &min);
    printf("finding min is success? %d\n", flagFindMin);
    printf("min is %f\n", min);
    printf("-------------------------------------------------------------------------------------------------\n");

    float max;
    bool flagFindMax = findMax(&mat, &max);
    printf("finding max is success? %d\n", flagFindMax);
    printf("max is %f\n", max);
    printf("-------------------------------------------------------------------------------------------------\n");

    Matrix A = {};
    Matrix B = {};
    Matrix C = {};
    float data1[4] = {1.0, 2.0, 3.0, 4.0};
    float data2[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    createMatrix(2,2,data1,&A);
    createMatrix(2,3,data2,&B);
    multiplyMatrices(&A, &B, &C);
    printf("For matrix C: Data 1 is %f, data 2 is %f, Data 3 is %f, data 4 is %f, Data 5 is %f, data 6 is %f\n", C.pData[0], C.pData[1], C.pData[2], C.pData[3], C.pData[4], C.pData[5]);
    printf("-------------------------------------------------------------------------------------------------\n");

}

int main()
{
    test();
    return 0;
}