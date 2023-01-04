#include<stdio.h>
#include<stdlib.h>


void pat(int  i);

int main()
{
   int a;
   printf("Enter the Number: ");
   scanf("%d", &a);
   pat(a);
   return 0;
}
void pat(int n)
{

	for(int i=1;i<n;i++)
	{
		for(int j=i;j<i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
