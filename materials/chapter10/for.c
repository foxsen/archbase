#pragma omp for [private(list)| firstprivate(list)|lastprivate(list)| \
reduction(reduction-identifier:list)|schedule(kind[,chunk_size])|collapse(n)|ordered| nowait] newline
