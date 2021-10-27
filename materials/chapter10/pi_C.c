#include <stdio.h>
#include <math.h>
int main(){
    int i;
    int num_steps=1000000;
    double x,pi,step,sum=0.0;
    step = 1.0/(double) num_steps;

    for(i=0;i<num_steps;i++){  
        x=(i+0.5)*step;
        sum = sum+4.0/(1.0+x*x);
    }

    pi = step*sum;
    printf("pi %1f\n", pi);
    return 0;
}

