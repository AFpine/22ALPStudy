#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, double> m;
    string str;
    double sum=0;
    
    while(getline(cin, str)){
        
        sum++;
        m[str]++;//�ش� ���� �Է¹����� ���� ���� ++
    }
    cout<<fixed;
    cout.precision(4);
    for(auto iter=m.begin();iter!=m.end();iter++){
        cout<<iter->first<<" "<<(iter->second/sum*100)<<endl;//map�� ��ȸ�ϸ� �ش� ���� ������ ���
    }
    
}