#include <bits/stdc++.h>
const int INF = 1e9;
const int MAX = 100000 + 1;
using namespace std;

int V, E; // ���� V, ���� E
int K; // ���� ���� ��ȣ
int result[MAX];
vector<pair<int, int>> vec[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// input
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;

		vec[u].push_back({ v, w }); // u<->v(�Ÿ� w) �����͸� ����
	}

	for (int i = 1; i <= V; i++)
	{
		result[i] = INF; // result(���� �� �ִ� �̵��Ÿ�)
	}

	// solve
	priority_queue<pair<int, int>> pq; // ��� queue �ᵵ ��� ���� ��
	// �ð� �ʰ� ���������� ���! ���߿� �׳� queue�θ� �غ� ��
	pq.push({ 0, K }); // �Ÿ�, ������ ������ pair �Է�
	result[K] = 0;

	while (!pq.empty())
	{
		int Cost = -pq.top().first;
		int Far = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[Far].size(); i++)
		{
			int next = vec[Far][i].first; // ���� ������ ���� ������ ���� ����
			int nextcost = vec[Far][i].second;

			if (result[next] > Cost + nextcost) // INF���� ���� ���� ������ �� ũ��
			{
				result[next] = Cost + nextcost; // ���� ����
				pq.push({ -result[next], next }); // �� �� ������ - ���̴��� �𸣰ڴ�
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (result[i] == INF)
		{
			cout << "INF" << "\n";
		}
		else cout << result[i] << "\n";
	}

	return 0;
}