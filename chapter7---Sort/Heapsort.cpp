#define LeftChild(i) (2 * (i) + 1)
#define ElementType int

void PercDown(ElementType A[], int i, int N) //NΪ�����С����������Ԫ�ظ�������0��ʼ��
{
	int Child;
	ElementType Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)  //����Ҫ������Ҫ���˵�Ԫ�ش���Tmp��, �����С�ڵ���N-1
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;  //i��Child���һ�θ�ֵ��ֵ
}

void Heapsort(ElementType A[], int N)
{
	int i;

	for (i = N / 2; i >= 0; i--) //BuildHeap
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]); // DeleteMax, ����һ�������һ������. �Լ���дSwap����
		PercDown(A, 0, i);  // ���˹���
	}
}