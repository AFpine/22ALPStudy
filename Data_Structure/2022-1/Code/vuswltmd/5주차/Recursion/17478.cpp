#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int N;

void _bar(string str, int stk) {
	for (int j = 0; j < stk; j++) cout << "____";
	cout << str;
}

void func(int cnt)
{
	_bar("\"����Լ��� ������?\"\n", cnt);
	if (cnt == N) _bar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
	else {
		_bar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
		_bar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
		_bar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);
		func(cnt + 1);
	}
	_bar("��� �亯�Ͽ���.\n", cnt);
}

int main()
{
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';

	func(0);
}