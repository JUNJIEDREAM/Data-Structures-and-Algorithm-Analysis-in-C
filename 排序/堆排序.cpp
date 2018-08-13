/*
������

˼·���������Ϊ�����ѡ�ɾ����ֵ�������Ѽ��������˲�����

������ʹ���������ADT�������������ͣ��ķ�ʽʵ�ֳ�ʼ�������±���㿪ʼ��

�ܽ᣺ʱ�临�Ӷ�ΪN*logN��
*/

//���˲���
void PercDown(ElementType A[], int i, int N)	//iΪ���ڵ��±�
{
	int replChild;		//���˲���ʱ��������ڵ㽻���ĺ��ӽڵ��±�
	ElementType tmp;	//һ�����ý������е�����Ҫ��һ��tmp����

	//ÿ�ο�ʼ��Ҫȡ������±꣬���Կ���д��for���ͷ����Ϊ��ʼ����
	//�������������Ǹ��ڵ㻹�к���
	//ִ����˴����˲�������Ҫ�ҵ��´����˲����ĸ��ڵ㣬��������Ҳ����д��for���ͷ
	for (tmp = A[i]; 2*i+1 < N; i = replChild)	//i = replChild���������ִ��֮��ִ�е�
	{
		if (2 * i + 1 != N - 1 && A[2 * i + 1] < A[2 * i + 1 + 1])//���Һ��Ӵ������Һ��Ӵ����Һ�������
			replChild = 2 * i + 1 + 1;
		if (2 * i + 1 != N - 1 && A[2 * i + 1] > A[2 * i + 1 + 1])//���Һ��Ӵ������Һ���С����������
			replChild = 2 * i + 1;
		if(2 * i + 1 == N - 1)		//���Һ��Ӳ���������������
				replChild = 2 * i + 1;

		//���Ϸ���
		//replChild = 2*i+1;
		//if (replChild != N - 1 && A[replChild + 1] > A[replChild])
		//	replChild++;

		//���㺢�ӱȸ������ݴ�,���������ݸ�ֵ��������,
		//���򣬲�����ѽṹ������Ҫ��������ѭ��
		if (tmp < A[replChild])
			A[i] = A[replChild];
		else
			break;
	}
	A[i] = tmp;
}

//������
void HeapSort(ElementType A[], int N)
{
	int i, temp;;

    //����С��Ԫ�ط��ڶ���Ѷ�λ�ã��������0λ��
	for (i = N / 2; i >= 0; i--)
        PercDown(A, i, N);
        
	for (i = N - 1; i > 0; i--)
	{	//�����������Ľڵ�����
		temp = A[0];
		A[0] = A[i];
		A[i] = temp;

		PercDown(A, 0, i);
	}
}







int main()
{
	int i;
	int a[10] = { 2, 4, 67, 12, 43, 78, 5, 3, 8, 65 };

    HeapSort(a, 10);
    
	for (i = 0; i < 10; i++)
		printf("%d,", a[i]);

    return 0;
}

