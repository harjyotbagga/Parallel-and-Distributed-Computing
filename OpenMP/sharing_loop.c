#include<stdio.h>
#include<omp.h>

#define n 10
#define chunksize 10

int main()
{
  int threads,id,i;
  float u[n], v[n], w[n];
  int chunk=chunksize;
  
  for(i=0;i<n;++i)
  {
    u[i]=v[i]=(i*2.0);
  }
  
  #pragma omp parallel shared(u,v,w,threads,chunk) private(i,id)
  {
    id=omp_get_thread_num();
    if(id==0)
    {
      threads=omp_get_num_threads();
      printf("No. of threads=%d\n",threads);
    }
    
    printf("Thread %d starting\n",id);
    
    #pragma omp for schedule(dynamic,chunk)
    for(i=0;i<n;++i)
    {
      w[i]=u[i]+v[i];
      printf("Thread %d: w[%d]=%lf\n",id,i,w[i]);
    }
  }
}    