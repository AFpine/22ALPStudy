#include <bits/stdc++.h>
#define x first
#define y second
#define INF 200000000
using namespace std;

vector<pair<int, int>> adj[2010]{}; //���� ������
int d[2005][3]{}; // ���� ������
int n, m, b, a, t, des, p1, p2;

void dijk(int s, int idx) //s:��� ��� idx: 0: ��� ��� ���� 1:p1��� ���� 2: p2��� ����
{

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // x:���� �Ÿ� , y:���
	q.push({ 0,s });
	d[s][idx] = 0;
	while (!q.empty())
	{
		auto cur = q.top(); q.pop();
		if (d[cur.y][idx] < cur.x) continue; //���ŵǱ� �� �����Ͱ� �����־ ���õȰ��
		for (auto nxt : adj[cur.y])
		{
			if (d[nxt.y][idx] <= d[cur.y][idx] + nxt.x) continue;
			d[nxt.y][idx] = d[cur.y][idx] + nxt.x;
			q.push({ d[nxt.y][idx] , nxt.y });
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 2010; i++) adj[i].clear();
		fill(&d[0][0], &d[2004][3], INF);
		cin >> n >> m >> des;
		cin >> a >> p1 >> p2;
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ w,v });
			adj[v].push_back({ w,u });
		}
		dijk(a, 0);
		dijk(p1, 1);
		dijk(p2, 2);
		vector<int> temp;
		for (int i = 1; i <= des; i++)
		{
			int c; cin >> c;
			temp.push_back(c);
		}
		sort(temp.begin(), temp.end());
		for (auto c : temp)
		{
			if (d[c][0] == d[p1][0] + d[p2][1] + d[c][2]) cout << c << " "; // s-p1-p2-c�� �̾����� ���
			else if (d[c][0] == d[p2][0] + d[p2][1] + d[c][1]) cout << c << " "; // s-p2-p1-c�� �̾����� ���
		}
		cout << "\n";
	}

	return 0;
}