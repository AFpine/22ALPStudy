#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int board[300][300];
int vis[300][300];

void tester()
{
	queue<pair<int, int>> q;
	int d_x[8] = { 1,1,2,2,-1,-1,-2,-2 };
	int d_y[8] = { 2,-2,1,-1,2,-2,1,-1 };
	bool fin_chk = false;
	int n;
	int cur_spot[2], fin_spot[2];
	cin >> n;
	cin >> cur_spot[0] >> cur_spot[1];
	cin >> fin_spot[0] >> fin_spot[1];
	vis[cur_spot[0]][cur_spot[1]] = 1;
	vis[fin_spot[0]][fin_spot[1]] = -1;
	q.push({ cur_spot[0],cur_spot[1] });
	while (!q.empty()&&!fin_chk)
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0;dir < 8;dir++)
		{
			int nx = cur.first + d_x[dir];
			int ny = cur.second + d_y[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (vis[nx][ny] > 0) continue;
			if (vis[nx][ny] == -1)
			{
				cout << vis[cur.first][cur.second] << endl;
				fin_chk = true;
				break;
			}
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}

}

int main()
{
	int cnt;
	cin >> cnt;
	for (int i = 0;i < cnt;i++)
	{
		tester();
		memset(board, 0, sizeof(int) * 90000);
		memset(vis, 0, sizeof(int) * 90000);
	}
	return 0;
}

/*
bfs�� Ȱ���� �ּҰŸ� ���ϱ� �������� ������ ��Ÿ���� d_x,d_y�� ��ǥ�� �� �� �ִ� ���� ���� �÷��� �ϸ� �ɰŶ� ����
1.d_x,d_y�� ���� �����ִ� ���� 8������ Ȯ���ϰ� �׿� �´� ��ǥ�� ����
2.1 ���ķδ� �ּ� �Ÿ��� �������� �����ϴ� ������ ����
*/