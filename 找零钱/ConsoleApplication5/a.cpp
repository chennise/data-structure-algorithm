#include <stdio.h>
int value[9] = {10000,5000,1000,500,100,50,20,10};
int num[9] = { 0 };
int exchange(int n){
	int i, j;
	for (i = 0; i < 9; i++){
		if (n > value[i]) break;
	}
	while (n>0&&i<9){
		if (n >= value[i]){
			n -= value[i];
			num[i]++;
		}
		else if (n < 10 && n >= 5){
			num[9 - 1]++;
			break;
		}
		else ++i;
	
	}

	return 0;
}
int main(){
	int i;
	float m;
	printf("请输入要找零的金额：");
	scanf_s("%f", &m);
	exchange((int)100 * m);

	printf("\n%.2f元零钱的组成：\n", m);
	for (i = 0; i < 9; i++){
		if (num[i] > 0)
			printf("%6.2f:%d张 \n", (float)value[i] / 100.0, num[i]);
		
	}

	return 0;
}