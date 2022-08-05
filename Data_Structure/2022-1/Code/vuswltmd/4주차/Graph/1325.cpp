#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

vector<int> V[10005];
int V_K[10005]; //�� ��ǻ���� �ִ�Ÿ��� ������ �迭
int vis[10005];
int n;               
int m;                


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;


	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		V[y].push_back(x); // ��) 4�� 5�� 3�� �����
	}

	int mmxx = 0; //��ü�� �ִ�Ÿ�

	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= n; j++)
		{
			vis[j] = -1;
		}

		int num = 0; //��ŷ�� ��ǻ�� ��
		queue<int> Q;
		Q.push(i);
		vis[i] = 0;

		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();

			for (auto nxt : V[cur])
			{
				if (vis[nxt] == -1)
				{
					vis[nxt] = vis[cur] + 1; // �Ÿ��� Ǯ �ʿ�� ����
					num++;
					Q.push(nxt);
				}
			}
		}

		mmxx = max(mmxx, num);

		V_K[i]=num;
	}

	for (int j = 1; j <= n; j++)
	{
		if (V_K[j] == mmxx)
		{
			cout << j << " ";
		}
	}
}