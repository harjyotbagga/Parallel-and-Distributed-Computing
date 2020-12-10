#include<stdlib.h>
#include<stdio.h>
#include<omp.h>

#define ARRAY_SIZE 8
#define NUM_THREADS 4

int main() 
{
    int a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE];
    printf("Enter elements of Vector A: \n");
    
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n");
    printf("Enter elements of Vector B: \n");
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("\n");

    omp_set_num_threads(NUM_THREADS);
    int n_per_thread = ARRAY_SIZE / NUM_THREADS;
    int i;
    #pragma omp parallel for shared(a,b,c) private(i) schedule(static, n_per_thread)
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        c[i] = a[i] + b[i];
        printf("Thread %d workds on element %d.\n", omp_get_thread_num(), i);
    }

    printf("i\ta[i]\tb[i]\tc[i]\n");
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, a[i], b[i], c[i]);
    }
    return 0;
}