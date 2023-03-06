#include<stdio.h>

int main()
{
  int a;
 unsigned int  count=0;
  printf("Enter the number :\n");
  scanf("%d", &a);
  while(a)
  {
	 count += a&1;
	 a>>=1;
  }
  printf("The total bits in the given number is %d\n", count);
  return 0;
}
