#include <iostream>
using namespace std;

#define OK 0
#define ERROR 1
#define ElemType int
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node, *LinkList;

// 函数功能：获取链表第i个数据  操作结果：用e返回L中第i个数据元素的值
int GetElem(LinkList L, int i, ElemType &e)
{
	if (i <= 0)
	{
		return ERROR;
	}
	LinkList p = L->next;            //声明一结点p
	int j = 1;                        //j为计数器
	while (j < i && p != NULL)        //p不为空且计数器j还没有等于i时，循环继续
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)                    //第i个元素不存在
	{
		return ERROR;
	}
	e = p->data;
	return OK;
}


// 函数名称: ListInsert  函数功能: 在链表的第i个位置之前插入数据元素e
int LinkInsert(LinkList &L, int i, ElemType e)
{
	if (i <= 0)
	{
		return ERROR;
	}
	LinkList p;
	p = L;
	int j = 1;
	while (j < i && p != NULL)            //寻找第i个结点
	{
		p = p->next;//关键代码
		++j;
	}
	if (!p || j > i)                        //第i个结点不存在
	{
		return ERROR;
	}
	LinkList temp = (LinkList)malloc(sizeof(struct Node));
	if (!temp)
	{
		return ERROR;
	}
	temp->data = e;
	temp->next = p->next;
	p->next = temp;
	return OK;
}

// 函数名称: ListDelete  函数功能: 删除L中的第i个元素，并用e返回其值
int ListDelete(LinkList &L, int i, ElemType *e)
{
	if (i <= 0)
	{
		return ERROR;
	}
	LinkList p, q;
	p = L;
	int j = 1;
	while (j < i && p->next != NULL)        //遍历寻找第i个结点
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;//关键代码
	*e = q->data;
	free(q);
	return OK;
}

// 函数名称: CreateList    
int CreateList(LinkList &L, int n)
{
	LinkList p;
	int i = 1,a;
	L = (LinkList)malloc(sizeof(struct Node));        //先建立一个带头结点的单链表
	if (L == NULL)
	{
		return ERROR;
	}
	L->next = NULL;
	while (i <= n)
	{
		p = (LinkList)malloc(sizeof(struct Node));
		if (p == NULL)
			return ERROR;
		cin >> a;
		p->data = a;
		p->next = L->next;
		L->next = p;                                    //插入到表头
		i++;
	}

	return OK;
}

// 函数名称: ClearList   函数功能: 单链表删除
int ClearList(LinkList &L)
{
	if (L == NULL)
	{
		return ERROR;
	}
	LinkList q, p;
	p = L->next;        //p指向第一个结点
	while (p)            //没有到表尾部
	{
		q = p->next;    //注意哦
		free(p);
		p = q;
	}
	L->next = NULL;    //头结点指针域为空
	return OK;
}
int show(LinkList L)
{
	LinkList p;
	p = L->next;
	if (p == NULL)
	{
		cout<<"链表为空"<<endl;
		return ERROR;
	}
	while (p)
	{
		cout<< p->data<<" ";
		p = p->next;
	}
	return OK;
}

int main(int argc, char **argv)
{
	int n;
	LinkList L;
	cout<<"创建的新链表为:"<<endl;
	cout << "输入初始化元素个数:";
	cin >> n;
	CreateList(L, n);
	show(L);

	cout<<"在第3个位置之前插入元素10后结果为:";
	LinkInsert(L,3, 10);
	show(L);

	int e;
	GetElem(L, 3, e);
	cout<<"链表第3个位置的元素为:"<<e;

	cout<<"删除第3个位置的元素后结果为"<<endl;
	ListDelete(L, 3, &e);
	show(L);

cout<<"清空链表:"<<endl;
	ClearList(L);
	show(L);

	return 0;
}