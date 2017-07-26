#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <time.h>
#include <stdlib.h>
using namespace std;

//二叉排序树的结点定义
typedef int KeyType;
typedef struct Node
{
	KeyType number;
	string name;
	int grade;
	struct Node *left;    //左孩子指针
	struct Node *right;	  //右孩子指针
	struct Node *parent;  //指向父节点指针
}Node, *PNode;

//插入结点
void insert(PNode *root, KeyType number, string name, int grade)
{
	PNode p = (PNode)malloc(sizeof(Node));
	p->number = number;
	p->left = p->right = p->parent = NULL;
	//树为空时，直接作为根节点
	if ((*root) == NULL)
	{
		*root = p;
		return;
	}
	//若key小于*root->key,则插入到当前节点的左孩子
	if ((*root)->left == NULL && (*root)->number>number)
	{
		p->parent = (*root);
		(*root)->left = p;
		return;
	}
	//若key大于*root->key,则插入到当前节点的右孩子
	if ((*root)->right == NULL && (*root)->number<number)
	{
		p->parent = (*root);
		(*root)->right = p;
		return;
	}
	if ((*root)->number>number)
		insert(&(*root)->left, number, name, grade);
	else if ((*root)->number<number)
		insert(&(*root)->right, number, name, grade);
	else
		return;
}

//查找结点 
PNode search(PNode root, KeyType number)
{
	if (root == NULL)
		return NULL;
	if (number > root->number)
		return search(root->right, number);
	else if (number<root->number)
		return search(root->left, number);
	else
		return root;
}

//查找最小关键字,空树时返回NULL  
PNode searchMin(PNode root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	else  //一直往左孩子找，直到没有左孩子的结点  
		return searchMin(root->left);
}

//查找某个结点的后继  
PNode searchSuccessor(PNode p)
{
	//空树  
	if (p == NULL)
		return p;
	//有右子树、右子树中最小的那个  
	if (p->right)
		return searchMin(p->right);
	//无右子树,查找某个结点的左子树遍历完了  
	else{
		if (p->parent == NULL)
			return NULL;
		//向上寻找后继  
		while (p){
			if (p->parent->left == p)
				break;
			p = p->parent;
		}
		return p->parent;  
	}
}


//删除结点，成功返回1，否则返回0
int deleteNode(PNode *root, KeyType number)
{
	PNode q;
	PNode p = search(*root, number);   //查找要删除的结点
	KeyType temp;

	//没查找到要删除的结点
	if (!p){
		cout << "找不到该元素!" << endl;
		return 0;
	}
	//被删结点是叶子结点，直接删除
	if (p->left == NULL&&p->right == NULL)
	{
		//只有一个元素，删完之后变成一颗空树
		if (p->parent == NULL)
		{
			free(p);
			(*root) = NULL;
		}
		else
		{
			//删除的结点是父节点的左孩子
			if (p->parent->left == p)
			{
				p->parent->left = NULL;
			}
			//删除的结点是父节点的右孩子
			else
			{
				p->parent->right = NULL;
			}
			free(p);
		}
	}

	//被删结点只有左子树
	else if (p->left&& !(p->right))
	{
		p->left->parent = p->parent;
		//如果删除是父结点，要改变父节点指针  
		if (p->parent == NULL)
		{
			*root = p->left;
		}
		//删除的结点是父节点的左孩子  
		else if (p->parent->left == p)  
		{
			p->parent->left = p->left;
		}
		//删除的结点是父节点的右孩子  
		else
		{
			p->parent->right = p->left;
		}
		free(p);
	}

	//被删结点只有右孩子
	else if (p->right && !(p->left)){
		p->right->parent = p->parent;
		//如果删除是父结点，要改变父节点指针  
		if (p->parent == NULL)
		{
			*root = p->right;
		}
		//删除的结点是父节点的左孩子  
		else if (p->parent->left == p)
		{
			p->parent->left = p->right; 
		}
		else //删除的结点是父节点的右孩子  
		{
			p->parent->right = p->right;
		}
		free(p);
	}
	//被删除的结点既有左孩子，又有右孩子  
	else{
		//找到要删除结点的后继  
		q = searchSuccessor(p);
		temp = q->number;
		//删除后继结点  
		deleteNode(root, q->number);
		p->number = temp;
	}
	return 1;
}



