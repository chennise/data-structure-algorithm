#include "iostream"
using namespace std;
#include "stdio.h"
#define  ok 1;
#define  error 0;
typedef int elemtype;
typedef int status;
 struct list{
	elemtype *elem;
	
	int length;
	int listsize;

};
 status destroylist(list&l){
	 if (l.elem) free(l.elem);
		 l.elem = NULL;
		 l.length = 0;
		 l.listsize = 0;
		 printf("销毁列表！\n");
		 return ok;
 }
 status priorelem(list & l, elemtype e, elemtype &r){
	 int i = 2;
	 elemtype *p = l.elem + 1;
	 while (i < l.length&&e!=*p){ 
		 p++;
		 i++;
	 }
	 if (i > l.length) return -1;
	
	 else
	 {
		 r = *(--p);
		 return ok;
	 }

 }//返回前驱元素；
 status nextelem(list & l, elemtype e, elemtype *next){
	 int i = 1;
	 elemtype *p = l.elem + 1;
	 while (i < l.length&&e != *p){
		 p++;
		 i++;
	 }
	 if (i == l.length) return -1;

	 else
	 {
		 *next = *(p++);
		 return ok;
	 }
 }//返回后继元素
 status initlist(list&l){
	 l.elem = (elemtype*)malloc(1000 * sizeof(elemtype));
	 if (!l.elem) exit(OVERFLOW);
	 l.length = 0;
	 l.listsize = 10;
	 return ok ;
 }//构造空的线性表；
 status getelem(list l,int i,elemtype&e){
	 if (i<1 || i>l.length) return error;//i不合法；
	 e = l.elem[i - 1];
	 return 1;
 }
 status listinsert(list & l,int i,elemtype e){
	 if (i<1 || i>l.length+1) return error;//i不合法；
	 elemtype *p, *q, *r;
	 if (l.length >= l.listsize)
	 {
		 r = (elemtype*)realloc(l.elem, (l.listsize + 10)*sizeof(elemtype));
		 l.elem = r;
		 l.listsize += 10;
		 if (!l.elem) return OVERFLOW;
	 }
	 p = &l.elem[i - 1];
	 for (q = &l.elem[l.length - 1]; q >= p; --q)  *(q + 1) = *q;
	 *p=e;
	 ++l.length;
	 return ok;
 }//插入一个元素；
 status listdelete(list & l, int i, elemtype e){
	 if (i<1 || i>l.length ) return error;//i不合法；
	 elemtype *p, *q;
	 p = &l.elem[i - 1];
	 e = *p;
	 q = (l.elem + l.length - 1);
	 for (p++; q >= p; ++p)  *(p -1) = *p;
	 e = *p;
	--l.length;
	 return ok;
 }//删除元素；
 status locatelist(list l, elemtype e){
	 int i = 0;
	 while (i < l.length&&l.elem[i] != e)++i;
	 if (i < l.length)cout<<"所查找元素所在序号为："<< i + 1;
	 else return error;
	
 }//查找元素；
 /*void mergelist(list la, list lb, list &lc){
	 int i, j, k;
	 elemtype a,b;
	i = j = 1; k = 0;
	initlist(lc);
	while ((i < =la.length) && (j <= lb.length)){
		getelem(la, i, a); getelem(lb, j, b);
		if (a <= b){ listinsert(lc, ++k, a); ++i; }
		else{ listinsert(lc, ++k, b); ++j; }
	}
	while (i<=la.length){
		getelem(la, i++, a); listinsert(lc, k++, a);

	}
	while (i<=lb.length){
		getelem(lb, i++, b); listinsert(lb, k++, b);

	}
	lc.length = la.length + lb.length;

 }*/
 void Mergelist(list la, list lb, list &lc){
	 elemtype*a; elemtype*b; elemtype*c; elemtype*a1; elemtype*b1;
	 a = la.elem; b = lb.elem;
	 lc.listsize = lc.length = la.length + lb.length;
	 c = lc.elem = (elemtype*)malloc(lc.listsize*sizeof(elemtype));
	 if (!lc.elem)exit(OVERFLOW);
	 a1 = la.elem + la.length - 1;
	 b1 = lb.elem + lb.length - 1;
	 while (a <= a1&&b <= b1){
		 if (*a < *b){ *(c++) = *(a++); }
		 else if (*a = *b){ *(c++) = *(a++); b++; }
		 else *(c++) = *(b++);
	 }

	 while (a <= a1)*(c++) = *(a++);
	 while (b <= b1)*(c++) = *(b++);


 }
 status unionList(list LA, list LB, list&LC)
 {
	 int i, j, k;
	 elemtype ai, bj;
	 initlist(LC);
	 i = j = 1, k = 0;
	 int LA_len, LB_len;
	 LA_len =LA.length; LB_len = LB.length;
	 while ((i <= LA_len) && (j <= LB_len)){
		 getelem(LA, i, ai); getelem(LB, j, bj);
		 if (ai <= bj){
			 if (k != 1 || k != 0){
				 if (!locatelist(LC, ai)){
					 listinsert(LC, ++k, ai); ++i;
				 }
				 else{
					 ++i;
				 }
			 }
			 else{
				 listinsert(LC, ++k, ai); ++i;
			 }
		 }
		 else{
			 if (k != 1 || k != 0){
				 if (!locatelist(LC, bj)){
					 listinsert(LC, ++k, bj); ++j;
				 }
				 else{
					 ++j;
				 }
			 }
			 else{
				 listinsert(LC, ++k, bj); ++j;
			 }
		 }

	 }
	 while (i <= LA_len){
		 getelem(LA, i++, ai);
		 if (!locatelist(LC, ai)){
			 listinsert(LC, ++k, ai);
		 }
	 }
	 while (j <= LB_len){
		 getelem(LB, j++, bj);
		 if (!locatelist(LC, bj)){
			 listinsert(LC, ++k, bj);
		 }
	 }

	 return 1;
 }

 status in(list& l){
	 int n,m;
	 cout << "初始化元素个数为：";
	 cin >> n;
	 for (int i = 0; i < n; i++){
		 cout << "输入插入的数据:" ;
		 cin >> m;
		
		 l.elem[i] = m;
		 l.length++;
	 }
	 return 0;
 }
 status show(list l,int n ){
	 cout << "线性表为:";
	 for (int i = 1; i <= n; i++)
		
		 cout << l.elem[i - 1] << " ";

	 cout << endl<<"线性表长度为：" << l.length <<endl;
	 return 0;
 }
 void sort(list &l){
	
	 int temp = 0;
	 for (int i = 0; i < l.length - 1; i++)
	 {
		 for (int j = i + 1; j < l.length; j++)
		 {
			 if (l.elem[j] < l.elem[i])
			 {
				 temp = l.elem[i];
				l.elem[i] = l.elem[j];
				 l.elem[j] = temp;
			 }
		 }
	 }
 }

/* void find(list&l){
	 elemtype e=0;
	 int a = 0;
	 for (int i = 0; i < l.length; i++)
	 {
		 if (l.elem[i] = l.elem[i + 1])
			 listdelete(l, i-a, e); a++;
	 }
 }*/

void main(){

	
	list la,lb,lc;
	//elemtype e=0;
	//elemtype r;
	initlist(la);
	initlist(lb);
	in(la);
	show(la, la.length);
	sort(la);
	//listdelete(la, 2, e);
	//show(la, la.length);
	//getelem(la, 2, e); cout << "所取值为："<<e;
	//locatelist(la, 8);
	//destroylist(la); show(la, la.length);
	//priorelem(la, e,r); cout << r;
	in(lb);
	show(lb, lb.length);
	sort(lb);
	Mergelist(la, lb, lc);
	//unionList(la, lb, lc);
    //sort(lc);
	show(lc, lc.length);

	//find(lc);
	
	cout << "合并后的线性表为：" << endl;
show(lc, lc.length);

		/*cout << "输入插入的数据" << endl;
		cin >> k;
		cout << "输入插入的数据位置" << endl;
		cin >> j;
		listinsert(l, j, k);
	    show(l, l.len3
		gth);*/
}