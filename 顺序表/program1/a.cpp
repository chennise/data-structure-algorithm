#include<stdio.h> /*������������в���һ����ʹ������������*/
#define N 5

void sort(int a[], int num)
{
	int i, j, t1, t2;
	int end = a[N - 2];
	if (num >= end)
		a[N - 1] = num;
	else
	{
		for (i = 0; i<N - 1; i++)
			if (a[i]>num)
			{
				t1 = a[i]; //�ȱ��浱ǰλ�õ�ֵ
				a[i] = num; //������ֵ
				for (j = i + 1; j<N; j++)
				{ //�������н�����λ��֮�������������ƶ�
					t2 = a[j];
					a[j] = t1;
					t1 = t2;
				}
				break; //�ҵ����ʵ�λ�ú����ֹ���ѭ��
			}
	}
}

//int main()
//{
//	int a[n] = { 5, 10, 20, 50 };
//	int i = 0;
//	int num;
//
//	printf("ԭ���飺");
//	for (i = 0; a[i] != '\0'; i++)
//		printf("%d\t", a[i]);
//
//	printf("\n����Ҫ���������");
//	scanf_s("%d", &num);
//
//	sort(a, num);
//	printf("�µ����飺");
//	for (i = 0; i<n; i++)
//		printf("%d\t", a[i]);
//	printf("\n");
//	return 0;
//}