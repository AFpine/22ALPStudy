#include <iostream>
#include <queue>

using namespace std;

int board[1000][1000];
int vis[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	queue<pair<int, int>> q;
	int d_x[4] = { 1,0,-1,0 };
	int d_y[4] = { 0,-1,0,1 };
	bool dont_fin_all = false,fin_already=true;
	int n, m, day=-1;
	cin >> m >> n;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> board[j][i];
			if (board[j][i]==1)  q.push({ j,i });
			if (board[j][i]==0)
			{
				vis[j][i] = -1;
				fin_already = false;
			}
		}
	}
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 4;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (vis[nx][ny]>=0) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}
	
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (vis[j][i]==-1)
			{
				dont_fin_all = true;
			}
			if (vis[j][i] > day) day = vis[j][i];
		}
	}

	if (dont_fin_all||fin_already)
	{
		if (fin_already) cout << 0;
		else cout << -1;
	}
	else cout << day;

	return 0;
}

/*
ó���� �丶�� ���ڿ� ���� �丶�䰡 ������ �� �� �����Ƿ� �Է� ���� �� ���� �丶�並 �̸� ť�� �־���� �ȴٰ� ����+�丶�䰡 ���� �ʹ� �ð��� �Ÿ��������� ���Դ� �ּ� �Ÿ� ã�� ������ ����(ť�� FIFO���� �̿�)
1. vis�� ����, �� ���� �丶�䰡 ���´ٸ�, �丶�䰡 ���� ������ �����ϱ� ���� -1�� �Է� --> ���߿� ������ ������ ������ �丶�䰡 �����ϴ����� ���� �Ǵ��� ����
2. vis�迭 �� ���Ҵ� ���� �丶��� ������ �Ÿ�(�Ÿ� 1�� �ð� 1�ϰ� ���� �ǹ�)�� �ǹ��ϹǷ� �Ÿ������� ����ϰ� cur�� vis���� +1��ŭ�� ���ο� vis[nx][ny]�� ����
3. ť������ ��� �۾��� ����ǰ� ���� �丶�信 ������ �丶�䰡 �����ϴ� �� ���� üũ(vis�迭 ������ -1üũ)�� �Բ� vis�迭 �� �ִ밪 ã��(�� ���� ������ �ɸ� �ִ� �ϼ�)
*/