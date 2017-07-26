#include<iostream>
using namespace std;
#define maxsize  1000000//表示两点之间不通
#define n 7  //节点的数目为7个
void djstl(int A[][n], int v)//求原点v到其余顶点的最短距离及其经过路径
{
	int B[n], P[n], Q[n]; 			//B用于记录各点到源点的距离,P用于记录路径，Q标括记是否为最短路径的结点
	int i, j, k, s, route;    //s表示源点，route表示经过的路径
	int min, max = maxsize, road = 20160601;
	s = v - 1;
	for (i = 0; i<n; i++)
	{
		B[i] = A[s][i];   //初始化距离值
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
		for (j = 0; j<n; j++)   //在当前P中选距离值最小的点k+1
		{
			if ((!Q[j]) && (B[j]<min))
			{
				min = B[j];
				k = j;
			}
		}
		Q[k] = 1;    //将k+1加入Q
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
		
		cout << "1到" << i + 1 << "的最短距离为" << B[i];
		route = P[i];
		cout << ",经过路径为:" << i + 1;
		while (route != 0)
		{
			printf("←%d", route);

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
	cout << "1表示广州，2表示佛山，3表示肇庆，4表示珠海，5表示深圳，6表示南宁，7表示香港" << endl<<endl;
	cout << "广州到其他各城市的最短距离及其经过路径为：" << endl<<endl;
	djstl(A, v);	
	return 0;
}
