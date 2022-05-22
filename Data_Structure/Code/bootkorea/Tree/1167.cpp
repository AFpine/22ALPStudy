#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100000 + 1
using namespace std;

int V, maxDist, maxindex;
int Visited[MAX];
vector<pair<int, int>> vec[MAX];

void DFS(int idx, int cost)
{
	if (Visited[idx])
	{
		return;
	}

	Visited[idx] = true;

	if (maxDist < cost)
	{
		maxDist = cost;
		maxindex = idx;
	}

	for (int i = 0; i < vec[idx].size(); i++)
	{
		DFS(vec[idx][i].first, vec[idx][i].second + cost);
	}
}

int main()
{
	int start, end, distance;

	cin >> V; // �ݺ� Ƚ�� V

	while (V--)
	{
		cin >> start; // ù ���� num

		while (true)
		{
			cin >> end; // ���� end �ް�
			if (end == -1)
			{
				break; // ��������
			}

			cin >> distance; // �������� �н��ϸ� �Ÿ� �Է�
			vec[start].push_back({ end, distance }); // ����-���� ���� ������
		}

	}

	DFS(1, 0);

	memset(Visited, false, sizeof(Visited));

	maxDist = 0;

	DFS(maxindex, 0);

	cout << maxDist;

	return 0;
}