//#include <bits/stdc++.h>
//
//char c = '"';
//int count;
//
//void what_is_recursive(int n) {
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << c << "����Լ��� ������?" << c << "\n";
//	if (n == 0) {
//		for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//		std::cout << c << "����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����" << c << "\n";
//		for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//		std::cout << "��� �亯�Ͽ���.\n";
//		return;
//	}
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << c << "�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������." << c << "\n";
//	what_is_recursive(n - 1);
//	for (int i = 0; i < 4 * (count - n); i++) std::cout << "_";
//	std::cout << "��� �亯�Ͽ���.\n";
//}
//
//int main() {
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//
//	int n;
//	std::cin >> n;
//	count = n;
//
//	std::cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
//	what_is_recursive(n);
//	return 0;
//}