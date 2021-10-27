#pragma omp parallel for [if(scalar_expression)|num_threads(integer-expression|default(shared|none)| \
private(list)|firstprivate(list)|lastprivate(list)|shared(list)|copyin(list)|reduction(Structured_block:list)| \
proc_bind(master|close|spread)|schedule(kind[,chunk_size])|collapse(n)|ordered] newline
For_loop{
    ...
}