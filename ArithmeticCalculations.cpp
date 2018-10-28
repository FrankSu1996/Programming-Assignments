//Author: Frank Su 001411435
#include <stdio.h>

//function prototypes
void addition(double x, double y);
void subtraction(double x, double y);
void multiplication(double x, double y);
void division(double x, double y);

int main() {
	// initialize array of 4 pointers to functions that each take 2 double's as 
	//arguments and return void
	void(*f[4])(double, double) = { addition, subtraction, multiplication, division };

	//print statements to show the menu
	puts("This program will perform the following calculations depending on the user input:");
	puts("To add two numbers, please enter a 0");
	puts("To subtract two numbers, please enter a 1");
	puts("To multiply two numbers, please enter a 2");
	puts("To divide two numbers, please enter a 3");
	puts("To exit the program, please enter a 4\n");

	//ask user for menu input and radius 
	int choice;
	printf("Please enter your choice: ");
	scanf("%i", &choice);
	// process user's choice
	while (choice < 0 || choice > 4) {
		puts("You have entered an invalid choice! Please enter a number between 0 and 4");
		scanf("%i", &choice);
	}
	while (choice >= 0 && choice < 4) {
		//invoke function at location choice in array f
		//and pass radius as an argument
		double x, y;
		puts("Please enter the first number: ");
		scanf("%lf", &x);
		puts("Please enter the second number: ");
		scanf("%lf", &y);
		(*f[choice])(x, y);

		//reprint menu
		puts("To add two numbers, please enter a 0");
		puts("To subtract two numbers, please enter a 1");
		puts("To multiply two numbers, please enter a 2");
		puts("To divide two numbers, please enter a 3");
		puts("To exit the program, please enter a 4");

		//reask for user input
		printf("Please enter your choice: ");
		scanf("%i", &choice);
	}
	puts("Program execution completed.");
}

//function to add two numbers
void addition(double x, double y) {
	double sum = x + y;
	puts("You have chosen to perform addition on two numbers!");
	printf("The sum from adding %f and %f is: %f\n\n", x, y, sum);
}

//function to subtract two numbers
void subtraction(double x, double y) {
	double difference = x - y;
	puts("You have chosen to perform subtraction on two numbers!");
	printf("The difference from subtracting %f from %f is: %f\n\n", y, x, difference);
}

//function to multiply two numbers
void multiplication(double x, double y) {
	double product = x * y;
	puts("You have chosen to perform multiplication on two numbers!");
	printf("The product from multiplying %f and %f is: %f\n\n", x, y, product);
}

//function to divide two numbers
void division(double x, double y) {
	double quotient = x / y;
	puts("You have chosen to perform division on two numbers!");
	printf("The quotient from dividing %f from %f is: %f\n\n", x, y, quotient);
}