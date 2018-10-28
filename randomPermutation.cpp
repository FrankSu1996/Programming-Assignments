//author: Frank Su 001411435
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

//function declaration

void shuffle(int a[]);

int main() {
	puts("This program will intialize an array of 20 integers with consecutive integers from 1 to 20");
	int array[SIZE];
	//initialize array elements with consecutive integers from 1 to 20
	for (size_t i = 0; i < SIZE; i++) {
		array[i] = i + 1;
	}
	//print array before shuffling 
	puts("The array before shuffling");
	printf("%s%13s\n", "Element", "Value");
	for (size_t i = 0; i < SIZE; i++) {
		printf("%7u%13d\n", i, array[i]);
	}
	//shuffle cards using shuffle function
	shuffle(array);
	puts("");
	//print shuffled array
	puts("The array after shuffling");
	printf("%s%13s\n", "Element", "Value");
	for (size_t i = 0; i < SIZE; i++) {
		printf("%7u%13d\n", i, array[i]);
	}
}

void shuffle(int a[]) {
	srand(time(NULL)); //seed random function with real time so it is never constant
	for (size_t i = 0; i < SIZE; i++) {
		int j = (rand() % 19); //j is random integer between 0 and 19 to signify elements of array
		int temp = a[i]; //temp holds first element
		a[i] = a[j]; //a[i] changes to a[j]: since j is randomly determined, this shuffles the two elements
		a[j] = temp;
	}
}