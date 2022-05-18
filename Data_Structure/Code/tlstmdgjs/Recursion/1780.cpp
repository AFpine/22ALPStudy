#include <bits/stdc++.h>
using namespace std;

int val[3]; //-1,0,1�� ä���� ���̰���
int board[2187][2187];

//���̾ȿ� ��� ĭ���� ���� ������ �ƴ��� �Ǵ��ϴ� �Լ�
bool check(int r, int c, int n) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (board[r][c] != board[i][j])
				return false;
		}
	}
	return true;
}

//9�����ϴ� �Լ�
void divide(int r, int c, int n) {
	if (check(r, c, n)) { //��� ĭ���� ���� ���� ���� ���
		val[board[r][c]]++;
	}
	else {
		int size = n / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(r + size * i, c + size * j, size); //��� �Լ� ȣ��?
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			board[i][j]++;
		}
	}
	divide(0, 0, n);
	cout << val[0] << "\n" << val[1] << "\n" << val[2];
}