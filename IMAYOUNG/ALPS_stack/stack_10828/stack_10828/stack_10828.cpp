#include <iostream>
#include <stack>
#include <string>
using namespace std;

//���� = �����۽� ��!! 
//�������� ���� �͸� �߰�, ���Ⱑ ����


int main() {
	stack<int> a;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string ch;
		cin >> ch;
		if (ch == "push") {
			int x;
			cin >> x;
			a.push(x);
		}
		else if (ch == "pop") {
			if (a.empty() == 1) {
				cout << -1 << "\n";
			}
			else {
				a.pop();
			}
		}
		else if (ch == "size") {
			cout << a.size() << "\n";
		}
		else if (ch == "empty") {
			cout << a.empty() << "\n";
		}
		else if (ch == "top") {
			{
				if (a.empty() == 1) { //����ִ�. 
					cout << -1 << "\n";
				}
				else {
					cout << a.top() << "\n";
				}

			}

		}

	}

}