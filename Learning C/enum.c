
/*******************************************
* Title:
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/

#include<stdio.h>

enum colors {white,red=10,black};		// enum makes a list constants, int only

//enum {white,red=10,black};  // this works as well dont need to name it

int main() {
	int a,b=0;
	a = white;
	b = red + black;
	
	printf("white = %d \n red = %d \n black = %d \n a = %d\n b = %d+%d =%d\n", white, red, black, a,red,black,b );

}