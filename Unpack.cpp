//Author: Frank Su 001411435
#include <stdio.h>

//function prototype
void unpackCharacters(unsigned int value);
void displayBits(unsigned int value);

int main(){
	unsigned int x;
	puts("This program will unpack an unsigned integer into two characters and print them out as bits:\n");
	printf("Enter the unsigned integer to unpack: ");
	scanf_s("%u", &x);
	printf("%u%s\n", x, " printed out in bits before unpacking is:");
	displayBits(x);
	puts("");
	puts("After unpacking, the two two resulting characters are: \n\n");
	unpackCharacters(x);
}

//function to print number in bits
void displayBits(unsigned int value) {
	//define mask and left shift 31 bits
	unsigned int mask = 1 << 31;
	//loop through bits
	for (unsigned int c = 1; c <= 32; c++) {
		putchar(value & mask ? '1' : '0');
		value <<= 1; //shift value left by 1
		if (c % 8 == 0) {
			putchar(' ');
		}
	}
	putchar('\n');
}

//function to unpack unsigned integer
void unpackCharacters(unsigned int value) {
	//initialize mask variables
	unsigned int mask1 = 65280;
	unsigned int mask2 = 255;
	//perform listed operations and store results in 2 char variables
	char a = (value & mask1) >> 8;
	char b = (value & mask2);
	printf("'%c' in bits as an unsigned integer is:\n", a);
	printf("%u = ", a);
	displayBits(a);
	puts("");
	printf("'%c' in bits as an unsigned integer is:\n", b);
	printf("%u = ", b);
	displayBits(b);
}