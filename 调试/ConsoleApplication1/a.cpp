#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h> 
#include <time.h>

struct node
{
	long  data; //������ݵ�һ�����߶���� 
	long count;
	struct node *pLeft;  //���� ָ��һ��������
	struct node *pRight; //�Һ���  ָ��һ��������
};

struct node * CreateNode(long value)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->pLeft = p->pRight = NULL;
	p->data = value;
	p->count = 1;
	return p;
}
struct node * AddNode(struct node * pNode, long v)
{
	//���һ pNode==NULL
	if (pNode == NULL)
	{
		return CreateNode(v);
	}
	// pNode->data=v
	if (pNode->data == v)
	{
		pNode->count++;
		return pNode;
	}
	if (v>pNode->data)
	{
		if (pNode->pRight == NULL)
		{
			pNode->pRight = CreateNode(v);
			return pNode->pRight;
		}
		else return AddNode(pNode->pRight, v); //�ݹ����
	}

	if (v<pNode->data)
	{
		if (pNode->pLeft == NULL)
		{
			pNode->pLeft = CreateNode(v);
			return pNode->pLeft;
		}
		else return AddNode(pNode->pLeft, v); //�ݹ����
	}

	return NULL;
}
int main(void)
{
	struct node*root;
	long v, i;
	printf("������������������ֵ��");
	scanf_s("%d", &v);
	root = CreateNode(v);
	for (i = 0; i <= 10; i++)
	{
		AddNode(root, i);
	}

	getchar();
	return 0;
}
