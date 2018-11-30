//Author: Frank Su 001411435
#include <stdio.h>
#include <string.h>

int main() {
	//declare file pointer
	FILE *fpointer;
	//declare and initialize variables from stdin
	char fileName[20];
	int lines;
	printf("Input the file name to be opened: ");
	fgets(fileName, 20, stdin);
	strtok(fileName, "\n"); //remove newline from stdin
	//open file using file pointer and append newline 
	fpointer = fopen(fileName, "a");
	printf("Input the number of lines to written: ");
	scanf_s("%d", &lines);
	puts("The lines are:");
	//for loop to get user input for strings to append
	for (int i = 0; i <= lines; i++) {
		char string[30];
		fgets(string, 30, stdin);
		fprintf(fpointer, string);
	}
	fclose(fpointer);
}