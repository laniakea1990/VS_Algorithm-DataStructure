#include <stdlib.h>
//递归例程Msort的驱动程序
void Msort(int A[], int TmpArray[], int left, int right)
{
	int center;

	if (left < right)
	{
		center = (left + right) / 2;
		Msort(A, TmpArray, left, center);
		Msort(A, TmpArray, center + 1, right);
		Merge(A, TmpArray, left, center + 1, right);
	}
}

//递归例程Mergesort
void Mergesort(int A[], int N)
{
	int *TmpArray;

	TmpArray = (int *)malloc(N * sizeof(int));
	if (TmpArray != NULL)
	{
		Msort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
		perror("No space for tmp array!!!");
}

void Merge(int A[], int Tmparray[], int lpos, int rpos, int rightEnd)
{
	int i, leftEnd, numElements, TmpPos;

	leftEnd = rpos - 1;
	TmpPos = lpos;
	numElements = rightEnd - lpos + 1;

	/* main loop */
	while (lpos <= leftEnd && rpos <= rightEnd)
		if (A[lpos] <= A[rpos])
			Tmparray[TmpPos++] = A[lpos++];
		else
			Tmparray[TmpPos++] = A[rpos++];
	
	while (lpos <= leftEnd)	//Copy rest of first half
		Tmparray[TmpPos++] = A[lpos++];
	while (rpos <= rightEnd)	//Copy rest of second half
		Tmparray[TmpPos++] = A[rpos++];

	//Copy Tmparray back
	for (i = 0; i < numElements; i++, rightEnd--)
		A[rightEnd] = Tmparray[rightEnd];
}