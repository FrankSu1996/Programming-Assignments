//Author: Frank Su 001411435
#include <stdio.h>
#include <stddef.h>
#define SIZE 10

//function prototypes
void bubbleSort(int a[]);

int main() {
	//create array of size integers
	int array[SIZE];
	puts("This program will sort the integer array, and print the largest integer, the smallest integer, and the average of all the integers.");
	//ask user for input to initialize elements of array
	for (size_t i = 0; i < SIZE; i++) {
		printf("Please enter the %i element of the array with integers from 0 to 99: ", i);
		puts("");
		scanf_s("%i", &array[i]);
	}
	//display array before sorting
	puts("The Array before sorting is as follows:");
	printf("%s%13s\n", "Element", "Value");
	for (size_t i = 0; i < SIZE; i++) {
		printf("%7u%13d\n", i, array[i]);
	}
	//display array after sorting
	puts("The array after sorting is as follows:");
	bubbleSort(array);
	printf("%s%13s\n", "Element", "Value");
	for (size_t i = 0; i < SIZE; i++) {
		printf("%7u%13d\n", i, array[i]);
	}
	//determine frequency of each integer in array
	int frequency[100] = { 0 };
	for (size_t i = 0; i < SIZE; i++) {
		++frequency[array[i]];
		}
	//print out unique elements
	for (size_t i = 0; i < 100; i++) {
		if (frequency[i] == 1) {
			printf("%i is a unique element\n", i);
		}
	}
}

//function that sorts an array with bubble sort algorithm
void bubbleSort(int a[]) {
	//loop to control number of passes
	for (unsigned int pass = 1; pass < SIZE; pass++) {
		for (size_t i = 0; i < SIZE - 1; i++) {
			if (a[i] > a[i + 1]) {
				unsigned int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}

