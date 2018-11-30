//Author: Frank Su 001411435
#include <stdio.h>

//function prototype
int packCharacters(char a, char b);
void displayBits(unsigned int value);

int main() {
	puts("This program will take two characters from user input and pack them into an unsigned integer\n");
	char a, b;
	printf("Please enter the first character: ");
	scanf(" %c", &a);
	printf("Please enter the second character: ");
	scanf(" %c", &b);
	puts("");
	printf("'%c' in bits as an unsigned integer is:\n", a);
	printf("%u = ", a);
	displayBits(a);
	puts("");
	printf("'%c' in bits as an unsigned integer is:\n", b);
	printf("%u = ", b);
	displayBits(b);
	puts("");
	printf("'%c' and '%c' packed in an unsigned integer:\n", a, b);
	printf("%u = ", packCharacters(a, b));
	displayBits(packCharacters(a, b));
}

//function to print number in bits
void displayBits(unsigned int value) {
	//define mask and shift depending on memory of value
	unsigned int mask;
	//if input is char, only need to print out 8 bits
	if (sizeof(value) == 1) {
		mask = 1 << 7;
		for (unsigned int c = 1; c <= 8; c++) {
			putchar(value & mask ? '1' : '0');
			value <<= 1; //shift value left by 1
		}
	}
	//if input is packaged int, will need to print out 16 bits
	else {
		mask = 1 << 15;
		for (unsigned int c = 1; c <= 16; c++) {
			putchar(value & mask ? '1' : '0');
			value <<= 1; //shift value left by 1
			if (c % 8 == 0) {
				putchar(' ');
			}
		}
	}
	//loop through bits
	putchar('\n');
}

//function to pack the integers
int packCharacters(char a, char b) {
	unsigned int temp = a << 8;
	return (temp | b);
}
