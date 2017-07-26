#include <iostream>
using namespace std;
typedef int elemtype;
typedef struct lnode{
	elemtype data;
	struct lnode *next;
}lnode,*linklist;

void mian(){
	linklist l=0; 	linklist la=0;	linklist lb=0;	linklist lc=0;
	linklist p;
	p = l->next;
	la->data = 3;
	lb->data = 4;
	lc->data = 6;

	l->next = la->next;
	la->next = lb->next;
	lb->next = lc->next;
	cout << p->next->next << endl;





}
