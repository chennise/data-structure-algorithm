#include<stdio.h> /*向有序的数组中插入一个数使该数组仍有序*/
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
				t1 = a[i]; //先保存当前位置的值
				a[i] = num; //插入数值
				for (j = i + 1; j<N; j++)
				{ //以下三行将插入位置之后的数依次向后移动
					t2 = a[j];
					a[j] = t1;
					t1 = t2;
				}
				break; //找到合适的位置后就终止外层循环
			}
	}
}

//int main()
//{
//	int a[n] = { 5, 10, 20, 50 };
//	int i = 0;
//	int num;
//
//	printf("原数组：");
//	for (i = 0; a[i] != '\0'; i++)
//		printf("%d\t", a[i]);
//
//	printf("\n输入要插入的数：");
//	scanf_s("%d", &num);
//
//	sort(a, num);
//	printf("新的数组：");
//	for (i = 0; i<n; i++)
//		printf("%d\t", a[i]);
//	printf("\n");
//	return 0;
//}