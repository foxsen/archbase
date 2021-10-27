extern void abort(void);
int fun(double a1, double a2, double a3, double a4, double a5, double a6,       
        double a7, double a8, double a9, int a10, double a11, int a12)
{
    if (a9 != a11) abort();
    return 0;
}

