#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main()
{
    omp_set_num_threads(5);
    printf("\nThe no. of threads received: %d",omp_get_num_threads());
    printf("\nThe no. of processors outside parallel: %d",omp_get_num_procs());
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        if(ID == 0)
        {
            printf("\nThe no. of threads in parallel region: %d",omp_get_num_threads());
            printf("\nThe no. of processors inside parallel is: %d",omp_get_num_procs());
        }
        if(ID == 1)
        {
        printf("\nThe dynamic runtime adjustment is %s",omp_get_dynamic() ? "true" : "false");
        }
        if(ID == 2)
        {
            printf("\nThe nested parallelism adjustment is %s",omp_get_nested() ? "true" : "false");
        }
    }
    printf("\n");
    return 0;
}