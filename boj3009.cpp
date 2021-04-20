#include <iostream>
#include <map>
using namespace std;

map<int,int> ma;
map<int,int> mb;
/*
    백준 3009번

    a b를 각각 입력받아 갯수를 세어 
    갯수가 한개인 것을 출력했다.
    
*/

int main(void){
    int a,b;
    for(int i = 0 ;i<3;++i){
        cin>>a>>b;
        ma[a]++;mb[b]++;
    }
    int ansa,ansb;
    for(auto iter = ma.begin();iter != ma.end();++iter)
        if(iter->second == 1)
            ansa=iter->first;

        
    for(auto iter = mb.begin();iter != mb.end();++iter)
        if(iter->second == 1)
            ansb=iter->first;
    
    cout<<ansa<<" "<<ansb<<Endl;
    return 0;
}
