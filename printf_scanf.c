
/*******************************************
* C language tutorial printf,scanf
* Author: Horvath Adam
* Last modified: 2020-08-22
********************************************/




#include <stdio.h>		// printf scanf
#include <stdlib.h>		// exit
#include <conio.h>		// getch
#include <string.h>		// strspn 







void print(void);						// declaration has to be BEFORE main function.
void sum(void);
void inputsum(void);
void scanfcheck(void);
void infiniteinputsum(void);
void wronginputcontinue(void);
void wronginputcontinuestring(void);
void inputerrorcheck(void);

void detailedinputcheck(void);
int errorpos(char*);

void inputcheckstrspn(void);


int main(void) {

	//print();								// text output
	//sum();								// output is the sum of a and b
	//scanfcheck();							// checking if the user wrote the input correctly or not
	//infiniteinputsum();					// endless loop with press space to exit (wrong input exit)
	//wronginputcontinue();					// endless loop scan with press space to exit (wrong input continue)
	//wronginputcontinuestring();			// loop with string scan
	//inputerrorcheck();					// input check loop with checking wich input is wrong and detecting it
	//detailedinputcheck();					// checking wich input is incorrect and then showing it
	//inputcheckstrspn();					// same as detailedinputcheck but with strspn built in function
	return 0;
}


void print(void) {
	printf("C languague\n");
	printf("The sum of two numbers: %d + %d = %d\n", 7, 10, 7 + 10);
}

void sum(void) {
	int a, b, c;
	a = 5;
	b = 7;
	c = a + b;
	printf("The sum of two numbers: a=%d b=%d c=a+b then c=%d\n", a, b, c);
}

void inputsum(void) {
	int a, b, c;
	printf("Write two numbers comma separated: ");
	scanf_s("%d,%d", &a, &b);										//if input is goingto be: "5,5" then a=5 b=5
	c = a + b;
	printf("The sum of two numbers: %d\n", c);
}

void scanfcheck(void) {
	int a, b, c;
	printf("Write two numbers comma separated: ");
	if (scanf_s("%d,%d", &a, &b) != 2) {					// the return value of scanf will be the amount of numbers stored
		printf("Incorrect input!\n");						// if the input isn't 2 numbers we exit the program		
		fflush(stdin);					// flush the scanf input puffer values. Without this they keep the same value until next scanf!
		exit(-1);											// exit with error
	}
	c = a + b;
	printf("The sum of two numbers: %d\n", c);
}

void infiniteinputsum(void) {
	int a, b, c;
	do {														// endless loop for the input and sum function
		printf("Write two numbers comma separated: ");
		if (scanf_s("%d,%d", &a, &b) != 2) {					// the return value of scanf will be the amount of numbers stored
			printf("Incorrect input!\n");						// if the input isn't 2 numbers we exit the program		
			fflush(stdin);				// flush the scanf input puffer values. Without this they keep the same value until next scanf!
			exit(-1);
		}
		c = a + b;
		printf("The sum of two numbers: %d + %d = %d \npress SPACE to exit!\npress any button to continue!\n", a, b, c);
	} while (_getch() != 32);									// endless loop until the space (character number 32) is pressed
}

void wronginputcontinue(void) {
	int a, b, c;
	do {														// endless loop for the input and sum function
		printf("Write two numbers comma separated: ");
		if (scanf_s("%d,%d", &a, &b) != 2) {					// the return value of scanf will be the amount of numbers stored
			printf("Incorrect input! Press any button to continue or press SPACE to exit!\n");// if the input isn't 2 numbers we exit the program		
			//fflush(stdin);				// flush the scanf input puffer values. Without this they keep the same value until next scanf!
			rewind(stdin);					//fflush(stdin) not working properly in visual studio using rewind for same purpose
			continue;
		}
		c = a + b;
		printf("The sum of two numbers: %d + %d = %d \npress SPACE to exit or press any button to continue!\n", a, b, c);
	} while (_getch() != 32);									// endless loop until the space (character number 32) is pressed

}


