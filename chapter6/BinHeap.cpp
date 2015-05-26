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

	// Allocate the array plus one extra for sentinel(�����һλ����Ϊ�ڱ�)
	H->Elements = (ElementType*)malloc((MaxElements + 1) * sizeof(ElementType));
	if (H->Elements == NULL)
		perror("Out of space!!!");

	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	
	return H;	
}

// H->Element[0] is a sentinel
void Insert(ElementType X, PriorityQueue H)		//��������
{
	int i;

	if (IsFull(H))	//�����Ƿ�����
	{
		perror("Priority queue is full");
		return;
	}

	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)	//H->Element[0]���뱣֤С�ڣ�����ڣ������κ�ֵ
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)	//ʹ����������Insert�����еļ�����������н�������
{
	int i, Child;
	ElementType MinElement, LastElement;

	if (IsEmpty(H))
	{
		perror("Priority queue is empty");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];  //��������һ��Ԫ��

	for (i = 1; i * 2 <= H->Size; i = Child)
	{
		//Find smaller child
		Child = i * 2;
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
			//���ڵ�i�Ƿ����������ӣ��������Ƚ��������Ӵ�СʹChildָ�����н�С�Ķ���
			Child++;

		//Percolate one level
		if (LastElement > H->Elements[Child])	//���˵Ĺ���
			H->Elements[i] = H->Elements[Child];
		else
			break;
	}
	H->Elements[i] = LastElement;	
	return MinElement;		
}

