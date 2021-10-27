#include <stdio.h>
#include "mpi.h"
#define n 1000
int main(int argc, char **argv)
{
    double *A,*B,*C;
    int i,j,k;
    int ID,num_procs,line;
    MPI_Status status;

    MPI_Init(&argc,&argv); //Initialize the MPI environment
    MPI_Comm_rank(MPI_COMM_WORLD,&ID);//获取当前进程号
    MPI_Comm_size(MPI_COMM_WORLD,&num_procs);//获取进程数目

    //分配数据空间
    A = (double *)malloc(sizeof(double)*n*n);
    B = (double *)malloc(sizeof(double)*n*n);
    C = (double *)malloc(sizeof(double)*n*n);
    line = n/num_procs;//按进程数来划分数据

    if(ID==0){ //节点0，主进程
        //初始化数组
        for(i=0;i<n;i++)
        for(j=0;j<n;j++){ 
            A[i*n+j] = 1.0;
            B[i*n+j] = 1.0;
        }
        //将矩阵A、B的相应数据发送给从进程
        for(i=1;i<num_procs;i++) {
            MPI_Send(B,n*n,MPI_DOUBLE,i,0,MPI_COMM_WORLD);
            MPI_Send(A+(i-1)*line*n,line*n,MPI_DOUBLE,i,1,MPI_COMM_WORLD);
        }
        //接收从进程计算结果
        for(i=1;i<num_procs;i++) 
            MPI_Recv(C+(i-1)*line*n,line*n,MPI_DOUBLE,i,2,MPI_COMM_WORLD,&status);
        //计算剩下的数据
        for(i=(num_procs-1)*line;i<n;i++) 
        for(j=0;j<n;j++) {
            C[i*n+j]=0;
        for(k=0;k<n;k++)
            C[i*n+j]+=A[i*n+k]*B[k*n+j];
        }
    } else {
        //其他进程接收数据，计算结果，发送给主进程
        MPI_Recv(B,n*n,MPI_DOUBLE,0,0,MPI_COMM_WORLD,&status);
        MPI_Recv(A+(ID-1)*line*n,line*n,MPI_DOUBLE,0,1,MPI_COMM_WORLD,&status);
        for(i=(ID-1)*line;i<ID*line;i++) 
        for(j=0;j<n;j++) {
            C[i*n+j]=0;
        for(k=0;k<n;k++)
            C[i*n+j]+=A[i*n+k]*B[k*n+j];
        }
        MPI_Send(C+(num_procs-1)*line*n,line*n,MPI_DOUBLE,0,2,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    Return 0;
}

