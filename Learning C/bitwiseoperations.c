
/*******************************************
* Title: Bit masking
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/


#include<stdio.h>
#include<math.h>

int bitset(int,int);
int bitreset(int, int);
int bitxor(int, int);
int bitswitch(int, int);
int bitshift(int, int,int);
int showbyte(void);



int main() {
		
	bitset(1994, 0x1020);						//	Setting the bit is just bitwise or "|" with number 1 in the proper bit position
												//  In the example we set bit 5 and 12 (starting from 0 from right to left)
												//	  0000 0111 1100 1010 = 1994
												//	| 0001 0000 0010 0000 = 0x1020  mask with number "1" in 5. and 12. bit
												//	  0001 0111 1110 1010 = 0x17EA

	bitreset(1994, 0xFBF7);						// Resetting the bit is just bitwise and "&" with number 0 in the proper bit position
												// In the example we reset bit 10 and 3
												//    0000 0111 1100 1010 = 1994
												//  & 1111 1011 1111 0111 = 0xFBF7 mask with number "0" in 10. and 3. bit
												//    0000 0011 1100 0010 = 0x03C2

	bitxor(1994, 0x8421);						//  Xor output is only 1 if only one number is 1
												//  writing number 1 in mask will invert the corresponging bit value.
												//  Lets invert bit 0,5,10,14. To do that write number 1 in mask bit 0,5,10,14
												//  0000 0111 1100 1010 = 0x07CA
												// ^1000 0100 0010 0001 = 0x0842 mask
												// =1000 0011 1110 1011 = 0x83EB

	bitswitch(25000, 20000);					// switching 2 register bit values without 3. container

	bitshift(1994, 1,2);						// Bitshift left operation equals to multiplying by 2^n, right is dividing by 2^n.
												// shifting number 1994 or 0x07CA left 1 times:
												// 0000 0111 1100 1010  =0x07CA or 1994
												// 0000 1111 1001 0100  = 0x07CA<< 1 =3988 (1994*2)
												// Bitshift right number 1994 right 2 times:
												// 0000 0111 1100 1010 = 0x07CA or 1994 
												// 0000 0001 1111 0010 = 0x07CA >> 2 = 498 (1994/ 2^2)

	showbyte();									// show the upper and lower byte of the input number


}



int bitset(int inputnumber, int mask) {
	int bitsetoutput;
	bitsetoutput = inputnumber | mask;
	printf("Bitset operation output:\ninput value=%X or %d\nmask value=%X or %d\noutput value=%X\ or %d\n\n",inputnumber,inputnumber,mask,mask,bitsetoutput,bitsetoutput);

	return bitsetoutput;
}

int bitreset(int inputnumber, int mask) {
	int bitresetoutput;
	bitresetoutput = inputnumber & mask;
	printf("Bitreset operation output:\ninput value=%X or %d\nmask value=%X or %d\noutput value=%X\ or %d\n\n", inputnumber, inputnumber, mask, mask, bitresetoutput, bitresetoutput);
}

int bitxor(int inputnumber, int mask) {
	int bitxoroutput, bitxoragain;
	bitxoroutput = inputnumber ^ mask;
	bitxoragain = bitxoroutput ^ mask;

	printf("Bitwise XOR operation output:\ninput value=%X or %d\nmask value=%X or %d\noutput value=%X or %d\nXor again gives back the original value=%X or %d\n\n", inputnumber, inputnumber, mask, mask, bitxoroutput, bitxoroutput,bitxoragain,bitxoragain);
}

int bitswitch(int firstinput, int secondinput) {
	printf("Switching operation: \nBefore switch first value=%d, second value=%d\n",firstinput,secondinput);
	firstinput = firstinput ^ secondinput;
	secondinput = secondinput ^ firstinput;
	firstinput = firstinput ^ secondinput;

	printf("After switch first value=%d, second value=%d\n\n", firstinput, secondinput);
	
}

int bitshift(int inputnumber, int shiftnumber1,int shiftnumber2) {
	int output;
	printf("Bitshift operation: \ninputnumber=%d or %X, shiftnumber1=%d shiftnumber2=%d\n", inputnumber,inputnumber, shiftnumber1,shiftnumber2);
	output = inputnumber << shiftnumber1;
	printf("Shifting number %X left %d times: %X<<%d=%X or %d\n", inputnumber, shiftnumber1, inputnumber,shiftnumber1, output,output);
	output = inputnumber >> shiftnumber2;
	printf("Shifting number %X right %d times: %X<<%d=%X or %d\n\n", inputnumber, shiftnumber2, inputnumber, shiftnumber2, output, output);
}

int showbyte(void) {
	int input;
	int lowerbyte,upperbyte;
	
	
	
	printf("Write an integer: \n");
	scanf_s("%d", &input);
	printf("Your number in hexadecimal form: %X \n", input);

	if (input > pow(2,16) ){
		printf("Too big number, please use a 16bit number!\n");
		return 0;
	}

	lowerbyte = input & 0x00FF;
	printf("The lower byte of your number is: %X \n", lowerbyte);
	
	upperbyte= input >> 8;
	printf("The upperbyte of your number is: %X \n", upperbyte);


}