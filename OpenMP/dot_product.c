#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<omp.h>

#define size 4

int main() 
{
    float u[size], v[size], prod=0, final_prod=0;
    int i, thread_id;
    printf("\nEnter value of Vector u:\n");
    for (i=0; i<size; i++)
    {
        printf("Enter u[%d]: ", i);
        scanf("%f", &u[i]);
    }
    printf("\nEnter value of Vector v:\n");
    for (int i=0; i<size; i++)
    {
        printf("Enter v[%d]: ", i);
        scanf("%f", &v[i]);
    }
    #pragma omp parallel shared(u,v, prod, final_prod) private(i, thread_id)
    {
        thread_id = omp_get_thread_num();
        #pragma omp for private(i)
        for(i=0; i<size; i++)
        {
            prod+=u[i]*v[i];
            printf("Thread in use: %d\n", thread_id);
        }
        #pragma omp critical
        {
            final_prod = prod;
            printf("Thread in use: %d\n", thread_id);
        }
    }
    printf("\nDot product of the 2 vectors is %f\n", final_prod);
}