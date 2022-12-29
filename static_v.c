#include<stdio.h>


int main()
{
	static int a=10;
	static int b;
	printf("The Static Variable with a Value is: %d\n", a);
	printf("The Default static value is %d\n", b); 
	return 0;

}

//static is a storage class, in which if we define a variable as a static that variable 
//can be used in any part of functions in the program
//the default value of the static is 0
