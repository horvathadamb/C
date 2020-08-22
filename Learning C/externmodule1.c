
/*******************************************
* Title: External module function call
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/

#include<stdio.h>
#define ONE 1
#define TWO 2



extern int sum(int, int);		  // defined in the module externmodule2
int e;

int main() {
	int a, b;
	a = ONE;
	b = TWO;
	e = sum(a, b);
	printf("The sum of two numbers: %d+%d=%d!\n", a, b, e);
}