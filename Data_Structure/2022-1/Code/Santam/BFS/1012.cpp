#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int d_x[4] = { 1,0, -1,0 };
int d_y[4] = { 0,-1,0,1 };
int board[50][50];
int vis[50][50];

void tester()
{
	queue<pair<int, int>> q;
	int n, m, k, res = 0;
	cin >> m >> n >> k;

	for (int i = 0;i < k;i++)
	{
		int temp_x, temp_y;
		cin >> temp_x >> temp_y;
		board[temp_x][temp_y] = 1;
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (board[j][i] > 0 && vis[j][i] == 0)
			{
				res++;
				q.push({ j,i });
				vis[j][i] = 1;
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int dir = 0;dir < 4;dir++)
					{
						int nx = cur.first + d_x[dir];
						int ny = cur.second + d_y[dir];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	cout << res << "\n";
}

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0;i < cnt;i++)
	{
		tester();
		memset(board, 0, sizeof(int) * 2500);
		memset(vis, 0, sizeof(int) * 2500);

	}
	return 0;

}

/*
������ ��ġ�� board�� �����ϰ� ���� board��ü�� ���� �ݺ����� �����ָ鼭 ���߰� �ִµ� bfs�� �湮 ������ ���� ��쿡 �� ���� ť�� �ְ� bfs�ǽ��ϴ� ������� �ϸ� ���߱����� ������ �� ���ִٰ� ����
1. ���� ��ġ board�� ����, �� �� board�� ���� ����, ���߰� ������ �湮�� ������ ���� ��쿡 ���� �� ��ġ�� vis�� ǥ�ø� ���ָ鼭 ť�� push�� ��, bfs �ǽ�
2. � �ϳ��� ���߿� ���� bfs�� �ǽ� �Ŀ�, �� ���߿� �������ִ� ���ߵ��� ���� �湮 ������ �����ֱ⿡ board�� �ٽ� �˻��Ҷ� ���ܵ�
*/