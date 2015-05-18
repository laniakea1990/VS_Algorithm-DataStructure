//#include<stdlib.h>
//#include<stdio.h>
//
//#define ElementType int
//#define MinTableSize 5
//
//#ifndef _HashSep_H
//
//struct ListNode;
//typedef struct ListNode *Position;
//struct HashTbl;
//typedef struct HashTbl *HashTable;
//
//HashTable InitializeTable(int TableSize);
//void DestroyTable(HashTable H);
//Position Find(ElementType Key, HashTable H);
//void Insert(ElementType Key, HashTable H);
//ElementType Retrieve(Position P);
///* Routines such as Delete and MakeEmpty are omitted */
//
//#endif  //_HashSep_H
//
//
//struct ListNode
//{
//	ElementType Element;
//	Position Next;
//};
//
//typedef Position List;
//
///* List *TheList will be an array of lists, allocated later
//   The lists uses headers(for simplicity),
//   though this wastes space */
//struct HashTbl
//{
//	int TableSize;
//	List *TheLists;
//};
//
//HashTable InitializeTable(int TableSize)
//{
//	HashTable H;
//	int i;
//
//	if (TableSize < MinTableSize)
//	{
//		perror("Table size too small");
//		return NULL;
//	}
//
//	/* Allocate table */
//	H = (struct HashTbl*)malloc(sizeof(struct HashTbl));
//	if (H == NULL)
//		perror("Out of space");
//
//	H->TableSize = NextPrime(TableSize);	//设置表的大小为一素数
//
//	/* Allocate array of lists */
//	H->TheLists = (List *)malloc(sizeof(List) * H->TableSize);
//	if (H->TheLists == NULL)
//	{
//		perror("Out of Space!!!");
//	}
//
//	/* Allocate list headers */
//	for (int i = 0; i < H->TableSize; i++)
//	{
//		H->TheLists[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
//		if (H->TheLists[i] == NULL)
//		{
//			perror("Out of Space!!!");
//		}
//		else
//			H->TheLists[i]->Next = NULL;
//	}
//
//	return H;
//}
//
//Position Find(ElementType Key, HashTable H)
//{
//	Position P;
//	List L;
//
//	L = H->TheLists[Hash(Key, H->TableSize)];
//	P = L->Next;
//	while (P != NULL && P->Element != Key)
//		/* Probably need strcmp!! if Element is a string */
//		P = P->Next;
//	return P;	
//}
//
//void Insert(ElementType Key, HashTable H)
//{
//	Position Pos, NewCell;
//	List L;
//
//	Pos = Find(Key, H);
//	if (Pos == NULL)	/* Key is not found */
//	{
//		NewCell = (struct ListNode*)malloc(sizeof(struct ListNode));
//		if (NewCell == NULL)
//			perror("Out of space!!!");
//		else
//		{
//			L = H->TheLists[Hash(Key, H->TableSize)];
//			NewCell->Next = L->Next;
//			NewCell->Element = Key;	/* Probably need strcpy */
//			L->Next = NewCell;
//		}
//	}
//}
