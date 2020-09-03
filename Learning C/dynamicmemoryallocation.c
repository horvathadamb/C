
/*******************************************
* Title: Dynamic memory allocation 
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/

#include<stdio.h>
#include<stdlib.h>		// for sizeof,malloc


int main() {
	int x = 7, y = 3;
	int* p;									// declaring pointer


	p = (int *)malloc(sizeof(int));			// allocating enough memory for an int size variable
	if (p == NULL) exit(-1);				// checking is the memory is allocated for the pointer othervise error

	*p = x + y;								

	printf("*p=x+y=%d,\n", *p);

	free(p);								// we dont need to use p anymore, freeing the allocated memory used for pointer p


	char a = 'c', b = 'd';
	char* q;

	q = (char *)malloc(sizeof(char));
	if (q == NULL) exit(-1);

	*q = a;

	printf("*q=%c\n", *q);

	free(q);
}