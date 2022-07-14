#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

vector<int> board[10001];
int vis[10001] = { 0 };

int main()
{
	vector<int> res_computer_num;
	queue<int> q;
	int n, m,res=0;
	cin >> n >> m;

	for (int i = 0;i < m;i++)
	{
		int u, v;
		cin >> u >> v;
		board[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)
	{
		int temp_res = 0;
		q.push(i);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int dir = 0;dir < board[cur].size();dir++)
			{
				if (vis[board[cur][dir]] > 0) continue;
				vis[board[cur][dir]] = 1;
				temp_res++;
				q.push(board[cur][dir]);
			}
		}
		if (temp_res >= res)
		{
			if (temp_res > res)
			{
				res = temp_res;
				res_computer_num.clear();
			}
			res_computer_num.push_back(i);
		}
		memset(vis, 0, sizeof(int) * 10001);
	}
	for (int i = 0;i < res_computer_num.size();i++)
	{
		cout << res_computer_num[i] << " ";
	}

	return 0;
}

/*
bfs�� �̿��� �� ������ ���������� �ؼ� ���� ���� ������ �Ǵ� ������ ����ϴ� ����� ����
1. �Է��� ���� ��, ������ ������� �ƴ϶� �ܹ����̶�� �� ����
2. �������� ���� bfs�� ������ �湮 ����� �߰��ɴ븶�� ī��Ʈ
3. �� ������ ī��Ʈ�� ���� ���� ���� ī��Ʈ�� ��ǻ�� ��ȣ ���
*/