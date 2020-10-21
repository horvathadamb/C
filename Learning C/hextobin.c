
/*******************************************
* Title:
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/
#include <stdio.h>
#include <stdint.h>
const char* bit_rep[16] = {
    [0] = "0000",[1] = "0001",[2] = "0010",[3] = "0011",
    [4] = "0100",[5] = "0101",[6] = "0110",[7] = "0111",
    [8] = "1000",[9] = "1001",[10] = "1010",[11] = "1011",
    [12] = "1100",[13] = "1101",[14] = "1110",[15] = "1111",
};

void print_byte(uint8_t byte)
{

    printf("%s%s", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}


int main(void) {
    print_byte(0x10);




    return 0;
}