/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_travs(struct node *root, int *arr, int *len)
{
	if (root == NULL)
		return;
	inorder_travs(root->left, arr, len);
	arr[*len] = root->data;
	*len = *len + 1;
	inorder_travs(root->right, arr, len);
}

void inorder(struct node *root, int *arr)
{
	if ((root == NULL) || (arr == NULL))
		return;
	int len = 0;
	inorder_travs(root, arr, &len);
}

void preorder_travs(struct node *root, int *arr, int *len)
{
	if (root == NULL)
		return;
	arr[*len] = root->data;
	*len = *len + 1;
	inorder_travs(root->left, arr, len);
	inorder_travs(root->right, arr, len);
}

void preorder(struct node *root, int *arr)
{
	if ((root == NULL) || (arr == NULL))
		return;
	int len = 0;
	preorder_travs(root, arr, &len);
}

void postorder_travs(struct node *root, int *arr, int *len)
{
	if (root == NULL)
		return;
	inorder_travs(root->left, arr, len);
	inorder_travs(root->right, arr, len);
	arr[*len] = root->data;
	*len = *len + 1;
}

void postorder(struct node *root, int *arr)
{
	if ((root == NULL) || (arr == NULL))
		return;
	int len = 0;
	postorder_travs(root, arr, &len);
}

