#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> S;
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			S.pop();
		}
		else {
			S.push(num);
		}
	}

	int sum = 0;

	//���� �� ���� ����. ���ϰ� ���� ���ڸ� ��� ����.
	for (int i = 0; i <= k; i++) {
		sum += S.top();
		S.pop();
	}

	cout << sum;
	
}