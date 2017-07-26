#include <iostream>
using namespace std;
int a[10] = { 0,1,2,3 ,4,5,6,7,8,9};
int b = 0;
void amain()
{
	int i, j, k;

	for (i = 0; i < 10; i++)
		for (j = 1; j <10 && i != j; j++)
			for (k = 2; k < 10 && k != i&&k != j; k++){
				cout << a[i]<< "" << a[j] << "" <<a[ k] << " ";
				b++;

			}
	cout << "一共有" << b << "种组合" << endl;
}