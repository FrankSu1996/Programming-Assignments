//author: Frank Su 001411435
#include <stdio.h>
#include <string.h>

//global node structure 
typedef struct Node {
	int data;
	Node* next;
}Node;
Node *head;


//Function to insert element into linked list
void Insert(int data) {
	//create memory for new node 
	Node* temp = new Node();
	//set data in node, 
	temp->data = data;
	temp->next = head;
	head = temp; //set new head to newly created node
	return;
}

//Function to print linked list
void Print() {
	Node* temp = head;
	while (temp != NULL) {
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
	if (temp == NULL) {
		printf("NULL");
	}
	printf("\n");
}

//Function to recursively search linked list for an element
int Search(Node* head, int x) {
	//Base case
	if (head == NULL) {
		return 0;
	}
	//If key is present in current node, return 1 (true)
	if (head->data == x) {
		return 1;
	}
	//Recursively search through remaining list
	return (Search(head->next, x));
}

int main() {
	//menu options
	puts("Enter your choice: ");
	puts("To insert an element into the list, enter \"insert\"");
	puts("to recursively search the list for an element, enter \"search\"");
	puts("To end, enter \"exit\"");
	//while loop continuously gets user input until "exit" is entered
	char input[10];
	while (fgets(input, 10, stdin)) {
		if (strncmp(input, "insert", 6) == 0) {
			int data;
			printf("Enter an integer: \n");
			scanf_s("%d", &data);
			Insert(data);
			printf("The list is: \n");
			Print();
		}
		else if (strncmp(input, "search", 6) == 0) {
			int key;
			printf("Enter the integer to recursively search for: \n");
			scanf_s("%d", &key);
			if ((Search(head, key) == 0)) {
				printf("%d is not in the list.\n", key);
			}
			else if ((Search(head, key) == 1)) {
				printf("%d is in the list.\n", key);
			}
		}
		else if (strncmp(input, "exit", 4) == 0) {
			break;
		}
	}
	printf("End of run.");
}