#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
//�ͳο� �� ������ Map�� �����ϰ�
//���� ������ ��ȣ�� map���� Ž���Ͽ� ������� ���Ϳ� ����
//�� ������ ������ ���� ������ ������ ���Ͽ� ���� �������� �ͳο� �ʰ� ���µ� ���� �������� �ͳο��� �� ���� ���� ���, cnt ++
int main(){
    int N,cnt=0,tmp;
    string str, test;
    unordered_map<string, int> input;
    vector<int> v;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>str;
        input[str]=i;
    }
    for(int i=0;i<N;i++){
        cin>>str;
        v.push_back(input[str]);
    }
    for(int i=0;i<N-1;i++){
        for(int j=i;j<N;j++){
            if(v[i]>v[j]) {
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<"\n";
}