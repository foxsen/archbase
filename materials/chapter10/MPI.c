#include "mpi.h"
int main(int argc,char *argv[])
{  int myid,count;
   MPI_Init(&agrc,&argv); /*启动计算*/
   MPI_Comm_size(MPI_COMM_WORLD,&count); /*获得进程总数*/
   MPI_Comm_rank(MPI_COMM_WORLD, &myid);/*获得自己进程号*/
   printf("I am %d of %d\n", myid,count);  /*打印消息*/
   MPI_Finalize();/*结束计算*/
}