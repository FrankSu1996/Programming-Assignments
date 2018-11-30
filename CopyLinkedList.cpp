//Author: Frank Su 001411435
#include <stdio.h>
#include <stdlib.h>

//Define Node structure
typedef struct Node {
	char data;
	Node* next;
};

//Insert function only needed to insert at beginning of list
void Insert(Node** head, char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

//Insert first function: Will insert char at beginning of list
//Function to print list
void Print(Node * head) {
	while (head != NULL) {
		printf("%c ", head->data);
		head = head->next;
	}
	//print start to signify NULL at end of list
	if (head == NULL) {
		printf("*");
	}
}


int main() {
	//set head node to NULL
	Node* head = NULL;
	Node* headReverse = NULL;
	//set head node of copied linked list to NULL
	//get user input for 10 characters and insert them into linked list 
	puts("This program will copy a linked list of 10 characters in reverse order.");
	puts("Please enter 10 characters: ");
	for (int i = 0; i < 10; i++) {
		printf("Please enter character %d: ", i+1);
		printf("\n");
		char c;
		scanf_s(" %c", &c);
		Insert(&head, c);
	}
	//Print list
	puts("\nThe list is:");
	Print(head);
	printf("\n\n");
	//Make copy of list in reverse order and print it
	Node* current = head;
	while (current != NULL) {
		Insert(&headReverse, current->data);
		current = current->next;
	}
	//Call Print function with head of reversed linked list to show it is seperate from original
	puts("The list in reverse is:");
	Print(headReverse);
}