//前序遍历
void PreOder(PNode MyTree)
{
	stack<PNode> stk;
	if (MyTree == NULL)
		return;
	stk.push(MyTree);
	cout << setw(5) << (MyTree->number);
	PNode left = MyTree->left;
	while (left)
	{
		stk.push(left);
		cout << setw(5) << ((*left).number); 
		left = left->left;
	}

	  while (!stk.empty())
	{
		PNode top = stk.top();
		stk.pop();
		if (top->right)
		{

			left = top->right;
			while (left)
			{
				cout << setw(5) << ((*left).number);
				stk.push(left);
				left = left->left;
			}

		}
	}
}

//中序遍历
void MidOrder(PNode MyTree)
{
	stack<PNode> stk;
	if (MyTree == NULL)
		return;
	stk.push(MyTree);
	PNode left = MyTree->left;
	while (left)
	{
		stk.push(left);
		left = left->left;
	}
	while (!stk.empty())
	{
		PNode top = stk.top();
		cout << setw(5) << top->number;
		top = top->right;
		stk.pop();
		while (top)
		{
			stk.push(top);
			top = top->left;
		}
	}
}

//后序遍历
void PostOrder(PNode MyTree)
{
	stack<PNode> stk, stk1;
	if (MyTree == NULL)
		return;
	stk.push(MyTree);

	PNode left = MyTree->left;
	while (left)
	{
		stk.push(left);
		left = left->left;
	}
	while (!stk.empty())
	{
		PNode top = stk.top();
		if (top->right == NULL)
		{
			cout << setw(5) << top->number;
			stk.pop();
		}
		else
		{
			if ((!stk1.empty()) && top == stk1.top())
			{
				cout << setw(5) << stk1.top()->number;
				stk.pop();
				stk1.pop();
				continue;
			}
			stk1.push(top);
			top = top->right;
			while (top)
			{
				stk.push(top);
				top = top->left;
			}

		}
	}
}

//创建一颗二叉排序树
void create(PNode* root, Node *keyArray, int length)
{
	int i;
	//逐个结点插入二叉树中  
	for (i = 0; i<length; i++)
		insert(root, keyArray[i].number, keyArray[i].name, keyArray[i].grade);
}

// 树状输出
void PrintBST(Node *T, int depth)
{
	int i;
	if (T->right)
		PrintBST(T->right, depth + 1);
	for (i = 1; i <= depth; i++)
		cout << "   ";
	cout << T->number << endl;
	if (T->left)
		PrintBST(T->left, depth + 1);
}
//void PrintBST(Node *T, int depth)
//{
//	int k;
//	if (T == NULL)
//		return;
//	PrintBST(T->right, depth + 1);
//	for (k = 0; k<depth; k++)
//		printf("	");
//	printf("%u\n", T->number);
//	PrintBST(T->left, depth + 1);
//}

int searchArray(Node stu[], KeyType number)
{
	for (int i = 0; i<6; i++)
	{
		if (stu[i].number == number)
			return 1;
	}
	return 0;
}


void show()
{
	cout << "1.树状显示学号二叉排序树" << endl;
	cout << "2.插入结点" << endl;
	cout << "3.删除结点" << endl;
	cout << "4.非递归遍历" << endl;
	cout << "5.查找效率对比" << endl;
	cout << "请选择:";
}



