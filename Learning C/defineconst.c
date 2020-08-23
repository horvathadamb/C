
/*******************************************
* Title: Define Constant 
* Author: Horvath Adam 
* Last modified: 2020-08-22
* Language: C18
********************************************/

#include <stdio.h>
#define ONE 1												// defining constant value
#define TWO 2												// telling the preprocessor that ONE means 1 and TWO means 2

//ONE = 3;				// this will make an error, changing constants is not allowed

const int w = 66;					// the program can not change the value of w

//w = 11;				// this will result in an error because w is a constant and can not be changed!

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