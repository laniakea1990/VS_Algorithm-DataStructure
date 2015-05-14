

#ifndef _AvlTree_H
#define ElementType int

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

#endif
#include<stdlib.h>
#define Max(x,y) x>y?x:y

struct AvlNode
{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		/* Create and return a one-node tree */
		T =(struct AvlNode*)malloc(sizeof(struct AvlNode));
		if (T == NULL)
			perror("Out of Space!!!");
		else
		{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (X>T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	}
	/* Else X is in the tree already; we'll do nothing */

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}
/* This function can be called only if K2 has left child
	Perform a rotate between a node (K2) and its left child
	Update heights, then return new root
	*/

static Position SingleRotateWithLeft(Position K2)
{
	Position K1;

	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), K2->Height) + 1;
	
	return K1; /* New Root */
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Right), K2->Height) + 1;

	return K1;

}

/* This function can be called only if K3 has a left
	child and K3's left child has a right child
	Do the left-right double rotation 
	Update heights, then return new root */

static Position DoubleRotateWithLeft(Position K3)
{
	/* Rotate between K1 and K2 */
	K3->Left = SingleRotateWithRight(K3->Left);

	/* Rotate between K3 and K2 */
	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);
	
	return SingleRotateWithRight(K3);
}