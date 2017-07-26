#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h> 
#include <time.h>

struct node
{
	long  data; //存放数据的一个或者多个项 
	long count;
	struct node *pLeft;  //左孩子 指向一个二叉树
	struct node *pRight; //右孩子  指向一个二叉树
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
	//情况一 pNode==NULL
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
		else return AddNode(pNode->pRight, v); //递归调用
	}

	if (v<pNode->data)
	{
		if (pNode->pLeft == NULL)
		{
			pNode->pLeft = CreateNode(v);
			return pNode->pLeft;
		}
		else return AddNode(pNode->pLeft, v); //递归调用
	}

	return NULL;
}
int main(void)
{
	struct node*root;
	long v, i;
	printf("请输入二叉树根结点数值：");
	scanf_s("%d", &v);
	root = CreateNode(v);
	for (i = 0; i <= 10; i++)
	{
		AddNode(root, i);
	}

	getchar();
	return 0;
}
