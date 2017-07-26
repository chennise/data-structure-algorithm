#include <stdio.h>
#define maxsize 20
typedef int datatype;
typedef  struct{
	datatype data[maxsize];
	int last;
}sequenlist;


void CreateList(sequenlist *L, int n)
{
	int i;
	printf("请你输入数据元素：\n");
	for (i = 0; i<n; i++)
	{
		scanf_s("%d", &(*L).data[i]);
	}
	(*L).last = n - 1;
}




void InsertaInteger(sequenlist *L, int c)
{
	int i, j, m;
	for (i = 0; i<(*L).last; i++)
	{
		if (c <= (*L).data[i])
		{
			m = i; break;
		}
	}
	(*L).last++;
	for (j = (*L).last; j >= m; j--)
	{
		(*L).data[j + 1] = (*L).data[j];
		(*L).data[m] = c;
	}
	(*L).last++;
	for (i = 0; i<(*L).last; i++)
		printf("%d  ", (*L).data[i]);
}



int main()
{
	int i, x;
	int a, c, n;
	sequenlist L;
	L.last = 0;
	printf("请你输入顺序表的长度:\n n=");
	scanf_s("%d", &n);
	CreateList(&L, n);                //调用顺序表的建立函数

	printf("\n请输入你要插入的数据元素C：");
	scanf_s("%d", &c);
	InsertaInteger(&L, c);
	getchar();
	getchar();
}