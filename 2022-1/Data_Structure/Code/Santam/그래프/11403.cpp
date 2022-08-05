#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[101][101] = { 0 };
int vis[101][101] = { 0 };

int main()
{
	queue<pair<int,int>> q;
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cin >> board[j][i];
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (board[j][i])
			{
				vis[j][i] = 1;
				q.push({ j,i });
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					for (int k = 1;k <= n;k++)
					{
						if (board[cur.second][k] != 1) continue;
						if (vis[cur.first][k] != 0) continue;
						vis[cur.first][k] = 1;
						board[cur.first][k] = 1;
						q.push({ cur.first,k });
					}					
				}
				memset(vis, 0, sizeof(int) * 101 * 101);
			}
		}
	}

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			cout << board[j][i]<<" ";
		}
		cout << "\n";
	}
	return 0;
}

/*
�� ���� ���� �� (1,3),(2,1),(3,2)�� ���� ������ �־��� ��, �ݺ������� 1,3��3,2�� ���� 1,2�� �Ǹ� board�� 1,2��ǥ�� �����ϴ� ������� ���� �ǰڴٰ� ����
1. board�� �Է� ���� ���� �ְ�, �ݺ����� ���� 1�� ������ ��ǥ�� ���� ������ bfs�� �����־���.
2. bfs�� ���� �� ������ ���ο� ��ǥ�鿡 ���� board�� ������ ������Ʈ����� ���� bfs�� ������ ��, �� ���ο� ��ǥ�� ���� ��ε� �ݿ��� �� �ִٰ� �Ǵ�
==> vis�湮�� ǥ���ϸ鼭 board���� ǥ��
3. bfs�� ���� ��, ���� bfs�� ������ ���� vis�� 0���� �ʱ�ȭ
==> �̰� ���ϸ�, ���� �湮�� bfs�� ��θ� Ž���� �� ���� ��
*/