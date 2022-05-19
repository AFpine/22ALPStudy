#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100001];
int p[100001] = { 0 };

void Bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0;i < v[cur].size();i++)
		{
			if (p[cur] == v[cur][i]) continue; //�θ��� ��常�� ����ϴ� ���̱⿡, �ڽ��� �θ� �����ϴ� �� �ܿ� �ݴ��� ��찡 ������ ������ ����
			p[v[cur][i]] = cur;
			q.push(v[cur][i]);
		}
	}
}

int main()
{

	int n;
	cin >> n;
	for (int i = 0;i < n-1;i++)
	{
		int temp,temp2;
		cin >> temp >> temp2;
		v[temp].push_back(temp2);
		v[temp2].push_back(temp);
	}
	Bfs(1);
	for (int i = 2; i < n+1; i++)
	{
		cout << p[i] << "\n";
	}

	return 0;
}

/*
�̹������� �� ����� �θ� ��尡 �������� �˼� �ֵ��� �θ� ��带 �����ϴ� �迭�� ������ �ذ��� �� �������� ����
1. �� ����� ���Ῡ�θ� ���͹迭 ������ ������ push_back���־���.
2. ����� ���Ϳ��� bfs�� Ȱ���� �� ��带 ��ȸ�ϸ鼭 ��Ʈ���� ���� ������� ��ȸ�Ҷ�, �� ����� �θ� � ������� �迭 p�� ����
3. ����� �迭 p�� �ִ� �����͸� 2�������� ������� ����ߴ�.
*/