#include<stdio.h>


int main()
{
	int a, b, carry, output;
	printf("Enter the numbers : \n");
	scanf("%d%d", &a, &b);
	while(b!=0)
	{
		carry = a&b;
		a = a^b;
		b = carry<<1;
	}
	printf("The Adding of two numbers is %d\n", a);
	return 0;
}
