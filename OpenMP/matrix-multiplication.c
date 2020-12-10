#include <omp.h> 
#include <stdio.h> 
#include <stdlib.h> 

#define no_of_rows_A 3                 
#define no_of_cols_A 3                 
#define no_of_cols_B 3                 



int main (int argc, char *argv[])  
{ 
    int tid, nthreads, i, j, k, chunk_size; 
    double a[no_of_rows_A][no_of_cols_A], b[no_of_cols_A][no_of_cols_B], c[no_of_rows_A][no_of_cols_B];  
    chunk_size = 10;              

    #pragma omp parallel shared(a,b,c,nthreads,chunk_size) private(tid,i,j,k) 
    { 
        tid = omp_get_thread_num(); 
        if (tid == 0) 
        { 
        nthreads = omp_get_num_threads(); 
        printf("Starting matrix multiple example with %d threads\n",nthreads); 
        printf("Initializing matrices...\n"); 
    } 


    #pragma omp for schedule (static, chunk_size)  
        for (i=0; i<no_of_rows_A; i++) 
            for (j=0; j<no_of_cols_A; j++) 
                a[i][j]= i+j; 

    #pragma omp for schedule (static, chunk_size) 
        for (i=0; i<no_of_cols_A; i++) 
            for (j=0; j<no_of_cols_B; j++) 
                b[i][j]= i*j; 

    #pragma omp for schedule (static, chunk_size) 
        for (i=0; i<no_of_rows_A; i++) 
            for (j=0; j<no_of_cols_B; j++) 
                c[i][j]= 0; 

    printf("Thread %d starting matrix multiply...\n",tid); 

    #pragma omp for schedule (static, chunk_size) 
        for (i=0; i<no_of_rows_A; i++)     
        { 
            printf("Thread=%d did row=%d\n",tid,i); 
            for(j=0; j<no_of_cols_B; j++)        
                for (k=0; k<no_of_cols_A; k++) 
                    c[i][j] += a[i][k] * b[k][j]; 
        } 
    }   

    printf("Result Matrix:\n"); 
    for (i=0; i<no_of_rows_A; i++) 
    { 
        for (j=0; j<no_of_cols_B; j++)  
            printf("%6.2f   ", c[i][j]); 
        printf("\n");  
    } 

    printf ("Completed.\n"); 
} 

