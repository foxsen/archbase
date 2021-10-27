#pragma omp parallel sections [if(scalar_expression)|num_threads(integer-expression)| \
default(shared|none)|private(list)|firstprivate(list)|lastprivate(list)|shared(list)| \
copyin(list)|reduction(Structured_block:list)|proc_bind(master|close|spread)]
{
    [#progma omp section newline]
        Structured_block
    [#progma omp section newline
        Structured_block]
    ......
}