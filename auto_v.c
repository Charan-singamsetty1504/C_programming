#include<stdio.h>


int fun()
{
	int a=10;
	return a;
}
int auto_fun()
{
	auto int b=20;
	return b;
}
int main()
{
      int ans=fun();
      printf("The Normal Function Value is %d\n", ans);
     // int var = auto_fun();
     // printf("This Statement doesn't Execute because the variable given is auto\n");
     return 0;
}

//auto is a storage class, it can be accessed within in the block or the function 
//every variable initially is a auto variable 
//
