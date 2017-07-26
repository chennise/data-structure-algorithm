#include<stdio.h> 
using namespace std;
#include<string.h> 
#define MAXV 100 
#define InfoType char 
#define INF 1000 /*INF表示∞*/ 
typedef struct
{
	int no; /*顶点编号*/
	InfoType info[12]; /*顶点信息*/
}vertextype; /*顶点类型*/

typedef struct
{
	int edges[MAXV][MAXV]; /*邻接矩阵*/
	int n, e; /*顶点数,弧数*/
	vertextype vexs[MAXV]; /*顶点信息*/
}mgraph; /*图的定义*/
///////////////////////////////////////////////////////////////////////////////// 
void createmgraph(mgraph &g) //创建图，包括图的顶点和邻接矩阵 
{
	int i, j, m; int a = 0; int f = 0; int o = 0; int n = 0; int c = 0; int k = 1; int v = 0;
	InfoType b[23], t[22];
	printf(" 图的初始化,边为有向边\n");
	g.n = i = 0;
	while (i<2)
	{
		printf("请输入顶点的个数( 整形>=2 ):");
		scanf_s("%d", &g.n);
		i = g.n;
	}
	for (i = 0; i<g.n; i++)
	{
		v = 0;
		printf("请输入第%d个顶点的信息:", i + 1);// 
		scanf_s("%s", g.vexs[i].info);
		g.vexs[i].no = i;
		for (j = 0; j<i; j++)
			if (strcmp(g.vexs[i].info, g.vexs[j].info) == 0)
				v = 1;
		if (v == 1)
		{
			printf(" 此顶点以存在\n"); i--;
		}

	}
	for (i = 0; i<g.n; i++) /*初始化邻接矩阵*/
		for (j = 0; j<g.n; j++)
		{
			if (i == j)
				g.edges[i][j] = 0;
			else
				g.edges[i][j] = INF;
		}
	g.e = -1;
	while (g.e<0 || g.e>g.n*(g.n - 1))
	{
		printf("请输入边的个数( 0<=整行<=%d)", g.n*(g.n - 1));
		scanf_s("%d", &g.e);
	}
	if (g.e >= 1)
	{
		while (1) /*修改邻接矩阵*/
		{
			a = f = 0;
			printf("请输入第%d条边的信息:", k++);
			printf("请输入起点、终点 权值(必须是整形）:");
			scanf_s("%s %s %d", b, t, &m);
			if (strcmp(b, t) == 0){ k--; printf("起始点和终点不能相同（已经默认为0）\n"); }
			else
			{
				for (i = 0; i<g.n; i++)
				{
					if (strcmp(b, g.vexs[i].info) == 0) { a = 1; o = i; }
				}
				for (j = 0; j<g.n; j++)
				{
					if (strcmp(t, g.vexs[j].info) == 0){ f = 1; n = j; }
				}
				if (a == 0 && f == 1)
				{
					printf("输入的起点有误\n"); k--;
				}
				if (a == 1 && f == 0)
				{
					printf("输入的终点有误\n"); k--;
				}
				if (a == 0 && f == 0)
				{
					printf("输入的起点和终点均有误\n"); k--;
				}
				if (a == 1 && f == 1)
				{
					if (g.edges[o][n] != INF)
					{
						printf("这条边应经天加了\n"); k--;
					}
					else
					{
						g.edges[o][n] = m;
						c++; printf("\n");
					}
				}
				if (c == g.e) return;
			}
		}
	}
}
///////////////////////////////////////////////// 
void Dispath(mgraph g, int dist[], int path[], int s[], int n, int v) /*输出最短路

																	  径*/
{
	int i; int a, b;
	for (i = 0; i<n; i++)
	{
		if (s[i] == 1)
		{
			printf("从%s到%s的最短路径长度为:%d", g.vexs[v].info, g.vexs[i].info, dist[i]);
			printf(" 路径为:");
			if (strcmp(g.vexs[v].info, g.vexs[i].info) == 0)
				printf(" %s", g.vexs[v].info);
			for (int m = 0; m<n; m++)
			{
				if (path[m] == i)
					a = m;
			}
			for (int j = 0; j <= a; j++)
			{
				b = path[j];
				printf(" %s", g.vexs[b].info);
			}
			printf("\n");
		}
		else printf("从%s到%s不存在路径\n", g.vexs[v].info, g.vexs[i].info);
	}
}
/////////////////////////////////////////////////////////// 
void Dijkstra(mgraph g, char v1[])
{
	int dist[MAXV], path[MAXV];
	int s[MAXV];
	int mindis, i, j, v, u; int c = 0; int z = 0;//nt v1; 
	for (i = 0; i<g.n; i++)
		if (strcmp(v1, g.vexs[i].info) == 0)
			v = g.vexs[i].no;
	for (i = 0; i<g.n; i++)
	{
		if (i == v)
		{
			for (int j = 0; j<g.n; j++)
			{
				dist[j] = g.edges[i][j];
			}
		} /*距离初始化*/
		s[i] = 0;
		path[i] = -1;
	}
	path[0] = v; s[v] = 1;
	for (i = 0; i<g.n; i++) /*循环直到所有顶点的最短路径都求出*/
	{
		mindis = INF; /*mindis置最小长度初值*/
		for (j = 0; j<g.n; j++) /*选取不在s中且具有最小距离的顶点u*/
			if (s[j] == 0 && dist[j]<mindis)
			{
				u = j;
				mindis = dist[j];
				s[u] = 1; z = 1;
			}
		c++; path[c] = u;
		if (z == 1)
		{
			for (j = 0; j<g.n; j++) /*修改不在s中的顶点的距离*/
				if (s[j] == 0)
					if (g.edges[u][j]<INF && dist[u] + g.edges[u][j]<dist[j])
					{
						dist[j] = dist[u] + g.edges[u][j];
					}
		}
	}
	Dispath(g, dist, path, s, g.n, v); /*输出最短路径*/
}
///////////////////////////////////////////////////////////////////// 

//void main()
//{
//	mgraph g; //最短路 
//	int q = 0; int r = 0;
//	InfoType v[22];
//	createmgraph(g);
//	printf("该图的邻接矩阵为:\n");
//	for (int i = 0; i<g.n; i++)
//	{
//		int u = 0;
//		for (int j = 0; j<g.n; j++)
//		{
//			if (g.edges[i][j] == 1000)
//			{
//				printf("∞"); u++;
//			}
//			else
//			{
//				printf(" %d", g.edges[i][j]); u++;
//			}
//			if (u%g.n == 0)
//				printf("\n");
//		}
//	}
//	while (1)
//	{  
//		r = 0;
//		printf("输入要查找的原点的信息\n");
//		scanf_s("%s", v);
//		for (int i = 0; i<g.n; i++)
//		{
//			if (strcmp(v, g.vexs[i].info) == 0)
//			{
//				r = 1;
//			}
//		}
//		if (r == 1)
//		{
//			Dijkstra(g, v);
//		}
//		else printf("输入的原点有误\n");
//	}
//	printf("\n");
//}