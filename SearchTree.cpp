//Author: Frank Su 001411435
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tree structure
typedef struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

//function to insert node into tree
void Insert(BstNode** rootPtr, int data) {
	if (*rootPtr == NULL) { //empty tree
		*rootPtr = (BstNode*)malloc(sizeof(BstNode));
		if (*rootPtr != NULL) {
			(*rootPtr)->data = data;
			(*rootPtr)->left = NULL;
			(*rootPtr)->right = NULL;
		}
	}
	else if (data <= (*rootPtr)->data) {
		Insert(&((*rootPtr)->left), data); 
	}
	else {
		Insert(&((*rootPtr)->right), data);
	}
}

//function to print instructions
void Instructions() {
	printf("This program will search for all keys within a given range in a Tree stucture.\n");
	printf("To Insert a node into the tree, enter \"insert\"\n");
	printf("To print the tree using an InOrder traversal, enter \"print\"\n");
	printf("To search for keys within a range, enter \"search\"\n");
	printf("To exit the program, enter \"exit\"\n");
	return;
}
//Inorder traversal of tree for testing
void InOrder(BstNode* rootPtr) {
	if (rootPtr == NULL) {
		return;
	}
	InOrder(rootPtr->left);
	printf("%d ", rootPtr->data);
	InOrder(rootPtr->right);
}

//Search function to find keys in a tree within a range
void Search(BstNode* rootPtr, int lower, int upper) {
	if (rootPtr == NULL) {
		return;
	}
	Search(rootPtr->left, lower, upper);
	if ((rootPtr->data >= lower) && (rootPtr->data <= upper)) {
		printf("%d ", rootPtr->data);
	}
	Search(rootPtr->right, lower, upper);
}

int main() {
	BstNode* root = NULL;
	Instructions();
	char input[20];
	int data;
	int lower; //lower range limit
	int upper; //upper range limit
	while (fgets(input, 20, stdin)) {
		if (strncmp(input, "insert", 6) == 0) {
			printf("Please enter an integer to insert into the tree: ");
			scanf_s("%d", &data);
			Insert(&root, data);
		}
		else if (strncmp(input, "print", 5) == 0) {
			if (root == NULL) {
				printf("The tree is empty!\n");
				continue;
			}
			printf("The tree InOrder is: ");
			InOrder(root);
			puts("");
		}
		else if (strncmp(input, "search", 6) == 0) {
			if (root == NULL) {
				printf("The tree is empty!\n");
				continue;
			}
			printf("Please enter the lower limit of the range: ");
			scanf_s("%d", &lower);
			printf("Please enter the upper limit of the range: ");
			scanf_s("%d", &upper);
			printf("The elements in the tree between %d and %d are: ", lower, upper);
			Search(root, lower, upper);
			puts("");
		}
		else if (strncmp(input, "exit", 4) == 0) {
			break;
		}
	}
	puts("Program will now terminate.");
}