int main(){
	int i, j, k, g, num;  //用于添加、删除、查找学生结点
	string name;
	int time = 10000000;
	PNode root = NULL;
	Node nodeArray[50];
	nodeArray[0].number = 923; nodeArray[0].name = "hil"; nodeArray[0].grade = 79;
	nodeArray[1].number = 565; nodeArray[1].name = "hfq"; nodeArray[1].grade = 86;
	nodeArray[2].number = 120; nodeArray[2].name = "zhr"; nodeArray[2].grade = 98;
	nodeArray[3].number = 414; nodeArray[3].name = "gmn"; nodeArray[3].grade = 88;
	nodeArray[4].number = 626; nodeArray[4].name = "toc"; nodeArray[4].grade = 75;
	nodeArray[5].number = 250; nodeArray[5].name = "arq"; nodeArray[5].grade = 85;
	nodeArray[6].number = 711; nodeArray[6].name = "lgh"; nodeArray[6].grade = 80;
	nodeArray[7].number = 262; nodeArray[7].name = "drg"; nodeArray[7].grade = 99;
	nodeArray[8].number = 1; nodeArray[8].name = "wbb"; nodeArray[8].grade = 95;
	nodeArray[9].number = 156; nodeArray[9].name = "zbd"; nodeArray[9].grade = 83;
	nodeArray[10].number = 232; nodeArray[10].name = "pkq"; nodeArray[10].grade = 71;
	nodeArray[11].number = 37; nodeArray[11].name = "rlb"; nodeArray[11].grade = 86;
	nodeArray[12].number = 182; nodeArray[12].name = "lmm"; nodeArray[12].grade = 95;
	nodeArray[13].number = 416; nodeArray[13].name = "wbz"; nodeArray[13].grade = 95;
	nodeArray[14].number = 791; nodeArray[14].name = "zrd"; nodeArray[14].grade = 87;
	nodeArray[15].number = 490; nodeArray[15].name = "klb"; nodeArray[15].grade = 76;
	nodeArray[16].number = 75; nodeArray[16].name = "nma"; nodeArray[16].grade = 79;
	nodeArray[17].number = 500; nodeArray[17].name = "zyo"; nodeArray[17].grade = 90;
	nodeArray[18].number = 338; nodeArray[18].name = "tlp"; nodeArray[18].grade = 89;
	nodeArray[19].number = 169; nodeArray[19].name = "thn"; nodeArray[19].grade = 75;
	nodeArray[20].number = 99; nodeArray[20].name = "gjm"; nodeArray[20].grade = 80;
	nodeArray[21].number = 428; nodeArray[21].name = "zle"; nodeArray[21].grade = 94;
	nodeArray[22].number = 529; nodeArray[22].name = "slo"; nodeArray[22].grade = 94;
	nodeArray[23].number = 41; nodeArray[23].name = "ylw"; nodeArray[23].grade = 88;
	nodeArray[24].number = 987; nodeArray[24].name = "wac"; nodeArray[24].grade = 93;
	nodeArray[25].number = 162; nodeArray[25].name = "xjl"; nodeArray[25].grade = 85;
	nodeArray[26].number = 285; nodeArray[26].name = "sjb"; nodeArray[26].grade = 77;
	nodeArray[27].number = 195; nodeArray[27].name = "zbd"; nodeArray[27].grade = 84;
	nodeArray[28].number = 836; nodeArray[28].name = "kjh"; nodeArray[28].grade = 87;
	nodeArray[29].number = 289; nodeArray[29].name = "jbb"; nodeArray[29].grade = 99;
	nodeArray[30].number = 188; nodeArray[30].name = "pos"; nodeArray[30].grade = 81;
	nodeArray[31].number = 728; nodeArray[31].name = "nbg"; nodeArray[31].grade = 98;
	nodeArray[32].number = 89; nodeArray[32].name = "lxm"; nodeArray[32].grade = 74;
	nodeArray[33].number = 267; nodeArray[33].name = "wgc"; nodeArray[33].grade = 85;
	nodeArray[34].number = 111; nodeArray[34].name = "xsa"; nodeArray[34].grade = 85;
	nodeArray[35].number = 277; nodeArray[35].name = "lrt"; nodeArray[35].grade = 93;
	nodeArray[36].number = 14; nodeArray[36].name = "fex"; nodeArray[36].grade = 94;
	nodeArray[37].number = 204; nodeArray[37].name = "kpo"; nodeArray[37].grade = 83;
	nodeArray[38].number = 315; nodeArray[38].name = "orr"; nodeArray[38].grade = 75;
	nodeArray[39].number = 706; nodeArray[39].name = "dlp"; nodeArray[39].grade = 76;
	nodeArray[40].number = 211; nodeArray[40].name = "der"; nodeArray[40].grade = 79;
	nodeArray[41].number = 240; nodeArray[41].name = "zym"; nodeArray[41].grade = 85;
	nodeArray[42].number = 566; nodeArray[42].name = "qda"; nodeArray[42].grade = 88;
	nodeArray[43].number = 164; nodeArray[43].name = "lmq"; nodeArray[43].grade = 82;
	nodeArray[44].number = 68; nodeArray[44].name = "ldg"; nodeArray[44].grade = 91;
	nodeArray[45].number = 476; nodeArray[45].name = "fkk"; nodeArray[45].grade = 88;
	nodeArray[46].number = 985; nodeArray[46].name = "zxc"; nodeArray[46].grade = 93;
	nodeArray[47].number = 199; nodeArray[47].name = "zbg"; nodeArray[47].grade = 99;
	nodeArray[48].number = 382; nodeArray[48].name = "tnm"; nodeArray[48].grade = 73;
	nodeArray[49].number = 547; nodeArray[49].name = "qfa"; nodeArray[49].grade = 86;



	create(&root, nodeArray, 50);
	while (1){
		show();
		cin >> i;
		switch (i)
		{
		case 1:
			PrintBST(root, 1);	
			break;
		case 2:
		
			cout << "请输入所插入学生的学号-->";
			cin >> j;
			cout << "请输入所插入学生的姓名-->";
			cin >> name;
			cout << "请输入所插入学生的成绩-->";
			cin >> g;
			insert(&root, j, name, g);
			cout << endl;
			PrintBST(root, 1);
			break;
		case 3:
			
			cout << "请输入要删除学生的学号-->";
			cin >> k;
			deleteNode(&root, k);
			cout << endl;
			PrintBST(root, 1);
			break;
		case 4:
			
			cout << "非递归先序遍历:";
			PreOder(root); cout << endl;
			cout << "非递归中序遍历:";
			MidOrder(root); cout << endl;
			cout << "非递归后序遍历:";
			PostOrder(root); cout << endl;
			PrintBST(root, 1);
			break;
		case 5:
			
			cout << "请输入要查找的学生学号-->";
			cin >> num;

			clock_t  clockBeginT, clockEndT;
			cout << "---二叉树查找---" << endl;
			clockBeginT = clock();
			while (time--){
				if (!search(root, num)){
					cout << "没有查找到！" << endl;
					break;
				}
			}
			clockEndT = clock();
			cout << "用二叉排序树查找的时间为：" << (clockEndT - clockBeginT) << "毫秒" << endl;

			time = 10000000;
			clock_t  clockBeginA, clockEndA;
			cout << "---数组查找---" << endl;
			clockBeginA = clock();
			while (time--){
				if (!searchArray(nodeArray, num)){
					cout << "没有查找到" << endl;
					break;
				}
			}
			clockEndA = clock();
			cout << "用数组查找的时间为：" << (clockEndA - clockBeginA) << "毫秒" << endl;
			break;
		case 0:
			cout << "谢谢使用!" << endl;
			return 1;
		default:
			cout << "输入无效!" << endl;
			cout << "请重新选择：";
		}
	}

	return 0;
}






