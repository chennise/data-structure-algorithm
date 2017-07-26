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

// �������ܣ���ȡ�����i������  �����������e����L�е�i������Ԫ�ص�ֵ
int GetElem(LinkList L, int i, ElemType &e)
{
	if (i <= 0)
	{
		return ERROR;
	}
	LinkList p = L->next;            //����һ���p
	int j = 1;                        //jΪ������
	while (j < i && p != NULL)        //p��Ϊ���Ҽ�����j��û�е���iʱ��ѭ������
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)                    //��i��Ԫ�ز�����
	{
		return ERROR;
	}
	e = p->data;
	return OK;
}


// ��������: ListInsert  ��������: ������ĵ�i��λ��֮ǰ��������Ԫ��e
int LinkInsert(LinkList &L, int i, ElemType e)
{
	if (i <= 0)
	{
		return ERROR;
	}
	LinkList p;
	p = L;
	int j = 1;
	while (j < i && p != NULL)            //Ѱ�ҵ�i�����
	{
		p = p->next;//�ؼ�����
		++j;
	}
	if (!p || j > i)                        //��i����㲻����
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

// ��������: ListDelete  ��������: ɾ��L�еĵ�i��Ԫ�أ�����e������ֵ
int ListDelete(LinkList &L, int i, ElemType *e)
{
	if (i <= 0)
	{
		return ERROR;
	}
	LinkList p, q;
	p = L;
	int j = 1;
	while (j < i && p->next != NULL)        //����Ѱ�ҵ�i�����
	{
		p = p->next;
		++j;
	}
	if (p->next == NULL || j > i)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;//�ؼ�����
	*e = q->data;
	free(q);
	return OK;
}

// ��������: CreateList    
int CreateList(LinkList &L, int n)
{
	LinkList p;
	int i = 1,a;
	L = (LinkList)malloc(sizeof(struct Node));        //�Ƚ���һ����ͷ���ĵ�����
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
		L->next = p;                                    //���뵽��ͷ
		i++;
	}

	return OK;
}

// ��������: ClearList   ��������: ������ɾ��
int ClearList(LinkList &L)
{
	if (L == NULL)
	{
		return ERROR;
	}
	LinkList q, p;
	p = L->next;        //pָ���һ�����
	while (p)            //û�е���β��
	{
		q = p->next;    //ע��Ŷ
		free(p);
		p = q;
	}
	L->next = NULL;    //ͷ���ָ����Ϊ��
	return OK;
}
int show(LinkList L)
{
	LinkList p;
	p = L->next;
	if (p == NULL)
	{
		cout<<"����Ϊ��"<<endl;
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
	cout<<"������������Ϊ:"<<endl;
	cout << "�����ʼ��Ԫ�ظ���:";
	cin >> n;
	CreateList(L, n);
	show(L);

	cout<<"�ڵ�3��λ��֮ǰ����Ԫ��10����Ϊ:";
	LinkInsert(L,3, 10);
	show(L);

	int e;
	GetElem(L, 3, e);
	cout<<"�����3��λ�õ�Ԫ��Ϊ:"<<e;

	cout<<"ɾ����3��λ�õ�Ԫ�غ���Ϊ"<<endl;
	ListDelete(L, 3, &e);
	show(L);

cout<<"�������:"<<endl;
	ClearList(L);
	show(L);

	return 0;
}