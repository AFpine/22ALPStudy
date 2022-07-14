#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[100][100];
int vis[100][100];
int d_x[4] = { 1,0,-1,0 };
int d_y[4] = { 0,-1,0,1 };

int main()
{
	queue<pair<int, int>> q;
	int res_w[100] = { 0 };
	int n, m, k,res=0;
	cin >> n >> m >> k;
	for (int i = 0;i < k;i++)
	{
		int s_x, s_y, f_x, f_y;
		cin >> s_x >> s_y >> f_x >> f_y;
		for (int j = s_y;j < f_y;j++)
		{
			for (int l = s_x;l < f_x;l++)
			{
				board[l][j] = 1;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (!board[j][i] && !vis[j][i])
			{				
				vis[j][i] = 1;
				q.push({ j,i });
				while (!q.empty())
				{
					pair<int, int> cur = q.front(); q.pop();
					res_w[res]++;
					for (int dir = 0;dir < 4;dir++)
					{
						int nx = cur.first + d_x[dir];
						int ny = cur.second + d_y[dir];
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] != 0) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				res++;
			}
		}
	}
	sort(res_w, res_w+res);
	cout << res << "\n";
	for (int i = 0;i < res;i++) cout << res_w[i] << " ";

	return 0;
}

/*
�Է¹��� ���簢���� ���̶�� �����ϰ� bfs �׸��������� �����ϰ� Ǯ�� �ȴٰ� ����+���� ���θ� �� �����ؾ��ؼ� �迭 �߰�

1. �Է¹��� ���簢�� ���� ��ǥ ������� board�� �� �߰�
2. vis�� 0�̸鼭 board�� ���� �ƴ� ���� ���ö��� �и��� ���� ���� �߰��ϸ鼭 �� ������ ���̸� ť���� ���Ҹ� pop�Ҷ����� 1�� �����ָ� ����
*/