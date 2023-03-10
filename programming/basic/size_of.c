#include<stdio.h>
#define size_of(type) (char*)(&type+1)-(char*)(&type) //taking the address of the variable and incrementing,
                                           //making substract with first address of that variable
int main()
{
    double a;
    printf("Enter the number to check size: \n");
    scanf("%ld", &a);
    printf("The size of given variable is %d\n", size_of(a));
    return 0;
}
