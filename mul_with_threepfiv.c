#include<stdio.h>

void mul(int n);


int main()
{
	int n;
	printf("Enter the Number: ");
	scanf("%d", &n);
        mul(n);
	return 0;
}

void mul(int n)
{
	int ans = (n<<1)+n+(n>>1);
	printf("%d\n", ans);
}
