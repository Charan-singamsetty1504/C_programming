#include<stdio.h>


int func()
{
	int a=10; //Can be Accessed in any function throughout the program
	return a;
}
void fun2()
{
	auto int var=20; //can't be accessed for the calling because of the auto keyword
}
int main()
{
       int some_var=func();
	printf("The Normal Variable is %d\n", some_var);
 //	fun2(); commented because it gives error
//	printf("The Auto Variable is %d\n", var); 
	return 0;
}
//auto is a storage class in which it can be used within the block or the function 
//initially it is normal variable is declared as a automatic 
