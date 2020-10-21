
/*******************************************
* Title:
* Author: Horvath Adam 
* Last modified: 
* Language: C18
********************************************/
#include <stdio.h>



unsigned long char_to_bin10(char ch) {
    unsigned char uch = ch;
    unsigned long sum = 0;
    unsigned long power = 1;
    while (uch) {
        if (uch & 1) {
            sum += power;
        }
        power *= 10;
        uch /= 2;
    }
    return sum;
}


int main(void) {
    int mask = 0x00;
   
    printf("%08lu\n", (char_to_bin10(145) | mask));



    return 0;
}