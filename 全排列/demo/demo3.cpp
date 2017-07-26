#include <stdio.h>
#include <string.h>

void convto(char *s, int n, int b)
{
	char bit[] = { "0123456789ABCDEF" };
	int len;
	if (n == 0)
	{
		s="";
		return;
		
	}
	convto(s, n / b, b);
	len = strlen(s);
	s[len] = bit[n%b];
	s[len + 1] = '\0';
 
}
int main(void){
	char s[80];
	int i, base, old;
	printf("请输入十进制数：");
	scanf_s("%d", &old);
	printf("请输入准换的精制");
	scanf_s("%d", &base);
	convto(s, old, base);
	getchar();
	return 0;


}