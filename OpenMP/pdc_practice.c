#include<stdio.h>
#include<omp.h>

int main() 
{
    
    int a[10], i, n=10, sum=0;    
    for(i=0;i<n;i++)    
    {
        printf("Enter the Element A[%d]: ", i+1);   
        scanf("%d",&a[i]);
    }

    printf("\n Sum: %d",sum);
    #pragma omp parallel for reduction (+:sum)
    for (i=0;i<n;i++)
        sum=sum+a[i];
    printf("%d",sum);
    return 0;
}

// To compile: gcc print_with_cores.c -fopenmp -o print_with_cores
