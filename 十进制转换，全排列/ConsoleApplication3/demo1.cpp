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
	printf("请输入十进制数：");
	scanf_s("%d", &old);
	printf("请输入准换的精制");
	scanf_s("%d", &base);
	convto( old, base);
	getchar();
	return 0;


}