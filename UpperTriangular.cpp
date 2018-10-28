//Author: Frank Su 001411435
#include <stdio.h>
#include <stddef.h> 
#include <stdlib.h>
#define SIZE 3

//declare function prototypes
void printArray(int a[SIZE][SIZE]);
int upperTriangular(int a[SIZE][SIZE]);

int main() {
	printf("This program will create a 5x5 matrix with random integers from 0 to 100\n");
	printf("This program will then calculate and print the sum of the upper triangular elements of the array\n");
	int array[SIZE][SIZE];
	//initialize array elements with random integers between 0 and 100
	for (size_t row = 0; row < SIZE; row++) {
		for (size_t column = 0; column < SIZE; column++) {
			array[row][column] = (rand() % 100);
		}
	}
	//print matrix
	puts("The matrix is as follows:");
	printArray(array);
	//calculate and pritn sum of uupper triangular elements
	printf("The sum of these elements are: %i", upperTriangular(array));
}

//function to print matrix
void printArray(int a[][SIZE]) {
	for (size_t row = 0; row < SIZE; row++) {
		for (size_t column = 0; column < SIZE; column++) {
			printf("%i ", a[row][column]);
		}
		puts("");
	}
}

//function to return sum of upper triangular elements of matrix
int upperTriangular(int a[SIZE][SIZE]) {
	int sum = 0;
	for (size_t row = 0; row < SIZE; row++) {
		for (size_t column = 0; column < SIZE; column++) {
			if (row < column) {
				sum += a[row][column];
			}
		}
	}
	return sum;
}