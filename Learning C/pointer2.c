
/*******************************************
* Title: Void pointers and casting
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/


#include<stdio.h>



int main(void) {
	int x;
	void* ptr = &x;						// void type pointer

	*(int*)ptr = 5;						// casting. Typeconversion to assign value to x

	printf("x=%d\n", x);

	int y;
	int* p;              // assigning int pointer type to p
	int** q;			// assigning a pointer wich is pointing to an int pointer

	y = 7;					
	p = &y;					// p is going to point to the adress of y
	q = &p;					// q is going to point to the adress of p
							// meaning q poins to p, and p points to y

	y = y + *p + **q;         // y = 7 + 7 + 7=21

	printf("y=%d\n", y); // printing

}