/* Place in implementation file */
/* Stack implementation is a dynamically allocated array */
#include <stddef.h>
#include "stack_array.h"

#define EmptyTOS (-1)
#define MinStackSize (5)
#define ElementType int

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
	Stack S;

	if (MaxElements < MinStackSize)
		Error("Stack size is too small");

	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
		FatalError("Out of space!!!");

	S->Array = malloc(sizeof(ElementType) * MaxElements);
	if (S->Array == NULL)
		FatalError("Out of space");
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
		//释放内存之后原来的指针的地址不变，只是指向的内存可以重新分配了，最好将free后从指针赋值为NULL；
	}
}

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S)
{
	if (IsFull(S))
		Error("Full Stack!");
	else
		S->Array[++S->TopOfStack] = X;
}

ElementType(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack];
	Error("Empty Stack");
	return 0; /*return value used to avoid warning */
}

void Pop(Stack S)
{
	if (IsEmpty(S))
		Error("Empty stack");
	else
		S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	Error("Empty stack");
	return 0; /*Return value used to avoid warning */
}

