#include <iostream>
#include <vector>
#include <algorithm> // sort 함수 이용
using namespace std;

/*
    백준 2576번 : 
    https://github.com/dnwls3023/
    
    접근방법:
    7개의 자연수중 홀수를 vector에 push_back 한 뒤 합을 구하고 정렬하여 최소값을 구한다.
    
    알고리즘 설명:
    접근 그대로
*/

vector<int> vec;

int main(void){
    int n;

    for(int i = 0 ; i<7;++i){
        cin>>n;
        if(n%2==1)
            vec.push_back(n);
    }
    
    sort(vec.begin(),vec.end());

    int sum = 0;
    for(int i = 0 ;i<vec.size();++i){
        sum+=vec[i];
    }
    cout<<sum<<endl;
    cout<<vec[0]<<endl;

    return 0;
}
