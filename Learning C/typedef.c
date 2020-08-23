
/*******************************************
* Title:
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/

#include<stdio.h>

typedef volatile unsigned long int mytype;					// using mytype will be the same as volatile unsigned long int in declaration

mytype bignumber = 83E3;			// this is a volatile unsigned long int, volatile means it can change (like hardware input changing in time, or an interrupt)

int main() {
	printf("%d \n", bignumber);
}