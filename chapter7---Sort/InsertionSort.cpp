#define elementtype int

void insertionsort(elementtype a[], int n)
{
	int j, p;

	elementtype tmp;
	for (p = 1; p < n; p++)
	{
		tmp = a[p];
		for (j = p; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];	// 没有明显使用交换
		a[j] = tmp;
	}
}
