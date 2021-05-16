#include <iostream>
using namespace std;
 
int arr[5][5];
 
int main() {
	int tmp = 1;
	for(int i = 0 ;i<5;++i){
		if(i % 2 == 0){
			for(int j = i ;j<5;++j){
				//cout<<4-j+i<<" "<<j<<"\n";
				arr[4-j+i][j] = tmp++;
			}
		}
		else{
			for(int j = i ;j<5;++j){
				//cout<<4-j+i<<" "<<j<<"\n";
				arr[j][4-j+i] = tmp++;
			}
		}
 
 
	}
 
	for(int i = 0 ; i<5;++i){
		for(int j = 0; j <5;++j){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
