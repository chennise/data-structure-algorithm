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
	char *str1 = " ahsdfasaasfababaaaba";  //����
	char *str2 = " ababaaaba";   //ƥ����Ӵ�
	int next[255];
	cout <<"��ƥ���㷨��" << endl;
	//��⺯��������ʱ��
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);
	int i = index(str1, str2, 0);
	cout << "�Ӵ���λ�ã�" << i << endl;
	QueryPerformanceCounter(&EndTime);
	double runtime1 = (double)(EndTime.QuadPart - BegainTime.QuadPart);
	cout << "���е�ʱ�䣺" << runtime1 << "΢��" << endl;
	cout << "KMP�㷨��" << endl;
	get_next(str2, next);
	//��⺯��������ʱ��
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);
	int j = index_KMP(str1, str2, 0);
	cout << "�Ӵ���λ�ã�" << j << endl;
	QueryPerformanceCounter(&EndTime);
	double runtime2 = (double)(EndTime.QuadPart - BegainTime.QuadPart);
	cout << "���е�ʱ�䣺" << runtime2 << "΢��" << endl;

	return 0;
}
//��ƥ���㷨
int index(char *S, char *T, int pos){
	int i = pos, j = 0;
	while (i<(int)strlen(S) && j<(int)strlen(T)){
		if (S[i] == T[j]){ ++i; ++j; }
		else{ i = i - j + 1; j = 0; }
	}
	if (j == (int)strlen(T)) return i - strlen(T) + 1;
	else return 0;
}

//KMP�㷨
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
		if (j == 0 || S[i] == T[j - 1]) //�������к����ַ����ıȽ�
		{
			i++;
			j++;
		}
		else j = next[j]; //ģʽ�������ƶ�
	}
	if (j>(int)strlen(T)) //ƥ��ɹ�
		return i - strlen(T) + 1;
	else //ƥ�䲻�ɹ� 
		return 0;
}
