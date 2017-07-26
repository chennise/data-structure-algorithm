#include <iostream>
using namespace std;
#define N 10
int number[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int temp[N];
int total = 0;
void move(int a, int i)                /* 交换两个数 */
{
	int c;
	c = number[a];
	number[a] = number[i];
	number[i] = c;
}

void arrange(int b, int count)        /* 排列 */
{
	int i;
	if (count == 0)
	{
		++total;

		for (int i = 0; i < N; ++i)
		{
			cout << temp[i] << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		for (i = b; i < N; i++)
		{
			temp[b] = number[i];
			move(b, i);
			arrange(b + 1, count - 1);
			move(b, i);
		}
	}
}
void bmain()
{
	arrange(0, N);
	cout << "一共有" << total << "种组合" << endl;
}
