/*************************************************************************
> File Name: binary_search.c
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Thu 30 Oct 2014 05:29:48 AM PDT
************************************************************************/

#include<stdio.h>

#define NotFound -1

typedef int ElementType;

int BinarySearch(const ElementType A[], ElementType X, int N)
{
	int Low, Mid, High;

	Low = 0;
	High = N - 1;
	while (Low <= High)
	{
		Mid = (Low + High) / 2;
		if (A[Mid] < X)
			Low = Mid + 1;
		else if (A[Mid] > X)
			High = Mid - 1;
		else
			return Mid;
	}
	return NotFound;
}

int main()
{
	int A[8] = { 1, 2, 4, 6, 9, 11, 14, 16 };
	int a;
	if ((a = BinarySearch(A, 16, 8)) > 0)
		printf("Just Found The Number!, the position is: %d\n", a);
	else
		printf("Oops, Not Found The Number!\n");
	getchar();
	return 0;
}
