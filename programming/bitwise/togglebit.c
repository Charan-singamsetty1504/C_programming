#include<stdio.h>


int main()
{
	int a, b;
	printf("Enter the Numbers: \n");
	scanf("%d", &a);
	scanf("%d", &b);
        a=a^(1<<b);
	printf("The Toggling bits are %d\n", a);
	return 0;
}
