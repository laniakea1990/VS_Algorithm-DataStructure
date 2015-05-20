#define ElementType int

//一趟hk-（k为下标）排序的作用就是对hk个独立的子数组执行一次插入排序
void Shellsort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType Tmp;

	for (Increment = N / 2; Increment > 0; Increment /= 2) // 增量序列循环（递减）
		for (i = Increment; i < N; i++)		// 从A[Increment]开始往后遍历数组元素并进行比较交换
		{
		Tmp = A[i];		// 待交换的元素先存入临时变量Tmp中
		for (j = i; j >= Increment; j -= Increment)		// A[Increment]和按Increment的间隔速度依次和前面的数据进行比较
			if (Tmp < A[j - Increment])
				A[j] = A[j - Increment];
			else
				break;
		A[j] = Tmp;
		}
}