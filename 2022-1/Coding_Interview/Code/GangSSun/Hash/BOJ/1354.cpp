#include <iostream>
#include <map>
using namespace std;

long long N, P, Q, X, Y;
map<long long, long long> m;

long long func(long long n){
    if(n <= 0) return 1;
    else if(m[n]) return m[n];
    return m[n]=func(n/P-X)+func(n/Q-Y);//�־��� ��ȭ���� �̿��� top-down����� dp ����
}
int main(){

    cin>>N>>P>>Q>>X>>Y;
    
    cout<<func(N)<<"\n";
}