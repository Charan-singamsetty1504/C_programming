#include<linnux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

int value, valuet[4];

char *name;

int valuen = 0;

module_param(valuet, int, S_IRUSR|S_IWUSR);
module_param(name, char
