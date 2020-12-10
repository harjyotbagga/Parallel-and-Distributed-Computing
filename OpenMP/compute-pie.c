#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>


double f(double x) 
{
    return 2*sqrt(1-x*x);
}

// Initial Parameters
long int n_rect = INT_MAX;
int threadct = 4;

int main(int argc, char** argv) 
{
    // lower and upper interval endpoints
    double a = -1.0, b = 1.0;  
    // width of a rectangle subinterval
    double h = (b - a)/n_rect; 
    // declare function that defines curve
    double f(double x);         
    // accumulates areas all rectangles so far
    double sum;                 
    long i;                        

    // compute the estimate
    sum = 0;
    #pragma omp parallel for num_threads(threadct) shared (a, n_rect, h) private(i) reduction(+: sum)
    for (i = 0; i < n_rect; i++) 
    {
        sum += f(a + (i+0.5)*h) * h;
    }
    printf("With n = %ld rectangles and %d threads, ", n_rect, threadct);
    printf("the estimate of pi is %.20g\n", sum);
    return 0;
}
