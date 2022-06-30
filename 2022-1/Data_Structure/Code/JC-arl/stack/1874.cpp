#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	stack<int> st;
	queue<char> qu;
	int num, count = 0;
	cin >> num;
	for (int i = 1; i <= n; i++)
	{
		st.push(i);
		qu.push('+');
		while (1)
		{
			if (st.empty())
				break;
			if (st.top() == num)
			{

				st.pop();
				qu.push('-');
				if (count == n - 1)
					break;
				scanf("%d", &num);		//������
				count++;
			}
			else
			{
				break;
			}

		}
	}if (!st.empty())
		cout << "NO";
	else
		while (!qu.empty())
		{
			printf("%c\n", qu.front());
			//cout << qu.front()<<endl;
			qu.pop();
		}




	return 0;
}
//1234-num== =>pop
/*�Է��� 1~n���� �ϳ��� �������(*�ߺ�x
* ����� �Էµ� ������ ����� ���� ���� ���
* + - push
* - - pop
*
*  push�� 1���� �������� �Է�
*
* Ǯ�� -
*/
