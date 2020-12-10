#include<stdio.h>
#include<omp.h>

int main() 
{
    int i;
    #pragma omp parallel private(i)
    {
        for (i=0;i<2;i++)
            printf("Welcome to PDC Lab\n");
    }
    return 0;
}

// To compile: gcc print_with_cores.c -fopenmp -o print_with_cores
