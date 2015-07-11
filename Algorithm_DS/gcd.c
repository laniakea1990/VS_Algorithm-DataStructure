/*************************************************************************
> File Name: gcd.c
> Author: ma6174
> Mail: ma6174@163.com
> Created Time: Thu 30 Oct 2014 06:09:11 AM PDT
************************************************************************/

#include<stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int Rem;

	while (N > 0)
	{
		Rem = M % N;
		M = N;
		N = Rem;
	}
	return M;
}

int main()
{
	unsigned int a = 1990, b = 1590;
	int gcd = 0;

	if ((gcd = Gcd(a, b)) > 0)
		printf("The Zui Da Gong Yue Shu is: %d\n", gcd);
	return 0;
}
