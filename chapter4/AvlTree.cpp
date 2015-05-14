#include<stdlib.h>
#include<stdio.h>

#define ElementType int

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