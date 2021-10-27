#pragma omp sections [private(list) |firstprivate(list)| \
lastprivate(list)|reduction(reduction-identifier:list)|nowait] newline
{
    [#pragma omp section newline]
        Structured_block
    [#pragma omp section newline
        Structured_block]
}