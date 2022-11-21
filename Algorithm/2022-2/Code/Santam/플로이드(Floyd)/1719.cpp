#include <bits/stdc++.h>

using namespace std;

int board[201][201]{};
int n, m;


int main()
{
	cin.tie(0)->sync_with_stdio(false);
	memset(board, 300000, sizeof(int) * 201 * 201); //����ġ�� ������ ���ü��ִ� �ִ�� 200000�̹Ƿ� �׺��� ū���� board�ʱ�ȭ
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int n1, n2, v;
		cin >> n1 >> n2 >> v;
		board[n1][n2] = v;
		board[n2][n1] = v;
	} //�Է�

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
			}
		}
	} //�÷��̵�(k:���İ��� ��� i,j:��,��)

	return 0;
}