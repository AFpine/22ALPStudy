#include <bits/stdc++.h>
using namespace std;
int n;
void func(int depth) {
	
	if (depth == n) {
		for (int i = 0; i < depth; i++) cout << "----";
		cout << "\"����Լ��� ������?\"" << '\n';
		for (int i = 0; i < depth; i++) cout << "----";
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		for (int i = 0; i < depth; i++) cout << "----";
		cout << "��� �亯�Ͽ���." << "\n";
		return ;
	}
	for (int i = 0; i < depth; i++) cout << "----";
	cout << "\"����Լ��� ������?\"" << '\n';
	for (int i = 0; i < depth; i++) cout << "----";
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
	for (int i = 0; i < depth; i++) cout << "----";
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
	for (int i = 0; i < depth; i++) cout << "----";
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" <<'\n';
	func(depth + 1);
	for (int i = 0; i < depth; i++) cout << "----";
	cout << "��� �亯�Ͽ���." << "\n";
	

}
int main(void) {
	
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."<<"\n";
	func(0);
	


}