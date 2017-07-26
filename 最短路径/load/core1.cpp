#include<stdio.h> 
using namespace std;
#include<string.h> 
#define MAXV 100 
#define InfoType char 
#define INF 1000 /*INF��ʾ��*/ 
typedef struct
{
	int no; /*������*/
	InfoType info[12]; /*������Ϣ*/
}vertextype; /*��������*/

typedef struct
{
	int edges[MAXV][MAXV]; /*�ڽӾ���*/
	int n, e; /*������,����*/
	vertextype vexs[MAXV]; /*������Ϣ*/
}mgraph; /*ͼ�Ķ���*/
///////////////////////////////////////////////////////////////////////////////// 
void createmgraph(mgraph &g) //����ͼ������ͼ�Ķ�����ڽӾ��� 
{
	int i, j, m; int a = 0; int f = 0; int o = 0; int n = 0; int c = 0; int k = 1; int v = 0;
	InfoType b[23], t[22];
	printf(" ͼ�ĳ�ʼ��,��Ϊ�����\n");
	g.n = i = 0;
	while (i<2)
	{
		printf("�����붥��ĸ���( ����>=2 ):");
		scanf_s("%d", &g.n);
		i = g.n;
	}
	for (i = 0; i<g.n; i++)
	{
		v = 0;
		printf("�������%d���������Ϣ:", i + 1);// 
		scanf_s("%s", g.vexs[i].info);
		g.vexs[i].no = i;
		for (j = 0; j<i; j++)
			if (strcmp(g.vexs[i].info, g.vexs[j].info) == 0)
				v = 1;
		if (v == 1)
		{
			printf(" �˶����Դ���\n"); i--;
		}

	}
	for (i = 0; i<g.n; i++) /*��ʼ���ڽӾ���*/
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
		printf("������ߵĸ���( 0<=����<=%d)", g.n*(g.n - 1));
		scanf_s("%d", &g.e);
	}
	if (g.e >= 1)
	{
		while (1) /*�޸��ڽӾ���*/
		{
			a = f = 0;
			printf("�������%d���ߵ���Ϣ:", k++);
			printf("��������㡢�յ� Ȩֵ(���������Σ�:");
			scanf_s("%s %s %d", b, t, &m);
			if (strcmp(b, t) == 0){ k--; printf("��ʼ����յ㲻����ͬ���Ѿ�Ĭ��Ϊ0��\n"); }
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
					printf("������������\n"); k--;
				}
				if (a == 1 && f == 0)
				{
					printf("������յ�����\n"); k--;
				}
				if (a == 0 && f == 0)
				{
					printf("����������յ������\n"); k--;
				}
				if (a == 1 && f == 1)
				{
					if (g.edges[o][n] != INF)
					{
						printf("������Ӧ�������\n"); k--;
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
void Dispath(mgraph g, int dist[], int path[], int s[], int n, int v) /*������·

																	  ��*/
{
	int i; int a, b;
	for (i = 0; i<n; i++)
	{
		if (s[i] == 1)
		{
			printf("��%s��%s�����·������Ϊ:%d", g.vexs[v].info, g.vexs[i].info, dist[i]);
			printf(" ·��Ϊ:");
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
		else printf("��%s��%s������·��\n", g.vexs[v].info, g.vexs[i].info);
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
		} /*�����ʼ��*/
		s[i] = 0;
		path[i] = -1;
	}
	path[0] = v; s[v] = 1;
	for (i = 0; i<g.n; i++) /*ѭ��ֱ�����ж�������·�������*/
	{
		mindis = INF; /*mindis����С���ȳ�ֵ*/
		for (j = 0; j<g.n; j++) /*ѡȡ����s���Ҿ�����С����Ķ���u*/
			if (s[j] == 0 && dist[j]<mindis)
			{
				u = j;
				mindis = dist[j];
				s[u] = 1; z = 1;
			}
		c++; path[c] = u;
		if (z == 1)
		{
			for (j = 0; j<g.n; j++) /*�޸Ĳ���s�еĶ���ľ���*/
				if (s[j] == 0)
					if (g.edges[u][j]<INF && dist[u] + g.edges[u][j]<dist[j])
					{
						dist[j] = dist[u] + g.edges[u][j];
					}
		}
	}
	Dispath(g, dist, path, s, g.n, v); /*������·��*/
}
///////////////////////////////////////////////////////////////////// 

//void main()
//{
//	mgraph g; //���· 
//	int q = 0; int r = 0;
//	InfoType v[22];
//	createmgraph(g);
//	printf("��ͼ���ڽӾ���Ϊ:\n");
//	for (int i = 0; i<g.n; i++)
//	{
//		int u = 0;
//		for (int j = 0; j<g.n; j++)
//		{
//			if (g.edges[i][j] == 1000)
//			{
//				printf("��"); u++;
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
//		printf("����Ҫ���ҵ�ԭ�����Ϣ\n");
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
//		else printf("�����ԭ������\n");
//	}
//	printf("\n");
//}