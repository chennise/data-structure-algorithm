#include<stdio.h>
#include<string.h>
#define MaxSize 100
typedef struct
{
	char data[MaxSize];
	int length;
}SqString;
void StrAssign(SqString &s, char cstr[]){
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}
void DispStr(SqString s)
{
	int i;
	if (s.length > 0){
		for (i = 0; i < s.length; i++)
			printf("%c", s.data[i]);
		printf("\n");
	}
}
int Index(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length&&j < t.length)
	{
		if (s.data[i] == t.data[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length)
		return(i - t.length);
	else
		return (-1);
}
void GetNextval(SqString t, int nextval[]){
	int j = 0, k = -1;
	nextval[0] = -1;
	while (j < t.length){
		if (k == -1 || t.data[j] == t.data[k]){
			j++; k++;
			if (t.data[j] != t.data[k])
				nextval[j] = k;
			else
				nextval[j] = nextval[k];
		}
		else
			k = nextval[k];
	}
}
int KMPIndex(SqString s, SqString t){
	int nextval[MaxSize], i = 0, j = 0;
	GetNextval(t, nextval);
	while (i < s.length &&j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j]){
			i++; j++;
		}
		else
			j = nextval[j];

	}
	if (j >= t.length)
		return(i - t.length);
	else
		return(-1);
}
void main(){
	int j;
	int nextval[MaxSize];
	SqString s, t;
	StrAssign(s, "abcabcdabcdeabcdefabcdefg");
	StrAssign(t, "abcdeabcdefab");
	printf("主串s: "); DispStr(s);
	printf("子串t: "); DispStr(t);
	printf("简单匹配算法：\n");
	printf("t在s中的位置= %d\n", Index(s, t));

	GetNextval(t, nextval);
	printf("    j   ");
	for (j = 0; j < t.length; j++)
		printf("%4d", j);
	printf("\n");
	printf("  t[j]  ");
	for (j = 0; j < t.length; j++)
		printf("%4c", t.data[j]);
	printf("\n");
	printf(" nextval");
	for (j = 0; j < t.length; j++)
		printf("%4d", nextval[j]);
	printf("\n");
	printf("KMP算法：\n");
	printf("t在s中的位置= %d\n", KMPIndex(s, t));
}