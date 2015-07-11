/*************************************************************************
> File Name: maxsubsum.c
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Wed 29 Oct 2014 07:03:22 PM PDT
************************************************************************/

#include<stdio.h>

int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, j;

	ThisSum = MaxSum = 0;
	for (j = 0; j < N; j++)
	{
		ThisSum += A[j];

		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int main()
{
	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	int max = MaxSubsequenceSum(A, 8);

	printf("The MaxSubSum is: %d\n", max);
}
