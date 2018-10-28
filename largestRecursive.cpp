//author: Frank Su 001411435
#include <stdio.h>
#define SIZE 20

int largestRecursive(int a[], int position, int largest);
int main() {
	puts("This program will recursively determine the largest integer from an array of 20 integers");
	int array[SIZE];
	//ask user input for array
	for (size_t i = 0; i < SIZE; i++) {
		printf("Please enter the %i element of the array: ", i);
		scanf_s("%i", &array[i]);
	}
	//print array
	puts("\nThe array is as follows:");
	printf("%s%13s\n", "Element", "Value");
	for (size_t i = 0; i < SIZE; i++) {
		printf("%7u%13d\n", i, array[i]);
	}
	//call largestRecursive using last element as starting position, and assuming 0 element is largest
	int largest = largestRecursive(array, SIZE - 1, array[0]);
	printf("\nThe largest integer in the array is: %i", largest);
	
}

int largestRecursive(int a[], int position, int largest) {
	if (position == 0) {
		return largest; //assume integer at position 0 to be largest
	}
	if (position > 0) {
		//if integer at position index is greater than largest, update largest
		if (a[position] > largest) {
			largest = a[position];
		}
		//call function again with position - 1 as new comparison, and updated largest variable
		return largestRecursive(a, position - 1, largest); 
	}
}