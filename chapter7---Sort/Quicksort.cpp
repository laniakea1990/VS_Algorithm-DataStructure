#define Cutoff (3)

//快速排序的驱动例程
void Quicksort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}

//实现三数中值分割方法的程序
/* Return median of left, center, and right*/
/* Order these and hide the pivot */
int Median3(int A[], int left, int right)
{
	int center = (left + right) / 2;

	if (A[left] > A[center])
		Swap(&A[left], &A[center]);
	if (A[left] > A[right])
		Swap(&A[left], &A[right]);
	if (A[center] > A[right])
		Swap(&A[center], &A[right]);

	/* Invariant: A[left] <= A[center] <= A[right] */

	Swap(&A[center], &A[right - 1]);  // Hide the pivot
	return A[right - 1];  // Return pivot
}

//快速排序的主例程
void Qsort(int A[], int left, int right)
{
	int i, j;
	int pivot;

	if (left + Cutoff <= right)
	{
		pivot = Median3(A, left, right);
		i = left;
		j = right - 1;
		for (;;)
		{
			while (A[++i] < pivot) {}
			while (A[--j] > pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[right - 1]); //Restore priot

		Qsort(A, left, i - 1);
		Qsort(A, i + 1, right);
	}
	else  //Do an insertion sort on the subarray
		InsertionSort(A + left, right - left + 1);
}