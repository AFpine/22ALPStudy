#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

//map�� �̸�, ���� I�� ������ ����
//�� ���� map�� �̸��� �����ϴ��� Ȯ����, �����Ѵٸ� �߰��ϰ� ���ٸ� ���� ����
//�������� �ʴ� �̸��� �ԷµȰ�� ����
//������ ������ ���, �̸��� key�� �Ͽ� �ε����� ã��, �� �ش� set���� �̵�
int main(){
    map<string, long long> name;
    vector<multiset<long long>> info;//��ġ�� ������ �������� ������ �Էµ� �� ������ multiset���

    long long Q,menu,k,c,cnt=0,num;
    long long vidx=0,idx,info_cnt,tmp;
    string str;

    cin>>Q;
    for(long long i=0;i<Q;i++){
        cin>>menu;
        if(menu==1){
            cin>>str>>k;
            if(name.find(str)==name.end()){//�������� �ʴ� ���
                name[str]=vidx;
                vidx++;//���� ������ index ����
                multiset<long long> tmp;
                for(long long j=0;j<k;j++){
                    cin>>num;
                    tmp.insert(num);//�ӽ� set�� �������� ����
                }
                info.push_back(tmp);//vector�� �ӽ� set����
            }
            else{//�����ϴ� ���
                idx=name[str];
                for(long long j=0;j<k;j++){
                    cin>>num;
                    info[idx].insert(num);
                }
            }
        }
        else if(menu==2){
            cin>>str>>info_cnt;
            if(name.find(str)!=name.end()){//�̸��� �����ϴ� ���
                idx=name[str];//�ش� ���� ������ �̸��� �����Ͽ� �ε����� ����
                for(auto iter=info[idx].rbegin();iter!=info[idx].rend();){//�ش� set�� ��ȸ
                    tmp=*iter;
                    multiset<long long>::iterator it=info[idx].find(tmp);//������ ������ �� ������°��� �����ϱ� ���� �ݺ��� ���
                    info[idx].erase(it);//�ŷ��� ���� set���� ����
                    cnt+=tmp;
                    info_cnt--;
                    if(!info_cnt) break;
                }
            }
            else continue;
        }
    }
    cout<<cnt<<"\n";
}