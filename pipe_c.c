#include<stdio.h>
#include<unistd.h>
#define M 16

char *msg1="Hello, World #1";
char *msg2="Hello, World #2";
char *msg3="Hello, World #3";


int main()
{
	char inbuf[M];
	int p[2], i;
	if(pipe(p)<0)
	{
		exit(1);
	}

	write(p[1], msg1, M);
	write(p[1], msg2, M);
	write(p[1], msg3, M);

	for(i=0;i<3;i++)
	{
		read(p[0], inbuf, M);
		printf("%s\n", inbuf);
	}
	return 0;
}
