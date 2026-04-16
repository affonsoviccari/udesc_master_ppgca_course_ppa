#include <stdio.h>
#include <omp.h>

int main (void) {
    int id;
    int local = 0;
    int plocal = 100;
    #pragma omp parallel shared(id) private(local) firstprivate(plocal)
    {
        id = omp_get_thread_num();
        printf("UDESC PPA 2026-1 = %d %d %d\n", id, local, plocal);
        plocal++;
    } // join

    return 0;
}