#include<iostream>
using namespace std;
#define INF INT_MAX
void Dispath(int path[], int dist[])//���·���ĺ���
{
	for (int i = 0; i<7; i++)
	{
		printf("��0�㵽%d�����·��Ϊ��%d, ·��Ϊ��", i, dist[i]);
		int k = 0;
		int c = i;
		int apath[7];
		while (path[c] != 0) //·������ʱ�����
		{
			apath[k] = path[c];
			k++;
			c = path[c];
		}
		k--;
		printf("0");//������
		for (k; k >= 0; k--)
		{
			printf("��%d", apath[k]);
		}//����������·��
		printf("��%d", i);//����յ�
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
//		INF, INF, INF, INF, INF, INF, 0 };//��ͼת���ڽӾ���
//	int dist[7], s[7], path[7];
//	int mindis, u, i, j;
//	for (int i = 0; i<7; i++){
//		s[i] = 0; path[i] = 0; dist[i] = INF;
//	}
//	dist[0] = 0;
//	for (i = 0; i<7; i++)//ѭ��������ж�������·��
//	{
//		mindis = INF;//����С���ȳ�ֵΪ����
//		for (j = 0; j<7; j++)
//			if (s[j] == 0 && dist[j]<mindis)//ѡȡ�������Ҿ�����С����Ķ���
//			{
//				u = j;
//				mindis = dist[j];
//			}
//		s[u] = 1;//�������s��
//		for (j = 0; j<7; j++)//�޸Ĳ���s�еĶ���ľ���
//			if (s[j] == 0)
//				if (dist[u] + graph[u][j]<dist[j])
//				{
//					dist[j] = dist[u] + graph[u][j];
//					path[j] = u;
//				}
//	}
//	Dispath(path, dist);//�������·������
//
//}
