#include <omp.h>
main(){
int var1,var2,var3;
   …
#pragma omp parallel private(var1,var2)  shared(var3)
    {
        …
    } 
   …
}
