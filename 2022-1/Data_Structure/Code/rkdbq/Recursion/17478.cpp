#include <iostream>
using namespace std;

int N;

void rec(int n) {
	if (n == N) cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	for (int i{}; i < 4 * (N - n); i++) cout << "_";
	cout << "\"����Լ��� ������?\"\n";
	if (n == 0) {
		for (int i{}; i < 4 * (N - n); i++) cout << "_";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i{}; i < 4 * (N - n); i++) cout << "_";
		cout << "��� �亯�Ͽ���.\n";
		return;
	}
	for (int i{}; i < 4 * (N - n); i++) cout << "_";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i{}; i < 4 * (N - n); i++) cout << "_";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i{}; i < 4 * (N - n); i++) cout << "_";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	rec(n - 1);
	for (int i{}; i < 4 * (N - n); i++) cout << "_";
	cout << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	rec(N);
	return 0;
}