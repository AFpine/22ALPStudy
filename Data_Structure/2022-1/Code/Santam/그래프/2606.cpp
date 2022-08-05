#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> board[101];
int vis[101] = { 0 };

int bfs()
{
	int res = 0;
	queue<int> q;
	vis[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();q.pop();
		res++;
		for (int i = 0;i < board[cur].size();i++)
		{
			if (vis[board[cur][i]]!=0) continue;
			vis[board[cur][i]] = 1;
			q.push(board[cur][i]);
		}
	}
	return res-1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int u, v;
		cin >> u >> v;
		board[u].push_back(v);
		board[v].push_back(u);
	}

	cout << bfs();

	return 0;
}
/*
bfs�� �̿��� 1�� ��ǻ�Ϳ��� �����ϴ� ���̷����� pop�Ҷ����� ��ǻ�͸� �����־� ������� ����
*/