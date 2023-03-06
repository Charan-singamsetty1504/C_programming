#include<stdio.h>
#define size_of(var) ((char *)(&var+1)-(char *)(&var))

int main()
{
	int a[] = {1, 2, 3, 4};
	int ans = size_of(a)/size_of(a[0]);
	int first = a[0];
	printf("The size of the given array is: %d\n", ans);
	printf("The Size of the First element in the array is: %d\n", a[0]);//first);
	printf("The Size is %d\n", sizeof(a[0]));

	return 0;


}

