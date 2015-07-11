/*************************************************************************
> File Name: list.c
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Sun 02 Nov 2014 10:40:57 PM PST
************************************************************************/
#include "list.h"
#include<stddef.h>

#define ElementType int

struct Node
{
	ElementType Element;
	Position Next;
};

/* Return true if L is empty */
int IsEmpty(List L)
{
	return L->Next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */

int IsLast(Position P, List L)
{
	return L->Next == NULL;
}

/* Return Position of X in L; NULL if not found */

Position Find(ElementType X, List L)
{
	Position P;

	P = L->Next;
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}

	return P;
}

void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P, L))	//Assumption of header use
	{					//X is found; delete it
		TmpCell = P->Next;
		P->Next = TmpCell->Next;	//Bypass deleted cell
		free(TmpCell);
	}
}

Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	return P;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		perror("Out of space!!!");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P, Tmp;

	P = L->Next;	//Header assumed
	L->Next = NULL;
	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}