#include <iostream>
#define MAX 1001
using namespace std;
 
int arr[MAX][MAX];
int n;
int main() {
	int tmp = 1;
	// input 
	cin>>n;
	for(int i = 0 ;i<n;++i){
		if(i % 2 == 0){
			for(int j = i ;j<n;++j){
				//cout<<4-j+i<<" "<<j<<"\n";
				arr[n-1-j+i][j] = tmp++;
			}
		}
		else{
			for(int j = i ;j<n;++j){
				//cout<<4-j+i<<" "<<j<<"\n";
				arr[j][n-1-j+i] = tmp++;
			}
		}
 
 
	}
 
	for(int i = 0 ; i<n;++i){
		for(int j = 0; j <n;++j){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
