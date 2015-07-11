/*************************************************************************
> File Name: pow.c
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Thu 30 Oct 2014 06:42:26 PM PDT
************************************************************************/

#include<stdio.h>

long int Pow(long int X, unsigned N)
{
	//	long int a = X;
	//	int b = N;

	if (N == 0)
		return 0;
	if (N == 1)
		return N;
	if (IsEven(N))
		return Pow(X * X, N / 2);
	else
		return Pow(X * X, N / 2) * X;
}

int IsEven(unsigned a)
{
	if (a % 2 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int p;
	long int result = 0, i;

	scanf("Please input the number and the power you want to compute: %ld %d", &i, &p);
	result = Pow(i, p);

	printf("The result of %ld ^ %d is: %ld \n", i, p, result);
}
