#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
LARGE_INTEGER BegainTime;
LARGE_INTEGER EndTime;
LARGE_INTEGER Frequency;
int index(char *S, char *T, int pos);
int index_KMP(char *S, char *T, int pos);
void get_next(char *S, int *next);
int main(){
	char *str1 = " ahsdfasaasfababaaaba";  //主串
	char *str2 = " ababaaaba";   //匹配的子串
	int next[255];
	cout <<"简单匹配算法：" << endl;
	//检测函数的运行时间
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);
	int i = index(str1, str2, 0);
	cout << "子串的位置：" << i << endl;
	QueryPerformanceCounter(&EndTime);
	double runtime1 = (double)(EndTime.QuadPart - BegainTime.QuadPart);
	cout << "运行的时间：" << runtime1 << "微秒" << endl;
	cout << "KMP算法：" << endl;
	get_next(str2, next);
	//检测函数的运行时间
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);
	int j = index_KMP(str1, str2, 0);
	cout << "子串的位置：" << j << endl;
	QueryPerformanceCounter(&EndTime);
	double runtime2 = (double)(EndTime.QuadPart - BegainTime.QuadPart);
	cout << "运行的时间：" << runtime2 << "微秒" << endl;

	return 0;
}
//简单匹配算法
int index(char *S, char *T, int pos){
	int i = pos, j = 0;
	while (i<(int)strlen(S) && j<(int)strlen(T)){
		if (S[i] == T[j]){ ++i; ++j; }
		else{ i = i - j + 1; j = 0; }
	}
	if (j == (int)strlen(T)) return i - strlen(T) + 1;
	else return 0;
}

//KMP算法
void get_next(char *T, int *next)
{
	int i = 1, j = 0;
	next[0] = next[1] = 0;
	while (i<(int)strlen(T))
	{
		if (j == 0 || T[i] == T[j]){
			i++;
			j++;
			next[i] = j;

		}
		else j = next[j];
	}
}
int index_KMP(char *S, char *T, int pos) {
	int i = pos, j = 1;
	int next[255];
	get_next(T, next);
	while (i <= (int)strlen(S) && j <= (int)strlen(T)){
		if (j == 0 || S[i] == T[j - 1]) //继续进行后续字符串的比较
		{
			i++;
			j++;
		}
		else j = next[j]; //模式串向右移动
	}
	if (j>(int)strlen(T)) //匹配成功
		return i - strlen(T) + 1;
	else //匹配不成功 
		return 0;
}
