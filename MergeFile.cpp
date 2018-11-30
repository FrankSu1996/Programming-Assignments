//Author: Frank Su 001411435
#include <stdio.h>

int main() {
	//character variable to hold individual characters of text files
	char c;
	//create filepointers for files to be opened
	FILE *file1p = fopen("test.txt", "r");
	FILE *file2p = fopen("test1.txt", "r");
	FILE *file3p = fopen("mergefiles.txt", "w");
	//error message if can't open files
	if (file1p == NULL || file2p == NULL || file3p == NULL) {
		puts("File could not be opened!");
	}
	else {
		//copy contents of test.txt into mergefiles.txt
		while ((c = fgetc(file1p)) != EOF) {
			fputc(c, file3p);
		}
		fputc('\n', file3p); //put a newline to seperate lines
		//copy contents of test1.txt into mergefiles.txt
		while ((c = fgetc(file2p)) != EOF) {
			fputc(c, file3p);
		}
	}
	printf("test.txt and test1.txt successfully merged into mergefiles.txt");
	//close files
	fclose(file1p);
	fclose(file2p);
	fclose(file3p);
}