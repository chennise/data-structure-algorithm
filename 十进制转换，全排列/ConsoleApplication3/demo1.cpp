#include <stdio.h>
#include <string.h>

void convto(int n, int b)
{
	int c;
	if (n == 0)
	{
	
		return;

	}
	else{
		convto(n / b, b);
		c = n%b;
		printf("%d",c );
	}

}
int main(void){
	int base, old;
	printf("������ʮ��������");
	scanf_s("%d", &old);
	printf("������׼���ľ���");
	scanf_s("%d", &base);
	convto( old, base);
	getchar();
	return 0;


}