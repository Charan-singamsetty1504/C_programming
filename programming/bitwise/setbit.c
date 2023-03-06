#include<stdio.h>
int main()
{
	int a, b;
	printf("Enter the number to set : \n");
	scanf("%d", &a);
	printf("Enter the number position to set: \n");
	scanf("%d", &b);
	a = a | (1<<(b-1));
        printf("The value after setting is %d\n", a);
	return 0;
}
