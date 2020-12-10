#include<stdio.h>
#include<omp.h>

int main()
{
  int n=5;
  int x[n],y[n];
  int product=1;
  for(int i=0;i<n;++i)
  {
    printf("Enter the value for %d value of x vector:",i);
    scanf("%d",&x[i]);
    printf("Enter the value for %d value of y vector:",i);
    scanf("%d",&y[i]);
  }
  
  #pragma omp parallel for reduction(*:product)
  for(int i=0;i<n;++i)
    product=product*(x[i]+y[i]);
  printf("Product: %d\n",product);
}