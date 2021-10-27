#include <stdio.h>
#include <omp.h>
#define n 1000
double A[n][n],B[n][n],C[n][n];

int main()
{
    int i,j,k;
   //初始化矩阵A和矩阵B
    for(i=0;i<n;i++)
    for(j=0;j<n;j++) {
        A[i][j] = 1.0;
        B[i][j] = 1.0;
    }
   //并行计算矩阵C
#pragma omp parallel for shared(A,B,C) private(i,j,k)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        C[i][j] = 0;
    for(k=0;k<n;k++)
        C[i][j]+=A[i][k]*B[k][j];
    }
    return 0;
}