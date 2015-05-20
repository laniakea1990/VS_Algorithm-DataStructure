//#define ElementType int
//
//void InsertionSort(ElementType A[], int N)
//{
//	int j, P;
//
//	ElementType Tmp;
//	for (P = 1; P < N; P++)
//	{
//		Tmp = A[P];
//		for (j = P; j > 0 && A[j - 1] > Tmp; j--)
//			A[j] = A[j - 1];	// 没有明显使用交换
//		A[j] = Tmp;
//	}
//}
