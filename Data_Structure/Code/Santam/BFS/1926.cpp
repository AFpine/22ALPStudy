#include <iostream>
#include <queue>
using namespace std;

int board[500][500] = { 0 };
int vis[500][500] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int,int>> q;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	int cnt_paint = 0;
	int max_w = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> board[j][i];
		}
	}
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (vis[i][j]||board[i][j]!=1) continue;
			int w_cnt = 0;
			vis[i][j] = 1;
			q.push({ i,j });
			cnt_paint++;
			while (!q.empty())
			{
				pair<int, int> cur = q.front(); q.pop();
				w_cnt++;
				for (int dir = 0;dir < 4;dir++)
				{
					int nx = cur.first + d_x[dir];
					int ny = cur.second + d_y[dir];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != 1) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			if (w_cnt > max_w) max_w = w_cnt;
		}
	}
	cout << cnt_paint << "\n" << max_w;
	return 0;
}

/*
��ŷ���� �⺻ BFS���� ������ ����
1. ���� ��ȭ���� �ִ� �׸��� ���� �ִ� ���̸� ���ؾߵǹǷ� ������ ������ ���� cnt_paint�� max_w����
2. �� �׸����� �׸��� ���̸� ���ϱ� ���� ���ÿ� �ִ� ��ǥ�� �ϳ��� pop�Ҷ����� ���̸� 1�� �÷���
3. ť�� ������� ���̻� ž���� ��ǥ�� �����Ƿ�, �� ���Ŀ� ���̸� ������ �ִ� ���̿� ��
4. �׸��� ���� �˱� ���� �湮�ߴ����� ���� ������ �ɾ� ���� �ݺ������� �������� ���� Ž���ϰ� �������� �����ɶ����� �׸��� ���� ī��Ʈ����
*/