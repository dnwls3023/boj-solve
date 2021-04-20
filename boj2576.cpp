#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 이용
using namespace std;

/*
    백준 2576번 : 
    https://github.com/dnwls3023/
    
    접근방법:
    7개의 자연수중 홀수를 vector에 push_back 한 뒤 합을 구하고 정렬하여 최소값을 구한다.
    홀수가 존재하지 않는 경우에는 -1을 출력해야 하므로 flag 변수를 사용하여 
    홀수가 한개라도 주어진다면 true로 처리하고 flag가 false라면 -1을 출력한다.
    
    알고리즘 설명:
    접근 그대로
*/

vector<int> vec;

int main(void){
    int n;
    bool flag =false;

    for(int i = 0 ; i<7;++i){
        cin>>n;
        if(n%2==1){
            vec.push_back(n);
            flag = true;
        }
            
    }
    
    sort(vec.begin(),vec.end());

    int sum = 0;
    for(int i = 0 ;i<vec.size();++i){
        sum+=vec[i];
    }
    if(flag){
        cout<<sum<<endl;
        cout<<vec[0]<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    

    return 0;
}
