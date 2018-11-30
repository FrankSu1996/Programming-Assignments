//Author: Frank Su 001411435
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 50
char stack[MAX_SIZE];
int top = -1;

//push function
void Push(char x) {
	top++;
	stack[top] = x; 
}
//pop function also returns popped char
char Pop() {
	if (top == -1) {
		printf("Error: No element to pop\n");
	}
	char c = stack[top];
	top--;
	return c;
}
// Function to remove all spaces (and punctuation) from a given string 
void RemoveSpace(char *str)
{
	if (str == NULL) {
		return;
	}
	int n = 0;
	//loop through string, if space/punc encountered, skip it
	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i])) {
			str[n++] = str[i];
		}
	}
	str[n] = '\0';
}

int main() {
	char string[50];
	char copy[50];
	int count = 0; 
	printf("Please enter a line of text:\n");
	fgets(string, 50, stdin);
	strcpy(copy, string);
	strtok(string, "\n"); //remove newline from string
	strtok(copy, "\n"); //remove newline from copy
	RemoveSpace(string); //remove spaces and punctuation froms string
	int length = strlen(string);
	//push string into stack
	for (int i = 0; i < length; i++) {
		Push(string[i]);
	}
	//compare first letter of string with popped char, increase count if match
	for (int i = 0; i < length; i++) {
		if (string[i] == Pop()) {
			count++;
		}
	}
	//if string is palindrome, match count should equal length of string
	if (length == count) {
		printf("\"%s\" is a palindrome", copy);
	}
	else {
		printf("\"%s\" is not a palindrome", copy);
	}
}