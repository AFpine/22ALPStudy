#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

int dist[1001][1001] = { 0 };
vector<int> tree[100001];


int Dfs(int r,int f)
{
	int p[1001] = { 0 };
	int dist_each_other = 0;
	stack<int> s;
	s.push(r);
	while (!s.empty())
	{
		int cur = s.top(); s.pop();
		for (int i : tree[cur])
		{
			if (p[cur] == i) continue;
			p[i] = cur;
			dist[r][i] = dist[r][cur] + dist[cur][i];
			dist[i][r] = dist[r][cur] + dist[cur][i];
			if (i == f) dist_each_other = dist[r][i];
			s.push(i);
		}
	}
	return dist_each_other;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		tree[u].push_back(v);
		tree[v].push_back(u);
		dist[u][v] = d;
		dist[v][u] = d;
	}
	for (int i = 0;i < q;i++)
	{
		int f,s;
		cin >> f>>s;
		cout << Dfs(f,s) << "\n";
	}

	return 0;
}

/*
�� ��� ������ �Է��� �־����� �� ��带 ó���� ������ ������ dfs�� �����鼭 �Ÿ��� ���Ѵ�. �̶� �Ÿ��� �����ϴ� �迭���� �ϳ��� �� ��� ������ �Ÿ��� �����Ѵ�.
1. �� ��带 ����, �� ��� ������ �Ÿ��� ������ ��, �� ��带 �Է����� ������, �� ��带 ���ڷ� �� dfs�� ����
*/