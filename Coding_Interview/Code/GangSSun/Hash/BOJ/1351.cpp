#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long func(long long n){
    if(n==0) return 1;
    else if(m[n] != 0) return m[n];
    return m[n]=func(n/P)+func(n/Q);//�־��� ��ȭ���� �̿��� top-down����� dp ����
}
int main(){

    cin>>N>>P>>Q;
    
    cout<<func(N)<<"\n";
}