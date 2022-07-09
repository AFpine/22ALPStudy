#include <iostream>
#include <queue>

using namespace std;

vector<int> board[101001];
int vis[101001] = { 0 };

int main()
{
	queue<int> q;
	int n, m, k;
	cin >> n >> k >> m;
	for (int i = 0;i < m;i++)
	{
		for (int j = 0;j < k;j++)
		{
			int temp;
			cin >> temp;
			board[temp].push_back(n + 1 + i);
			board[n + 1 + i].push_back(temp);
		}
	}
	vis[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0;i < board[cur].size();i++)
		{
			if (vis[board[cur][i]] != 0) continue;
			vis[board[cur][i]] = vis[cur] + 1;
			q.push(board[cur][i]);
		}
	}

	if (vis[n] != 0) cout << vis[n]/2+1;
	else cout << -1;

	return 0;
}

/*
�ԷµǴ� ������ Ʃ�� ���� ������ �������� �����Ϸ� ������ �ð��ʰ��� ���� ���Ƽ� ������ Ʃ�� ��ü�� ������ �дٰ� �����ߴ�.
1. ������ Ʃ�굵 ������ ����Ѵٴ� �����Ͽ� ���� ������ 101000���� �� �� �ְ�, �Է��� ���� ��, ������ ���� ���� ���� ���� �����ش�.
2. bfs�� 1�� ���� ���������� ���� �ִ� �Ÿ� ���ϴ� ������� ����
3. ������� �̾� ����, ������ ���� ���ٰ� �ٽ� ���� ������ ������ �������� ���ʿ��� �Ÿ� 1�߰��ǹǷ� ������� 2�� �����ش�
==> ������ ���� ���� ���̾ƴ� ����̹Ƿ� ��θ� �̿��Ҷ����� �ϳ��� ������ �ѷ� �ɰ�����.
4. ���� ���� ��߿��� �湮�� ���̹Ƿ� 1�����༭ ���

*/