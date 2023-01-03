#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

//fork is a system call which is used to create new process, and 
//runs concurrently along with the parent process as a child process
//it takes no parameters and returns an integer value
//Negative Value - creation of child process was unsuccessful
//Zero - returns to newly created child process
//positive value - return to the parent or caller, The value contains the process ID

int main()
{
	fork();
	printf("Hello, World!!\n");
	return 0;
}
