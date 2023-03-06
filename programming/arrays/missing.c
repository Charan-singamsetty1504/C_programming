#include<stdio.h>

int main()
{
	int size, avg, ans;
	printf("Enter the Number: \n");
	scanf("%d", &size);
 	int a[size];
	printf("Enter the Elements in array: \n");
	for(int i=0;i<size;i++)
	{
	scanf("%d", &a[i]);
	}
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			ans = a[i]+a[j]/j+1;
			if(a[i]>0)
			a[i]=a[j];

		}
			printf("%d\n", a[i]);
	}
	return 0;
}	

