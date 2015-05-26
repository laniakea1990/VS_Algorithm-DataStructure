#define LeftChild(i) (2 * (i) + 1)
#define ElementType int

void PercDown(ElementType A[], int i, int N) //N为数组大小（即待排序元素个数，从0开始）
{
	int Child;
	ElementType Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)  //将需要可能需要下滤的元素存入Tmp中, 左儿子小于等于N-1
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;  //i是Child最后一次赋值的值
}

void Heapsort(ElementType A[], int N)
{
	int i;

	for (i = N / 2; i >= 0; i--) //BuildHeap
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]); // DeleteMax, 交换一个和最后一个数据. 自己编写Swap例程
		PercDown(A, 0, i);  // 下滤过程
	}
}