void wronginputcontinuestring(void) {													// same as before but now we store the string data in an array	
	int a, b, c;
	char str[160] = { 0 };
	do {
		printf("Write two numbers comma separated, then press ENTER!\n");
		gets(str);																								// storing input
		if (sscanf_s(str, "%d,%d", &a, &b) != 2) {																// scanning string data
			printf("Incorrect input! Press SPACE to exit, or press any other button to continue!\n");
			continue;																							// new iteratoin in do loop
		}
		c = a + b;
		printf("The sum of two numbers: %d+%d=%d! Press SPACE to exit, or any other button to continue!\n", a, b, c);
	} while (_getch() != 32);
}

void inputerrorcheck(void) {
	int a, b, c;
	char str[160] = { 0 };
	do {
		printf("Write two nubers comma separated, then press enter!\n");
		gets(str);
		if (str[0] == 0) {																						//empty input check
			printf("No input detected! Press Space to exit, or any other button to continue!\n");
			continue;
		}
		switch (sscanf_s(str, "%d,%d", &a, &b)) {																// checking wich input is incorrect 
		case 0:
			printf("First input is incorrect! Press Space to exit, or any other button to continue!\n");	// frist input incorrect
			break;

		case 1:
			printf("Second input is incorrect! Press Space to exit, or any other button to continue!\n");	// second incorrect
			break;
		default:																							// otherwise calculate the sum
			c = a + b;
			printf("The sum of two numbers: %d+%d=%d! Press Space to exit, or any other button to continue!\n", a, b, c);
		}
	} while (_getch() != 32);
}

int errorpos(char* p) {														// checking which input character is invalid
	static char allowedcharacters[] = "0123456789+-, ";
	int i, j, ok;
	for (i = 0; p[i]; i++)
	{																		// cycle for running through every input
		ok = 0;
		for (j = 0; allowedcharacters[j]; j++) {								// checking if the input is the same as the allowed character
			if (p[i] == allowedcharacters[j]) {
				ok = 1;
			}

		}
		if (ok == 0) return i;												// if not return the position of the wrong input character
	}
	return -1;																// if every character is allowed then return -1
}

void detailedinputcheck(void) {
	int a, b, c, pos;
	char str[160] = { 0 };

	do {
		printf("Write two numbers comma separated, then press Enter!\n");
		gets(str);
		if (str[0] == 0) {
			printf("No input! Press SPACE to exit, or any other button to continue!\n");		//checking for empty input
			continue;
		}
		pos = errorpos(str);																	// calculating wrong character position
		if (pos != -1) {
			printf("Wrong input!The first wrong input character is:\n");
			printf("%s\n", str);
			printf("%*c\n", pos + 1, '^');														//showing wich is the wrong character
			printf("Press SPACE to exit, or any other button to continue!\n");
			continue;
		}
		switch (sscanf_s(str, "%d,%d", &a, &b)) {
		case 0:
			printf("The first input is incorrect!\n");
			break;
		case 1:
			printf("The second input is incorrect!\n");
			break;
		default:
			c = a + b;
			printf("The sum of two numbers: %d+%d=%d! Press SPACE to exit, or any other button to continue!\n", a, b, c);
			break;

		}

	} while (_getch() != 32);
}

void inputcheckstrspn(void) {
	int a, b, c, pos;
	char str[160] = { 0 };
	do {
		printf("Write two numbers comma separated, then press ENTER!\n");
		gets(str);
		if (str[0] == 0) {
			printf("Empty input, press SPACE to exit, or any other button to Continue!\n");
			continue;
		}
		pos = strspn(str, "0123456789+-, ");						// string compare, if there is a mismatch returns the position of the input
		if (pos != strlen(str)) {								// if there is no mismatch between the two strings it returns the lenght of
			printf("Wrong input!\n");							// the input string "str"
			printf("%s\n", str);
			printf("%*c\n", pos + 1, '^');
			continue;
		}
		switch (sscanf_s(str, "%d,%d", &a, &b)) {
		case 0:
			printf("First input is incorrect!\n");
			break;
		case 1:
			printf("Second input is incorrect!\n");
			break;
		default:
			c = a + b;
			printf("The sum of two numbers: %d+%d=%d! Press SPACE to exit, or any other button to Continue!\n", a, b, c);
			break;
		}
	} while (_getch() != 32);

}