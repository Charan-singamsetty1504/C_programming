#include<stdio.h>


int main()
{
	int n, mask;
	printf("Enter the Number: \n");
	scanf("%d", &n);
	mask = n-1;
	if(n&mask==0)
	{
	printf("It is the power of 2 \n");
	} 
	else {
		printf("It is not the power of 2\n");
		}
			return 0;
}	
