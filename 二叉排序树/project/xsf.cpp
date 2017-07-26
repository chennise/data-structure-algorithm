#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <time.h>
#include <stdlib.h>
using namespace std;

//�����������Ľ�㶨��
typedef int KeyType;
typedef struct Node
{
	KeyType number;
	string name;
	int grade;
	struct Node *left;    //����ָ��
	struct Node *right;	  //�Һ���ָ��
	struct Node *parent;  //ָ�򸸽ڵ�ָ��
}Node, *PNode;

//������
void insert(PNode *root, KeyType number, string name, int grade)
{
	PNode p = (PNode)malloc(sizeof(Node));
	p->number = number;
	p->left = p->right = p->parent = NULL;
	//��Ϊ��ʱ��ֱ����Ϊ���ڵ�
	if ((*root) == NULL)
	{
		*root = p;
		return;
	}
	//��keyС��*root->key,����뵽��ǰ�ڵ������
	if ((*root)->left == NULL && (*root)->number>number)
	{
		p->parent = (*root);
		(*root)->left = p;
		return;
	}
	//��key����*root->key,����뵽��ǰ�ڵ���Һ���
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

//���ҽ�� 
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

//������С�ؼ���,����ʱ����NULL  
PNode searchMin(PNode root)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL)
		return root;
	else  //һֱ�������ң�ֱ��û�����ӵĽ��  
		return searchMin(root->left);
}

//����ĳ�����ĺ��  
PNode searchSuccessor(PNode p)
{
	//����  
	if (p == NULL)
		return p;
	//��������������������С���Ǹ�  
	if (p->right)
		return searchMin(p->right);
	//��������,����ĳ��������������������  
	else{
		if (p->parent == NULL)
			return NULL;
		//����Ѱ�Һ��  
		while (p){
			if (p->parent->left == p)
				break;
			p = p->parent;
		}
		return p->parent;  
	}
}


//ɾ����㣬�ɹ�����1�����򷵻�0
int deleteNode(PNode *root, KeyType number)
{
	PNode q;
	PNode p = search(*root, number);   //����Ҫɾ���Ľ��
	KeyType temp;

	//û���ҵ�Ҫɾ���Ľ��
	if (!p){
		cout << "�Ҳ�����Ԫ��!" << endl;
		return 0;
	}
	//��ɾ�����Ҷ�ӽ�㣬ֱ��ɾ��
	if (p->left == NULL&&p->right == NULL)
	{
		//ֻ��һ��Ԫ�أ�ɾ��֮����һ�ſ���
		if (p->parent == NULL)
		{
			free(p);
			(*root) = NULL;
		}
		else
		{
			//ɾ���Ľ���Ǹ��ڵ������
			if (p->parent->left == p)
			{
				p->parent->left = NULL;
			}
			//ɾ���Ľ���Ǹ��ڵ���Һ���
			else
			{
				p->parent->right = NULL;
			}
			free(p);
		}
	}

	//��ɾ���ֻ��������
	else if (p->left&& !(p->right))
	{
		p->left->parent = p->parent;
		//���ɾ���Ǹ���㣬Ҫ�ı丸�ڵ�ָ��  
		if (p->parent == NULL)
		{
			*root = p->left;
		}
		//ɾ���Ľ���Ǹ��ڵ������  
		else if (p->parent->left == p)  
		{
			p->parent->left = p->left;
		}
		//ɾ���Ľ���Ǹ��ڵ���Һ���  
		else
		{
			p->parent->right = p->left;
		}
		free(p);
	}

	//��ɾ���ֻ���Һ���
	else if (p->right && !(p->left)){
		p->right->parent = p->parent;
		//���ɾ���Ǹ���㣬Ҫ�ı丸�ڵ�ָ��  
		if (p->parent == NULL)
		{
			*root = p->right;
		}
		//ɾ���Ľ���Ǹ��ڵ������  
		else if (p->parent->left == p)
		{
			p->parent->left = p->right; 
		}
		else //ɾ���Ľ���Ǹ��ڵ���Һ���  
		{
			p->parent->right = p->right;
		}
		free(p);
	}
	//��ɾ���Ľ��������ӣ������Һ���  
	else{
		//�ҵ�Ҫɾ�����ĺ��  
		q = searchSuccessor(p);
		temp = q->number;
		//ɾ����̽��  
		deleteNode(root, q->number);
		p->number = temp;
	}
	return 1;
}



//ǰ�����
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

//�������
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

//�������
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

//����һ�Ŷ���������
void create(PNode* root, Node *keyArray, int length)
{
	int i;
	//����������������  
	for (i = 0; i<length; i++)
		insert(root, keyArray[i].number, keyArray[i].name, keyArray[i].grade);
}

// ��״���
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
	cout << "1.��״��ʾѧ�Ŷ���������" << endl;
	cout << "2.������" << endl;
	cout << "3.ɾ�����" << endl;
	cout << "4.�ǵݹ����" << endl;
	cout << "5.����Ч�ʶԱ�" << endl;
	cout << "��ѡ��:";
}



int main(){
	int i, j, k, g, num;  //������ӡ�ɾ��������ѧ�����
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
		
			cout << "������������ѧ����ѧ��-->";
			cin >> j;
			cout << "������������ѧ��������-->";
			cin >> name;
			cout << "������������ѧ���ĳɼ�-->";
			cin >> g;
			insert(&root, j, name, g);
			cout << endl;
			PrintBST(root, 1);
			break;
		case 3:
			
			cout << "������Ҫɾ��ѧ����ѧ��-->";
			cin >> k;
			deleteNode(&root, k);
			cout << endl;
			PrintBST(root, 1);
			break;
		case 4:
			
			cout << "�ǵݹ��������:";
			PreOder(root); cout << endl;
			cout << "�ǵݹ��������:";
			MidOrder(root); cout << endl;
			cout << "�ǵݹ�������:";
			PostOrder(root); cout << endl;
			PrintBST(root, 1);
			break;
		case 5:
			
			cout << "������Ҫ���ҵ�ѧ��ѧ��-->";
			cin >> num;

			clock_t  clockBeginT, clockEndT;
			cout << "---����������---" << endl;
			clockBeginT = clock();
			while (time--){
				if (!search(root, num)){
					cout << "û�в��ҵ���" << endl;
					break;
				}
			}
			clockEndT = clock();
			cout << "�ö������������ҵ�ʱ��Ϊ��" << (clockEndT - clockBeginT) << "����" << endl;

			time = 10000000;
			clock_t  clockBeginA, clockEndA;
			cout << "---�������---" << endl;
			clockBeginA = clock();
			while (time--){
				if (!searchArray(nodeArray, num)){
					cout << "û�в��ҵ�" << endl;
					break;
				}
			}
			clockEndA = clock();
			cout << "��������ҵ�ʱ��Ϊ��" << (clockEndA - clockBeginA) << "����" << endl;
			break;
		case 0:
			cout << "ллʹ��!" << endl;
			return 1;
		default:
			cout << "������Ч!" << endl;
			cout << "������ѡ��";
		}
	}

	return 0;
}






