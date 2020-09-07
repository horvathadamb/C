
/*******************************************
* Title: Bit masking
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/


#include<stdio.h>

int bitset(int,int);
int bitreset(int, int);
int bitxor(int, int);

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

	bitxor(1994, 0x8421);						// 
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

	printf("Bitwise XOR operation output:\ninput value=%X or %d\nmask value=%X or %d\noutput value=%X\ or %d\nXor again with mask gets you the original value= %X or %d\n\n", inputnumber, inputnumber, mask, mask, bitxoroutput, bitxoroutput,bitxoragain,bitxoragain);
}