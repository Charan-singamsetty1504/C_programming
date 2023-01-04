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

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
