#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int board[100][100];
int vis[100][100];
int d_x[4] = { 1,0,-1,0 };
int d_y[4] = { 0,-1,0,1 };

int main()
{
	queue<pair<int, int>> q;
	int n,res_max=0,temp_max=0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin>>board[j][i];
		}
	}

	for (int i = 0;i <= 100;i++)
	{
		for (int j = 0;j < n;j++)
		{
			for (int k = 0;k < n;k++)
			{
				if (board[k][j] > i &&vis[k][j]==0)
				{
					vis[k][j] = 1;
					q.push({ k,j });
					while (!q.empty())
					{
						pair<int, int> cur = q.front();q.pop();
						for (int dir = 0;dir < 4;dir++)
						{
							int nx = cur.first + d_x[dir];
							int ny = cur.second + d_y[dir];
							if (nx < 0 || ny < 0 || nx >= n||ny >= n) continue;
							if (vis[nx][ny] != 0 || board[nx][ny] <= i) continue;
							vis[nx][ny] = 1;
							q.push({ nx,ny });
						}
					}
					temp_max++;
				}
			}
		}
		if (res_max < temp_max) res_max = temp_max;
		temp_max = 0;
		memset(vis, 0, sizeof(int) *10000);
	}

	cout << res_max;
	return 0;
}
/*
���� bfs ���� ���� ���ϴ� �������� ������ ������ ������ ���� �ƴ� ���̿� ���� �������ٴ� �� �����ϰ� ������ Ǯ�
1. ���� ������ ������ res_max�� ������ ������ 0~100���� �ɶ��� ������ ���̽����� ���� ������ ����� �ӽ÷� �� temp_max�� �������.
2. for���� �̿��� ���� 100������ ���̽��� ���� ������ �� ������ ���̽������� ���� ������ �ִ밪�� ����, ������־���.
*/
