#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

char board[105][105] = { 0 };
int vis[105][105] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	queue<pair<int, int>> q;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0;j < m;j++)
		{
			board[j][i]=temp[j];
		}	
	}
	vis[0][0] = 1;
	q.push({ 0,0 });
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] != '1') continue;
			vis[nx][ny] = vis[cur.first][cur.second]+1;
			q.push({ nx, ny });
		}
	}
	cout << vis[m-1][n-1] << "\n";

	return 0;
}

/*
BFS�� �̿��ϴµ� �ּ� �̵��Ÿ��� ã������ �湮ǥ�ø� ����ϴ� vis�� �̿�

1. vis�迭�� ó������ 1�� �����ؼ� ���ο� vis�� ǥ���Ҷ� ���� vis�� +1�� ���� ���� �����ϵ��� �Ѵ�.
2. 1�� ������ �ݺ��ϸ� m,n�� ĭ�� ���� ��ĭ�� �Դ��� ī��Ʈ�� �ڵ����� �ȴ�.
*/