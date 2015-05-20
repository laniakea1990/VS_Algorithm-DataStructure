#define ElementType int

//һ��hk-��kΪ�±꣩��������þ��Ƕ�hk��������������ִ��һ�β�������
void Shellsort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType Tmp;

	for (Increment = N / 2; Increment > 0; Increment /= 2) // ��������ѭ�����ݼ���
		for (i = Increment; i < N; i++)		// ��A[Increment]��ʼ�����������Ԫ�ز����бȽϽ���
		{
		Tmp = A[i];		// ��������Ԫ���ȴ�����ʱ����Tmp��
		for (j = i; j >= Increment; j -= Increment)		// A[Increment]�Ͱ�Increment�ļ���ٶ����κ�ǰ������ݽ��бȽ�
			if (Tmp < A[j - Increment])
				A[j] = A[j - Increment];
			else
				break;
		A[j] = Tmp;
		}
}