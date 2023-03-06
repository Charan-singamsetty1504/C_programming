#include<stdio.h>


int main()
{
	int n;
	printf("Enter the Number: \n");
	scanf("%d", &n);
	if((n&0xAAAAAAAA)==0)
	{
		printf("Number is power of four\n");
	}else
	{
		printf("Number is not a power of four\n");
	}
	return 0;
}
