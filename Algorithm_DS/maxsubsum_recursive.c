/*************************************************************************
> File Name: maxsubsum.c
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Wed 29 Oct 2014 05:58:16 PM PDT
************************************************************************/
//求最大子序列的和，该方法的时间复杂度为O(nlogn)

#include<stdio.h>

static int MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;

	if (Left == Right)
	if (A[Left] > 0)
		return A[Left];
	else
		return 0;

	Center = (Left + Right) / 2;
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int Max3(int a, int b, int c)
{
	int max = 0;
	if (a > b)
		max = a > c ? a : c;
	else
		max = b > c ? b : c;
	return max;
}

int MaxSubsequenceSum(const int A[], int N)
{
	return MaxSubSum(A, 0, N - 1);
}

int main()
{
	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	int maxsubsum = 0;

	maxsubsum = MaxSubsequenceSum(A, 8);
	printf("The Max Subsequence Sum of the array is: %d\n", maxsubsum);

	return 0;
}
