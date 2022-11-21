#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second

using namespace std;

char board[12][6];
int result;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool vst[12][6];

bool bfs(int x, int y, char c) { //�μ̴��� �Ⱥμ̴��� return
    queue<pair<int, int>> q;
    vector<pair<int, int>> v; //size�� 4 �̻�Ǹ� ��Ʈ���� �ƴϸ� �ʱ�ȭ�Ѵ�.
    memset(vst, false, sizeof(vst));
    q.push({ x,y });
    v.push_back({ x,y });
    vst[x][y] = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6 || vst[nx][ny]) continue;
            if (board[nx][ny] == c) {
                q.push({ nx,ny });
                v.push_back({ nx,ny });
                vst[nx][ny] = 1;
            }
        }
    }

    if (v.size() >= 4) {
        int vs = v.size();
        for (int i = 0; i < vs; i++) {
            board[v[i].X][v[i].Y] = '.';
        }
        return true;
    }

    return false; //���ν�
}

void down() {

    for (int j = 0; j < 6; j++) { //�� �̵�
        queue<char> q;
        for (int i = 12 - 1; i >= 0; i--) { //�� �Ʒ��� ���� ť�� �ִ´�
            if (board[i][j] != '.') {
                q.push(board[i][j]);
            }
        }
        int qs = q.size();
        for (int i = 12 - 1; i >= 12 - qs; i--) {
            board[i][j] = q.front(); q.pop();
        }
        for (int i = 12 - qs - 1; i >= 0; i--) {
            board[i][j] = '.';
        }
    }


}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //init
    for (int i = 0; i < 12; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++) {
            board[i][j] = s[j];
        }
    }

    while (1) {
        int flag = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] != '.') {
                    if (bfs(i, j, board[i][j])) {
                        flag++;
                    }
                }
            }
        }

        if (flag == 0) break;
        else {
            //�ϳ��� ��Ʈ������ �ٽ� ������ ���� ������ �Լ� ���
            result++;
            down();
        }

    }

    if (result) cout << result;
    else if (result == 0) cout << 0;

}
