#include <stdio.h>
#include <stdlib.h>

//Tree structure
typedef struct TreeNode {
	char data;
	TreeNode* left;
	TreeNode* right;
};

//Function to insert 'A' at root
void InsertRoot(TreeNode** root, char data) {
	if (*root == NULL) {
		*root = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
}

//function to insert to left branch of treeNode
TreeNode* InsertLeft(TreeNode** root, char data) {
	if ((*root)->left == NULL) {
		TreeNode* LeftBranch = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->left = LeftBranch;
		LeftBranch->data = data;
		LeftBranch->left = NULL;
		LeftBranch->right = NULL;
		return LeftBranch;
	}
}

//function to insert to right branch of treeNode
TreeNode* InsertRight(TreeNode** root, char data) {
	if ((*root)->right == NULL) {
		TreeNode* RightBranch = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->right = RightBranch;
		RightBranch->data = data;
		RightBranch->left = NULL;
		RightBranch->right = NULL;
		return RightBranch;
	}
}

//Inorder traversal to test output
void InOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}

//Preorder traversal to test output
void PreOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->data);
	PreOrder(root->left); 
	PreOrder(root->right);
}

int main() {
	TreeNode* root = NULL; // set tree to empty
	InsertRoot(&root, 'A');
	TreeNode* BPointer = InsertLeft(&root, 'B');
	InsertLeft(&BPointer, 'D');
	InsertRight(&BPointer, 'E');
	TreeNode* CPointer = InsertRight(&root, 'C');
	InsertLeft(&CPointer, 'F');
	printf("Inorder sequence: ");
	InOrder(root);
	printf("\n");
	printf("Preorder sequence: ");
	PreOrder(root);
}