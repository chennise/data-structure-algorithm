#include<iostream>
using namespace std;
#define INF INT_MAX
void Dispath(int path[], int dist[])//输出路径的函数
{
	for (int i = 0; i<7; i++)
	{
		printf("从0点到%d的最短路径为：%d, 路径为：", i, dist[i]);
		int k = 0;
		int c = i;
		int apath[7];
		while (path[c] != 0) //路径存在时输出它
		{
			apath[k] = path[c];
			k++;
			c = path[c];
		}
		k--;
		printf("0");//输出起点
		for (k; k >= 0; k--)
		{
			printf("→%d", apath[k]);
		}//倒序输出最短路径
		printf("→%d", i);//输出终点
		printf("\n");
	}
}
//int main(){
//	int graph[7][7] = { 0, 100, 200, 200, INF, INF, INF,
//		INF, 0, 50, INF, 150, INF, INF,
//		INF, INF, 0, INF, 100, 350, INF,
//		INF, INF, 100, 0, INF, 150, INF,
//		INF, INF, INF, INF, 0, INF, 150,
//		INF, INF, INF, INF, 400, 0, 500,
//		INF, INF, INF, INF, INF, INF, 0 };//把图转成邻接矩阵
//	int dist[7], s[7], path[7];
//	int mindis, u, i, j;
//	for (int i = 0; i<7; i++){
//		s[i] = 0; path[i] = 0; dist[i] = INF;
//	}
//	dist[0] = 0;
//	for (i = 0; i<7; i++)//循环求出所有顶点的最短路径
//	{
//		mindis = INF;//让最小长度初值为无穷
//		for (j = 0; j<7; j++)
//			if (s[j] == 0 && dist[j]<mindis)//选取不在中且具有最小距离的顶点
//			{
//				u = j;
//				mindis = dist[j];
//			}
//		s[u] = 1;//顶点加入s中
//		for (j = 0; j<7; j++)//修改不在s中的顶点的距离
//			if (s[j] == 0)
//				if (dist[u] + graph[u][j]<dist[j])
//				{
//					dist[j] = dist[u] + graph[u][j];
//					path[j] = u;
//				}
//	}
//	Dispath(path, dist);//调用输出路径函数
//
//}
