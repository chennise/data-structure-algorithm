# include "iostream"
using namespace std;
# include <stdio.h>
typedef struct complex{
	float realpart;
	float imagepart;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
};

complex complexadd(complex c1, complex c2, complex &c3){
	c3.realpart = c1.realpart + c2.realpart;
	c3.imagepart = c1.imagepart + c2.imagepart;
	return c3;
}
complex complexsub(complex c1, complex c4, complex &c3){
	//complex c4;
	//c4.realpart = -c2.realpart;
	//c4.imagepart =-c2.imagepart;
	c3.realpart = c1.realpart - c4.realpart;
	c3.imagepart = c1.imagepart - c4.imagepart;
	return c3;
}
void main(){
	complex c1,c2,c3;
	c1.realpart = 2.2, c1.imagepart = 3.2;
	c2.realpart = 2.2, c2.imagepart = 3.2;
	complexadd(c1, c2, c3);
	cout << c3.realpart << "+" << c3.imagepart << "i"<<endl;
	complexsub(c1, c2, c3);
	cout << c3.realpart << "+" << c3.imagepart << "i" << endl;

}
