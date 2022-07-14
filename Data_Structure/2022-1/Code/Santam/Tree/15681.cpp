#include <iostream>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

int p[100001] = { 0 };
int vis[100001] = { 0 };
vector<int> tree[100001];


void Child_Sum(int n)
{
	vis[n] = 1;
	for (int i = 0;i < tree[n].size();i++)
	{
		if (tree[n][i] == p[n]) continue; //�ڽ��� ��尡 �θ��� ����϶��� �н�
		Child_Sum(tree[n][i]); // �ڽ� ����� �ڽĵ��� ���� �˾Ƴ��� ���� ���
		vis[n] += vis[tree[n][i]]; // ���� ��忡 �ڽ��� ������ �ڽĵ��� ��(���ε� ����)�� ����
	}
}

void Dfs(int r)
{
	stack<int> s;
	s.push(r);
	while (!s.empty())
	{
		int cur = s.top(); s.pop();
		for (int i : tree[cur])
		{
			if (p[cur] == i) continue;
			p[i] = cur;
			s.push(i);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	Dfs(r);
	Child_Sum(r);
	for (int i = 0;i < q;i++)
	{
		int t;
		cin >> t;
		cout<<vis[t]<<"\n";
	}

	return 0;
}

/*
�� ����� �θ��� ������ ����� ���� dfs�� ������ �迭 p�� ������ ��, �� ��尡 �ڽĵ��� ���� ���� �˾Ƴ��� ���� ��������� child_sumȣ���ϵ��� �ؼ� v�迭�� �ڽ� ���� ����
1. dfs�Լ��� dfs������� �� ����� �θ� ������
2. child_sum�Լ��� ��������� �� ����� �ڽĵ��� ���Ҷ� �� �ڽĵ��� ��� ������ child_sum�Լ��� �ҷ����� �ڽĵ��� ���� ���� �˾Ƴ����� ����
3. dfs�� child_sum�� ������� root���� �־� Ž���� �����ؼ� �ʿ��� �� �迭�� ����, �ԷµǴ� ���� ���� �ش��ϴ� �迭�� ����� �����͸� ��� 
*/