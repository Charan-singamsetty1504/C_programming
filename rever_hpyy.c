#include<stdio.h>

void pat(int n);

int main()
{
 	int a;
   printf("Enter the number for pattern: \n");
   scanf("%d", &a);
   for(int i=0;i<=a;i++)
   {
   for(int j=i;j<a;j++)
   {
   	printf("*");
   }
   printf("\n");
}
   return 0;
}