#include <iostream>
#include <stack>
#include <utility>
using namespace std;
//���ÿ��� pair��� ���� ����.
//<utility> ����� ����.
//�ַ� x,y ��ǥ�� ������ �迭�� �ε��� ��. 


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	stack < pair<int, int>> s;
	s.push({ 100000001,0 }); //���� �ʱ�ȭ

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		while (s.top().first < t) {
			s.pop();
		}
		cout << s.top().second << " ";
		s.push({ t, i });

	}

}