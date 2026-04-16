#include <stdio.h>
#include <omp.h>

int main (void) {
    int id;
    
    #pragma omp parallel shared(id)
    {
        int tnum;
        tnum = omp_get_num_threads();
        id = omp_get_thread_num();
        printf("UDESC PPA 2026-1 = %d\n", id);

        #pragma omp master
        printf("thread master = %d\n", id);
        #pragma omp single
        printf("thread single = %d\n", id);
        #pragma omp critical
        printf("thread critical = %d\n", id);
    } // join

    return 0;
}