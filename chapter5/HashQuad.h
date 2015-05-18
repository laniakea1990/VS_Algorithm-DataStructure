#include<stdlib.h>
#include<stdio.h>

#define ElementType int
#define MinTableSize 11

#ifndef _HashQuad_H

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);
/* Routines such as Delete and MakeEmpty are omitted */

#endif /* _HashQuad_H */

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry
{
	ElementType Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

/* Cell *TheCells will be an array of
   HashEntry cells, allocated later */
struct HashTbl
{
	int TableSize;
	Cell *TheCells;
};

HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;

	if (TableSize < MinTableSize)
	{
		perror("Table size too small");
		return NULL;
	}

	/* Allocate table */
	H = (struct HashTbl*)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		perror("Out of space!!!");

	H->TableSize = NextPrime(TableSize);

	/* Allocate array of Cells */
	H->TheCells = (struct HashEntry*)malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL)
		perror("Out of space!!!");

	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;

	return H;
}

Position Find(ElementType Key, HashTable H) // 使用平方探测散列法的Find例程
{
	Position CurrentPos;
	int CollisionNum;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key) //probably need strcmp!!
	{
		CurrentPos += 2 * ++CollisionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
	Position Pos;

	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)
	{
		// Ok to insert here
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
			//probably need strcpy!
	}
}

HashTable Rehash(HashTable H)	// 再散列的实现
{
	int i, OldSize;
	Cell *OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	// Get a new, empty table
	H = InitializeTable(2 * OldSize);

	// Scan through old table, reinserting into new
	for (i = 0; i < OldSize; i++)
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);

	free(OldCells);

	return H;
}