#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[102];
int vis[102];
int n; // ��ǻ���� ��
int m; // ������ ��


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num = 0;
	
	cin >> n >> m;

	queue<int> Q;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		
		V[x].push_back(y);
		V[y].push_back(x);
	}

	Q.push({ 1 });
	vis[1] = 1;

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();

		for (auto nxt : V[cur])
		{
			if (vis[nxt] != 0) continue;
			vis[nxt] = 1;
			num++;
			Q.push(nxt);
		}
	}

	cout << num;
}