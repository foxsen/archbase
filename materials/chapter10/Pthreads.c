#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4 //假设线程数目为4
#define n 1000
double *A,*B,*C;
void *matrixMult(void *id) {//计算矩阵乘
    int my_id = (int ) id;
    int i,j,k,start,end;
    //计算进程负责的部分
    start = my_id*(n/NUM_THREADS);
    if(my_id == NUMTHREADS-1)
        end = n;
    else
        end = start+(n/NUM_THREADS);

    for(i=start;i<end;i++)
    for(j=0;j<n;j++) 
    {
        C[i*n+j] = 0;
        for(k=0;k<n;k++)
            C[i*n+j]+=A[i*n+k]*B[k*n+j];
    }
}

int main() {
    int i,j;
    pthread_t tids[NUM_THREADS];
    //分配数据空间
    A = (double *)malloc(sizeof(double)*n*n);
    B = (double *)malloc(sizeof(double)*n*n);
    C = (double *)malloc(sizeof(double)*n*n);
    //初始化数组
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){ 
        A[i*n+j] = 1.0;
        B[i*n+j] = 1.0;
    }

    for(i=0; i<NUM_THREADS; i++)
        pthread_create(&tids[i], NULL, matrixMult, (void *) i);
    
    for(i=0; i<NUM_THREADS; i++)
        pthread_join(tids[i], NULL);
    
    return 0;
}

