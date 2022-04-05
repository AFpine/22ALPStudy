#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> board[501];
int vis[501] = { 0 };

int bfs()
{
	int res = 0;
	queue<int> q;
	vis[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();q.pop();
		if(vis[cur]<=3) res++;
		for (int i = 0;i < board[cur].size();i++)
		{
			if (vis[board[cur][i]] != 0) continue;
			vis[board[cur][i]]= vis[cur]+1;
			q.push(board[cur][i]);
		}
	}
	return res - 1;
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
���̷��� ������ pop�Ҷ� ���� ��Ģ�� ������ �־ ù��°�� �Ÿ��� 3���ϸ� ���� �ֵ��� ����
*/