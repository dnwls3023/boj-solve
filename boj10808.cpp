#include <iostream>
using namespace std;

/*
    백준 10808번 : 
    https://github.com/dnwls3023/
    
    접근방법:
    배열을 사용하여 각각의 알파벳 수를 세주었다.
    알고리즘 설명:
    ex) alphabet[0] : 알파벳 a 의 갯수 ...
*/

int alphabet[26];
string str;

int main(void){
    cin>>str;
    for(int i = 0 ;i<str.size();++i){
        alphabet[str[i]-'a']++;
    }
    for(int i = 0 ; i<26;++i) cout<<alphabet[i]<<" ";
    cout<<endl;
    return 0;
}
