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

Position FindMin(SearchTree T)
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

Position FindMax(SearchTree T)
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

	return T;	//Do not forget this line!!
}