#include<stdio.h>


int main()
{
	int a, b;
	printf("Enter the Number to clear\n");
	scanf("%d", &a);
	printf("Enter the position to clear \n");
	scanf("%d", &b);
	a=a&(~(1<<(b-1)));
	printf("The Value after clearing is %d\n", a);
	return 0;
}
