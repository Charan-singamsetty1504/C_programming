#include<stdio.h>


int main()
{
	int n;
	printf("Enter the number \n");
	scanf("%d", &n);
        n = n&1;
       if(n==0)
       {
         printf("The given number is even \n");
       }else
       {
	printf("The given number is odd \n");
       }
return 0;
}
