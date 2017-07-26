#include<iostream>
using namespace std;
#define N 100
void prin(int i);
void fun(int n);
int p[N], a[N];

void main()
{
	int i, n;
	cout << "input n:";
	cin >> n;
	cout << "input the array.\n";
	for (i = 0; i<n; i++)
		cin >> a[i];
	fun(n);

}
void fun(int n)
{
	int m[N];
	int i, k, max;
	m[0] = 1;
	p[0] = -1;
	for (i = 1; i<n; i++)
	{
		max = 0;
		p[i] = -1;
		for (k = 0; k<i; k++)
		{
			if (m[k]>max&&a[k]<a[i])
			{
				p[i] = k;
				max = m[k];
			}
		}
		m[i] = max + 1;
	}
	i = 0;
	for (k = 1; k<n; k++)
	{
		if (m[k]>m[i])
		{
			i = k;
		}
	}
	cout << "最长单调递增子序列：";
	prin(i);
	cout << "\nlen=" << m[i] << endl;

}
void prin(int i)
{
	if (p[i]<0)
	{
		cout << a[i];
		return;
	}
	prin(p[i]);
	cout << "," << a[i];
}
