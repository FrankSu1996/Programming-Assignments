//Author: Frank Su 001411435
#include <stdio.h>
#include <math.h>
#define PI 3.1415926

//function prototypes
void circleCircumference(double radius);
void circleArea(double radius);
void sphereVolume(double radius);

int main() {
	//initialize array of 3 pointers to functions that each take a double 
	//argument and return void
	void(*f[3])(double) = { circleCircumference, circleArea, sphereVolume };

	//print statements to show the menu
	puts("This program will perform the following calculations depending on the user input:");
	puts("To calculate the circumference of a circle, please enter a 0");
	puts("To calculate the area of a circle, please enter a 1");
	puts("To calculate the volume of a sphere, please enter a 2");
	puts("To exit the program, please enter a 3");

	//ask user for menu input and radius 
	int choice;
	printf("Please enter your choice: ");
	scanf("%i", &choice);

	//process user's choice
	while (choice < 0 || choice > 3) {
		puts("You have entered an invalid choice! Please enter a number between 0 and 3");
		scanf("%i", &choice);
	}
	while (choice >= 0 && choice < 3) {
		//invoke function at location choice in array f
		//and pass radius as an argument
		double radius;
		puts("Please enter the radius: ");
		scanf("%lf", &radius);
		(*f[choice])(radius);

		//reprint menu
		puts("To calculate the circumference of a circle, please enter a 0");
		puts("To calculate the area of a circle, please enter a 1");
		puts("To calculate the volume of a sphere, please enter a 2");
		puts("To exit the program, please enter a 3");

		//reask for user input
		printf("Please enter your choice: ");
		scanf("%i", &choice);
	}
	puts("Program execution completed.");
}

//function to calculate circumference of circle
void circleCircumference(double radius) {
	double circumference = (2 * PI*radius);
	puts("You have chosen to calculate the circumference of a circle!");
	printf("The circumference of a circle with radius %.2f is: %.2f\n\n", radius, circumference);
}

//function to calculate area of circle
void circleArea(double radius) {
	double area = (PI * pow(radius, 2));
	puts("You have chosen to calculate the area of a circle!");
	printf("The area of a circle with radius %.2f is: %.2f\n\n", radius, area);
}

//function to calculate volume of sphere
void sphereVolume(double radius) {
	double volume = ((4.00 / 3.00) * PI * pow(radius, 3));
	puts("You have chosen to calculate the volume of a sphere!");
	printf("The volume of a sphere with radius %.2f is: %.2f\n\n", radius, volume);
}