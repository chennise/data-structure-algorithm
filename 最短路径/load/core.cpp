#include<iostream>
using namespace std;
#define maxsize  1000000//��ʾ����֮�䲻ͨ
#define n 7  //�ڵ����ĿΪ7��
void djstl(int A[][n], int v)//��ԭ��v�����ඥ�����̾��뼰�侭��·��
{
	int B[n], P[n], Q[n]; 			//B���ڼ�¼���㵽Դ��ľ���,P���ڼ�¼·����Q�������Ƿ�Ϊ���·���Ľ��
	int i, j, k, s, route;    //s��ʾԴ�㣬route��ʾ������·��
	int min, max = maxsize, road = 20160601;
	s = v - 1;
	for (i = 0; i<n; i++)
	{
		B[i] = A[s][i];   //��ʼ������ֵ
		if (B[i] != max)
			P[i] = v;
		else
			P[i] = 0;
	}
	for (i = 0; i<n; i++)
		Q[i] = 0;
	Q[s] = 1; B[s] = 0;
	for (i = 0; i<n - 1; i++)
	{
		min = road;
		for (j = 0; j<n; j++)   //�ڵ�ǰP��ѡ����ֵ��С�ĵ�k+1
		{
			if ((!Q[j]) && (B[j]<min))
			{
				min = B[j];
				k = j;
			}
		}
		Q[k] = 1;    //��k+1����Q
		for (j = 0; j<n; j++)
		{
			if ((!Q[j]) && (B[j]>B[k] + A[k][j]))
			{
				B[j] = B[k] + A[k][j];
				P[j] = k + 1;
			}
		}
	}

	for (i = 0; i<n; i++)
	{
		
		cout << "1��" << i + 1 << "����̾���Ϊ" << B[i];
		route = P[i];
		cout << ",����·��Ϊ:" << i + 1;
		while (route != 0)
		{
			printf("��%d", route);

			route = P[route - 1];
		}
		cout << endl; cout << endl;
	}
}

int main()
{

	int A[n][n] = {
		{ maxsize, 100, 200, 200, maxsize, maxsize, maxsize },
		{ maxsize, maxsize, maxsize, 50, 150, maxsize, maxsize },
		{ maxsize, maxsize, maxsize, 100, maxsize, 150, maxsize },
		{ maxsize, maxsize, maxsize, maxsize, 80, 350, maxsize },
		{ maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, 150 },
		{ maxsize, maxsize, maxsize, maxsize, 360, maxsize, 450 },
		{ maxsize, maxsize, maxsize, maxsize, maxsize, maxsize, maxsize }
	};

	int v = 1;
	cout << "1��ʾ���ݣ�2��ʾ��ɽ��3��ʾ���죬4��ʾ�麣��5��ʾ���ڣ�6��ʾ������7��ʾ���" << endl<<endl;
	cout << "���ݵ����������е���̾��뼰�侭��·��Ϊ��" << endl<<endl;
	djstl(A, v);	
	return 0;
}
