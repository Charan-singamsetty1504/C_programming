#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	float value;
};

int main()
{
	struct node obj;
	obj.data=4;
	obj.value=3.4;
	printf("%d", obj.data);
	printf("%d", obj.value);
	return 0;
	
	)