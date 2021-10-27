#include <alloca.h>

extern long 
nested(long a, long b, long c, long d, long e, long f, long g, long h, long i); 

long dynamic(void){
    long *p = alloca(64);
    p[0] = 0x123;

    return nested((long)p, p[0], 3, 4, 5, 6, 7, 8, 9);
}
