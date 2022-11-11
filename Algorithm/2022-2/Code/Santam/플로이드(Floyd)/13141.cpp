#include <bits/stdc++.h>
#define Max_V 200000

using namespace std;
int n, m;
double res = Max_V;
int board[201][201]{};
int adj[201][201];

double simulation(int s_n)
{
    double max_length = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] == Max_V) continue; //�� ��� ���� ���� ���� ���� pass
            double remain = adj[i][j]-(board[s_n][j]-board[s_n][i]); //�� ��尡 ��ȭ�Ǵ� �ð��� ����*2 ��ŭ ���� ������ �¿����Ƿ� ���� ����
            if(remain) max_length = max(remain/2+board[s_n][j], max_length);
        }
    }
    if (max_length == 0) return Max_V;
    return max_length;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    for (int i = 1; i <= 200; i++)
    {
        for (int j = 1; j <= 200; j++)
        {
            board[i][j] = Max_V;
            if (i == j) board[i][j] = 0;
        }
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, t, v;
        cin >> s >> t >> v;
        if (board[s][t] > v)
        {
            board[s][t] = v;
            board[t][s] = v;
        }
        if (adj[s][t] < v) {
            adj[s][t] = v;
            adj[t][s] = v; //���߿� Ž���� ���� ���� ������(���� ��͸�) ����
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    } // 1. �� ��� ������ �ּ� �Ÿ��� ���� (�÷��̵�)

    for (int i = 1; i <= n; i++)
    {
        res = min(simulation(i), res);
    }
    cout << fixed;
    cout.precision(1);
    cout << res;
    return 0;
}