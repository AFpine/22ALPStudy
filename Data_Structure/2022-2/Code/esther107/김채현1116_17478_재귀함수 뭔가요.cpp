#include <iostream>
using namespace std;

int i = 0;

void Line(int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
		cout << "____";
}

int RecursiveFunc(int repeat)
{
	i++;
	if (repeat >= 1) {
		Line(i);
		cout << "\"����Լ��� ������?\"\n";
		Line(i);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		Line(i);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		Line(i);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		RecursiveFunc(repeat - 1);
		i--;
		Line(i);
		cout << "��� �亯�Ͽ���.\n";
	}

	else {
		Line(i);
		cout << "\"����Լ��� ������?\"\n";
		Line(i);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		Line(i);
		cout << "��� �亯�Ͽ���.\n";

		return 0;
	}

}



int main(void)
{
	int repeat = 0;
	cin >> repeat;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	RecursiveFunc(repeat);
	return 0;
}
