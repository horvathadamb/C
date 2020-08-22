
/*******************************************
* Title: Define Constant 
* Author: Horvath Adam 
* Last modified: 2020-08-22
* Language: C18
********************************************/

#include <stdio.h>
#define ONE 1												// telling the preprocessor that ONE means 1 and TWO means 2
#define TWO 2												

int sum(int, int);
int e;

int main() {
	int a = ONE;
	int b = TWO;
	e = sum(a, b);
	printf("The sum of two numbers: %d+%d=%d!\n", a, b, e);

}

int sum(int x, int y) {
	int c;
	c = x + y;
	return c;
}