#define ElementType int

void InsertionSort(ElementType a[], int n)
{
	int j, p;

	ElementType tmp;
	for (p = 1; p < n; p++)
	{
		tmp = a[p];
		for (j = p; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];	// û������ʹ�ý���
		a[j] = tmp;
	}
}
