#include <iostream>
#include <cmath>
using namespace std;

/*
    백준 1065번 : 
    https://github.com/dnwls3023/
    
    문제 이해(재정의) : 각 자리의 수가 등차수열을 이룰 경우 이 수를 한수라고 한다. n이 주어질 때 1부터 n 까지의 한수의 개수를 구해라.
    
    접근방법: 1부터 99는 항상 등차수열이다. 따라서 1부터 99까지의 숫자가 입력으로 들어올 경우 그 숫자를 출력해주면 된다.
    그보다 큰 수일경우에는(3자리 이상) 각 자리수의 차이를 구한 뒤 등차수열이면 카운트 하는 방식으로 구한다. 따라서 답은 99 + count 가 된다.
    
    
*/
int n,cnt;

// 한수인가?
bool solve(int num){
  int size = to_string(num).size();
  bool flag = true;
  int diff = (num%10) - ((num/10)%10);
  for(int i = 0 ; i<size-2;++i){
    num/=10;
    if(diff != (num%10 - ((num/10)%10))) flag = false;
  }
  return flag;
}

int main(void){
    cin>>n;
    if(n>99){
      for(int i = 100;i<=n;++i){
        if(solve(i))cnt++;
      }
      cout<<cnt+99<<endl;
    }
  else{
    cout<<n<<endl;
  }
  
    return 0;
}
