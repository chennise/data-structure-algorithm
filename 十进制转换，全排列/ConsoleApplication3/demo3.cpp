#include <stdio.h>
#include <string.h>
#define max 64
int a[max + 1][max +1] = { 0 };
void game(int k, int n){
	int i, j;
	if (n == 2){
		a[k][1] = k;
		a[k][2] = k + 1;
		a[k + 1][1] = k + 1;
		a[k + 1][2] = k;
	
	}
	else{
		game(k, n / 2);
		game(k + n / 2, n / 2);
		for (i = k; i < k + n / 2; i++){
			for (j = n / 2 + 1; j <= n; j++)
			{
				a[i][j] == a[k + n / 2][j - n / 2];
			}
		}
			for (i = k + n / 2; i < k + n; i++){
				for (j = n / 2 + 1; j <= n;j++)
				{
					a[i][j] = a[i - n / 2][j - n / 2];
				}
			
			}	
	}

}
int amain(){
	int i,j;
	game(1, 8);
	for (i = 2; i <= 8; i++){
		for (j = 1; j <= 8; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return 0;


}