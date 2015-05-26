#include "BinHeap.h"
#include<stdlib.h>

#define MinPQSize 10
#define MinData -1

struct HeapStruct
{
	int Capacity;
	int Size;
	ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;

	if (MaxElements < MinPQSize)
		perror("Priority queue size is too small!");

	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	if (H = NULL)
		perror("Out of space!!!");

	// Allocate the array plus one extra for sentinel(数组多一位，作为哨兵)
	H->Elements = (ElementType*)malloc((MaxElements + 1) * sizeof(ElementType));
	if (H->Elements == NULL)
		perror("Out of space!!!");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	
	return H;	
}

// H->Element[0] is a sentinel
void Insert(ElementType X, PriorityQueue H)		//插入二叉堆
{
	int i;

	if (IsFull(H))	//检查堆是否已满
	{
		perror("Priority queue is full");
		return;
	}

	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)	//H->Element[0]必须保证小于（或等于）堆中任何值
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)	//使用了类似于Insert例程中的技巧来避免进行交换操作
{
	int i, Child;
	ElementType MinElement, LastElement;

	if (IsEmpty(H))
	{
		perror("Priority queue is empty");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];  //数组的最后一个元素

	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		//Find smaller child
		Child = i * 2;
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
			//检查节点i是否有两个儿子，如果有则比较两个儿子大小使Child指向其中较小的儿子
			Child++;

		//Percolate one level
		if (LastElement > H->Elements[Child])	//下滤的过程
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElement;	
	return MinElement;		
}

