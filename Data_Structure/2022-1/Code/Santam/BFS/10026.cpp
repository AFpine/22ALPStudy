#include <iostream>
#include <queue>

using namespace std;

char board[100][100];
int vis_r_g[100][100];
int vis_all[100][100];

void bfs(char board[][100], int vis[][100],pair<int,int> push_first,int n,char color,bool r_g_chk)
{
	queue<pair<int, int>> q;
	q.push(push_first);
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };

	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= n | ny >= n) continue;
			if (!r_g_chk)
			{
				if (vis[nx][ny] != 0 || board[nx][ny] != color) continue;
			}
			else
			{
				if (vis[nx][ny] != 0 || board[nx][ny] == 'B') continue;
			}
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}


int main()
{
	int n,res_all=0,res_r_g=0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin>>temp;
		for (int j = 0;j < n;j++)
		{
			board[j][i] = temp[j];
		}
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			if (board[j][i] == 'B'&&vis_all[j][i]==0)
			{
				vis_all[j][i] = 1;
				vis_r_g[j][i] = 1;
				res_all++;
				res_r_g++;
				bfs(board, vis_all, { j,i }, n, 'B',0);
				bfs(board, vis_r_g, { j,i }, n, 'B',0);
			}
			if (board[j][i] == 'R' )
			{
				if (vis_all[j][i] == 0)
				{
					vis_all[j][i] == 1;
					res_all++;
					bfs(board, vis_all, { j,i }, n, 'R', 0);
				}
				if (vis_r_g[j][i] == 0)
				{
					vis_r_g[j][i] = 1;
					res_r_g++;
					bfs(board, vis_r_g, { j,i }, n, 'R', 1);
				}
			}
			if (board[j][i] == 'G')
			{
				if (vis_all[j][i] == 0)
				{
					vis_all[j][i] == 1;
					res_all++;
					bfs(board, vis_all, { j,i }, n, 'G', 0);
				}
				if (vis_r_g[j][i] == 0)
				{
					vis_r_g[j][i] = 1;
					res_r_g++;
					bfs(board, vis_r_g, { j,i }, n, 'G', 1);
				}
			}
		}
	}

	cout << res_all << " " << res_r_g;

	return 0;
}

/*
������ bfs�� ������ ������ ������ ���ϴ� ������ ������ ���ο� ���� bfs���� ���Ǹ� �ٲ� vis�� ǥ���ϰ� �ߴ�.
1. bfs�Լ� �ϳ� ���� ��, ���� ���� ���� ���ο� ���� �����̸� R�̳�G�� ���ö�, B�� �ƴϸ� �ٸ� ���̾ continue�� ���� �ʵ��� ��ġ
2. board�� B�� �־� B������ bfs�� �����Ҷ� ���� ���δ� ���� ���ٴ� ���� Ȱ��
*/