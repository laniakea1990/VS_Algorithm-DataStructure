#ifndef _Tree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
int Retrieve(Position P);

#endif /* _Tree_H*/
#include <stdlib.h>

struct TreeNode
{
	int Element;
	SearchTree left;
	SearchTree right;
};

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

Position Find(int X, SearchTree T)
{
	if (T = NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->left);
	else if (X > T->Element)
		return Find(X, T->right);
	else
		return T;
}

Position FindMin(SearchTree T)		//递归实现
{
	if (T == NULL)
		return NULL;
	else if (T->left == NULL)
	{
		return T;
	}
	else
		return FindMin(T->left);
}

Position FindMax(SearchTree T)		//非递归实现
{
	if (T != NULL)
		while (T -> right != NULL)
		{
		T = T->right;
		}
	return T;
}

SearchTree Insert(int X, SearchTree T)
{
	if (T == NULL)
	{
		// create and return a one-node tree
		T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (T = NULL)
			FatalError("Out of space!!!");
		else
		{
			T->left = T->right = NULL;
			T->Element = X;
		}
	}
	else if (X < T->Element)
		T->left = Insert(X, T->left);
	else if (X > T->Element)
		T->right = Insert(X, T->right);
	/*Else X is in the tree already; we'll do nothing*/

	return T;	//Do not forget this line!!
}

SearchTree Delete(int X, SearchTree T)
{
	Position TmpCell;

	if (T == NULL)
		ERROR("Element not found");
	else if (X < T->Element)	/* Go left */
		T->left = Delete(X, T->left);
	else if (X > T->Element)	// Go right
		T->right = Delete(X, T->right);
	else if (T->left&&T->right)	//Found! Two children
	{
		// Replace with smallest in right subtree
		TmpCell = FindMin(T->right);
		T->Element = TmpCell->Element;
		T->right = Delete(T->Element, T->right);
	}
	else     //Found! One or zero children
	{
		TmpCell = T;
		if (T->left = NULL)	// Also handles 0 children
			T = T->right;
		else if (T->right = NULL)
			T = T->left;
		free(TmpCell);
	}

	return T;
}