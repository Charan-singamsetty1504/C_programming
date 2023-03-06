#include<stdio.h>


int main()
{
	int a, b;
	int result;
	printf("Enter the first number : \n");
	scanf("%d", &a);
	printf("Enter the Second number : \n");
	scanf("%d", &b);
        while(b!=0)
	{
		unsigned carry = (a&b);
	        result = a ^ b;
		b = carry<<1;
	}
	printf("The adding of two numbers is %d\n", result);
	return 0;
}
