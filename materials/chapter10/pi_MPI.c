#include <stdio.h>
#include “mpi.h”
int main(int argc, char **argv){
    int num_steps=1000000;
    double x,pi,step,sum,sumallprocs;
    int  i,start, end,temp;
    int ID,num_procs;//进程编号及组中的进程数量, 进程编号的范围为0到num_procs-1
    MPI_Status status;
    //Initialize the MPI environment
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&ID);//
    MPI_Comm_size(MPI_COMM_WORLD,&num_procs);
    //任务划分并计算
    step = 1.0/num_steps;
    start = ID *(num_steps/num_procs) ;

    if (ID == num_procs-1)
        end = num_steps;
    else
        end = start + num_steps/num_procs;

    for(i=start; i<end;i++) {
        x=(i+0.5)*step;
        sum += 4.0/(1.0+x*x);
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&sum,&sumallprocs,1,MPI_DOUBLE,MPI_SUM,0, MPI_COMM_WORLD);

    if(ID==0) {
        pi = sumallprocs*step;
        printf("pi %1f\n", pi);
    }
    
    MPI_Finalize();
    return 0;
}