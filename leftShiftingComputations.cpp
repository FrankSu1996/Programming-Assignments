//author: Frank Su 001411435
#include <stdio.h>

//function prototypes
void displayBits(unsigned int value);
int power2(unsigned int number, unsigned int power);

int main() {
	int number;
	int power;
	puts("This program will calculate the power of a number using the left shift operator");
	printf("Please enter a number: ");
	scanf_s("%u", &number);
	printf("How many bits do you wish to left shift your number by? ");
	scanf_s("%u", &power);
	printf("The result of the operation as an integer is: %u\n", power2(number, power));
	printf("The result of the operation printed in bits is: ");
	displayBits(power2(number, power));
}

//function to print number in bits
void displayBits(unsigned int value){
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

//function to calculate power of a number using shift operator
int power2(unsigned int number, unsigned int power) {
	return number << power;
}