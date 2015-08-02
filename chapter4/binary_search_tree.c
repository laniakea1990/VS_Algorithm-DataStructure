#include <stdlib.h>
#include "binary_search_tree.h"

#define ElementType int

struct TreeNode
{
	ElementType Element;
	Searchtree left;
	Searchtree right;
};

Searchtree MakeEmpty(Searchtree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

Position Find(int X, Searchtree T)
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

Position Findmin(Searchtree T)		//递归实现
{
	if (T == NULL)
		return NULL;
	else if (T->left == NULL)
	{
		return T;
	}
	else
		return Findmin(T->left);
}

Position Findmax(Searchtree t)		//非递归实现
{
	if (t != NULL)
	while (t->right != NULL)
	{
		t = t->right;
	}
	return t;
}

Searchtree Insert(int X, Searchtree T)
{
	if (T == NULL)
	{
		// create and return a one-node tree
		T = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (T = NULL)
			fatalerror("out of space!!!");
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
	/*else x is in the tree already; we'll do nothing*/

	return T;	//do not forget this line!!
}

Searchtree Delete(int X, Searchtree T)
{
	Position Tmpcell;

	if (T == NULL)
		perror("Element not found");
	else if (X < T->Element)	/* go left */
		T->left = Delete(X, T->left);
	else if (X > T->Element)	// go right
		T->right = Delete(X, T->right);
	else   // Found element to be deleted. 
	if (T->left&&T->right)	// Two children
	{
		// replace with smallest in right subtree
		Tmpcell = Findmin(T->right);
		T->Element = Tmpcell->Element;
		T->right = Delete(T->Element, T->right);
	}
	else     //found! one or zero children
	{
		Tmpcell = T;
		if (T->left = NULL)	// also handles 0 children
			T = T->right;
		else if (T->right = NULL)
			T = T->left;
		free(Tmpcell);
	}

	return T;
}