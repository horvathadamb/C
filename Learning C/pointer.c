
/*******************************************
* Title: Pointers
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/

#include<stdio.h>	



int main() {
	int x = 7, y = 3;
	int *p;											// declaring the pointer p, it allocates memory for p,  it has adress but has no value yet!
	p = &x;											// p is going to point to the adress of x, so using p is going to mean x
													// always make sure pointer is assigned to something before using it!!	
	*p = *p + x + y;								// "*" before the p means we are using the values of "p" not the adress. "p" points to the adress of x, and the value of x (=*p) is 7.
													// "*p" or value of p is x+x+y=7+7+3=17  so *p=x=17
	printf("*p=x=%d\n",x);


	p = &y;											// now p is going to point to y, using p will mean adress of y
	*p = x + y;										// value of p (*p) is going to be x+y=17+3=20 so *p=y=20
	printf("*p=y=%d\n", y);
	*p = x + y + *p;								// value of p pointer is going to be x+y+y=17+20+20=57
	printf("*p=y=%d\n",y);							// printing y



	int v;
	void* ptr = &v;						// void type pointer
	*(int*)ptr = 5;						// casting. Typeconversion to assign value to x
	printf("x=%d\n", v);




	int z;
	int* q;              // assigning int pointer type to p
	int** r;			// assigning an int pointer wich is pointing to an int pointer

	z = 7;
	q = &z;					// q is going to point to the adress of z
	r = &q;					// r is going to point to the adress of q
							// meaning r poins to q and q points to z, so r basically r points to z

	z = z + *q + **r;         // z = 7 + 7 + 7=21

	printf("z=%d\n", z); // printing
}
