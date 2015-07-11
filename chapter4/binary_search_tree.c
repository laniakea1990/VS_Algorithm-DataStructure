#include <stdlib.h>
#include "binary_search_tree.h"

#define ElementType int

struct TreeNode
{
	ElementType Element;
	Searchtree left;
	Searchtree right;
};

Searchtree MakeEmpty(Searchtree t)
{
	if (t != NULL)
	{
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}
	return NULL;
}

Position Find(int x, Searchtree t)
{
	if (t = NULL)
		return NULL;
	if (x < t->Element)
		return Find(x, t->left);
	else if (x > t->Element)
		return Find(x, t->right);
	else
		return t;
}

Position Findmin(Searchtree t)		//递归实现
{
	if (t == NULL)
		return NULL;
	else if (t->left == NULL)
	{
		return t;
	}
	else
		return Findmin(t->left);
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

Searchtree Insert(int x, Searchtree t)
{
	if (t == NULL)
	{
		// create and return a one-node tree
		t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		if (t = NULL)
			fatalerror("out of space!!!");
		else
		{
			t->left = t->right = NULL;
			t->Element = x;
		}
	}
	else if (x < t->Element)
		t->left = Insert(x, t->left);
	else if (x > t->Element)
		t->right = Insert(x, t->right);
	/*else x is in the tree already; we'll do nothing*/

	return t;	//do not forget this line!!
}

Searchtree Delete(int x, Searchtree t)
{
	Position Tmpcell;

	if (t == NULL)
		perror("element not found");
	else if (x < t->Element)	/* go left */
		t->left = Delete(x, t->left);
	else if (x > t->Element)	// go right
		t->right = Delete(x, t->right);
	else if (t->left&&t->right)	//found! two children
	{
		// replace with smallest in right subtree
		Tmpcell = Findmin(t->right);
		t->Element = Tmpcell->Element;
		t->right = Delete(t->Element, t->right);
	}
	else     //found! one or zero children
	{
		Tmpcell = t;
		if (t->left = NULL)	// also handles 0 children
			t = t->right;
		else if (t->right = NULL)
			t = t->left;
		free(Tmpcell);
	}

	return t;
}