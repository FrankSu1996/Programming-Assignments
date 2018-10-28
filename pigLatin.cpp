//Author: Frank Su
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//function prototype
void printLatinWord(char *word);
int main() {
	puts("This program will translate a sentence in english into pig latin!");
	puts("Please enter a sentence to be translated:");
	char sentence[500];
	const char s[2] = " ";
	gets_s(sentence);
	//tokenize the sentence using space as delimeter
	char *word = strtok(sentence, s);
	puts("The sentence you entered translated into pig latin is:");
	//continue tokenizing sentence until tokenPtr becomes NULL
	while (word != NULL) {
		printLatinWord(word); //call printLatinWord with word as input
		word = strtok(NULL, s); //get next token
	}
}

void printLatinWord(char *word) {
	char pig[25] = " ";
	//initialize char array to empty to hold first letter of word
	char firstLetter[2] = "";
	//copy first letter of word into firstLetter 
	strncat(firstLetter, word, 1);
	//copy initial word into pig array
	strcpy(pig, &word[1]);
	//add first letter to word in pig
	strcat(pig, firstLetter);
	strcat(pig, "ay" );
	printf("%s ", pig);
}