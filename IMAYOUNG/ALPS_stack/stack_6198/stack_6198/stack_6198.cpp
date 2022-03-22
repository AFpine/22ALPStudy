#include <iostream>
#include <stack>
using namespace std;

//������ ��: n�� 80,000,, -> long long

//���ÿ� ������ ���� ��, 
//1, ���� ������ �� �������� ������ ���� �������� ���� ����
//2. ���� ������ �� �������� ������ ���� �������� ���� �Ұ�
//���� �Ұ��� ������ ������
//���ÿ� �����ִ� �������� ���� ���� ���� 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;

	long long sum = 0;
	int n;
	int t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		while (!s.empty()) {
			if (s.top() > t) break;
			s.pop();
		}
		sum += (long long)s.size();
		s.push(t);
	}

	cout << sum << "\n";
	return 0;



}