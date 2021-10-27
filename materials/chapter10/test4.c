If(mypid==0) {
    MPI_Bcast(buf0,count,type,0,comm,ierr);
    MPI_Send(buf1,count,type,1,tag,comm,ierr);
} else {
    MPI_Recv(buf1,count,type,0,tag,comm,ierr);
    MPI_Bcast(buf0,count,type,0,comm,ierr);
}
