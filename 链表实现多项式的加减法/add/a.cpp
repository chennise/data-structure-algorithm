#include<iostream>
using namespace std;
typedef struct node
{
	int coaf, expn;
	struct node *next;
}node, *link;
void create(link &head)
{
	link p;
	int x, y;
	head = (link)malloc(sizeof(node));
	p = head;
	cout<<"ϵ�� ָ��(������ϵ��Ϊ0ʱ���������)"<<endl;        
	cin >> x;
	
	if (x != 0){
		cin >> y;
		while (x != 0 || y != 0)
		{
			p->next = (link)malloc(sizeof(node));
			p = p->next;
			p->coaf = x;
			p->expn = y;
			cout << "ϵ�� ָ��(������ϵ��Ϊ0ʱ���������)" << endl;
			cin >> x; if (x ==0) break;
			cin >> y;
		}
	}
	p->next = NULL;
	cout<<"�������"<<endl;         
}
void add(link &A, link &B)
{
	link p, q, a, b;
	p = A->next;
	q = A;
	a = B->next;
	while (p&&a)
	{
		if (p->expn < a->expn)
		{
			q = p;
			p = p->next;
		}
		else if (p->expn > a->expn)
		{
			a->coaf = -a->coaf;
			b =a->next;
			a->next = q->next;
			q->next = a;
			q = a;
			a = b;
		}
		else if (p->expn == a->expn || p->expn ==- a->expn)
		{
			int x;
			x = p->coaf + a->coaf;
			
			if (x == 0)
			{
				q->next = q->next->next;
				free(p);
				q =q->next;
				if (q != NULL) {
					p = q->next;   
				}
				else {
					p = NULL;
				}

			}
			else {
				p->coaf = x;
				q = p;                //pҲҪǰ�� 
				p = p->next;
			      }
			b = a;
			a = a->next;
			free(b);
		}
	}
	if (a) q->next = a;
}
void jianfa(link &A, link &B)
{
	link p, q, a, b;
	p = A->next;
	q = A;
	a = B->next;
	while (p&&a)
	{
		if (p->expn < a->expn)
		{
			q = p;
			p = p->next;
		}
		else if (p->expn > a->expn)
		{
			b =a->next;
			a->next = q->next;
			q->next = a;
			q = a;//
			a = b;
		}
		
		else if (p->expn == a->expn||p->expn == -a->expn)
		{
			int x;
			x = p->coaf - a->coaf;

			if (x == 0)
			{
				q->next = q->next->next;
				free(p);
				q = q->next;
				if (q != NULL) {
					p = q->next;
				}
				else {
					p = NULL;
				}

			}
			else {
				p->coaf = x;
				q = p;               
				p = p->next;
			}
			b = a;
			a = a->next;
			free(b);
		}
	}
	if (a) q->next = a;
}

void chengfa(link &A, link &B)
{
	
		link p1 = A->next, t;

		t = (link)malloc(sizeof(node));
		t->next = NULL;

		while (p1) {
			link p2 = B->next, L, q;

			L = (link)malloc(sizeof(node));
			L->next = NULL;
			q = L;

			while (p2) {
				link r = (link)malloc(sizeof(node));
				r->next = NULL;

				r->coaf = p1->coaf * p2->coaf;
				r->expn = p1->expn + p2->expn;
				L->next = r;
				L = L->next;
				p2 = p2->next;
			}

			add(t, q);
			A = t;
			p1 = p1->next;
		}
		
	}
void show(link head)
{
	link p = head->next;   
	cout << "������Ϊ";
	while (p)
	{
		cout<<p->coaf<<"X^"<<p->expn;    
		
		p = p->next;
		if (p) cout << "+";
	}
	cout<<"�������"<<endl;    
}
void main()
{
	link A, B;
	int a;
	
		cout << "�봴��A:";
		create(A);
		show(A);
		cout << "�봴��B:";
		create(B);
		show(B);
		
			cout << "������Ҫִ�еĲ���" << endl << "1 �ӷ�" << endl << "2 ����" << endl << "3 �˷�" << endl << "0 ȡ��" << endl;
			cin >> a;
			switch (a)
			{
			case 1:add(A, B);
				show(A); break;

			case 2:jianfa(A, B);
				show(A); break;
			case 3:chengfa(A, B);
				show(A); break;

			default:
				break;
			}
			


		}
		
	
