#include <stdio.h>
#include <string.h>
int nCount = 0;
int Matrix[100][100];
void chessBoard(int tr, int tc, int dr, int dc, int size);
int main()
{
	int size, r, c, row, col;
	memset(Matrix, 0, sizeof(Matrix));
	scanf_s("���������̴�С:%d", &size);
	scanf_s("�������ʼ���ⷽ������λ�õ��кź��к�:%d %d", &row, &col);
	chessBoard(0, 0, row, col, size);
	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size; c++)
		{
			printf("%2d ", Matrix[r][c]);
		}
		printf("\n");
	}
	return 0;
}
void chessBoard(int tr, int tc, int dr, int dc, int size)
{ //�����������,tr��tc�����̵����Ͻ�����,һ����Ϊ��0,0.
	int s, t;
	if (size == 1) //���̴�СΪ1
		return;
	s = size / 2;
	t = ++nCount;
	if (dr < tr + s && dc < tc + s)
	{//�ж����ⷽ�����ĸ�С����
		chessBoard(tr, tc, dr, dc, s);
	}
	else
	{
		Matrix[tr + s - 1][tc + s - 1] = t;
		chessBoard(tr, tc, tr + s - 1, tc + s - 1, s);
	}
	if (dr < tr + s && dc >= tc + s)
	{//ͬ��
		chessBoard(tr, tc + s, dr, dc, s);
	}
	else
	{
		Matrix[tr + s - 1][tc + s] = t;
		chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
	}
	if (dr >= tr + s && dc < tc + s)
	{
		chessBoard(tr + s, tc, dr, dc, s);
	}
	else
	{
		Matrix[tr + s][tc + s - 1] = t;
		chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
	}
	if (dr >= tr + s && dc >= tc + s)
	{//ͬ��
		chessBoard(tr + s, tc + s, dr, dc, s);
	}
	else
	{
		Matrix[tr + s][tc + s] = t;
		chessBoard(tr + s, tc + s, tr + s, tc + s, s);
	}
}