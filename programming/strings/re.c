#include<stdio.h>
#include<string.h>

int main()
{
	char str[100]="mouneesh is employee";

	for(int i=0;str[i]='\0';i++)
	{
		if(str[i]==" " | str[i]=="\0"){
			str[i]="_";
		}
	}
	for(int i=0;i<strlen(str);i++)
	{
		printf("%c", str[i]);
	}
	return 0;
}
