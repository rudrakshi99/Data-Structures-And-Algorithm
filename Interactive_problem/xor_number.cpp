#include<iostream>
using namespace std;

int main(){

	cout<<"? ";

	for(int i=1;i<=100;i++){ // 7 left most significant bits are 0
        cout<<i<<" ";
	}

	cout<<endl;
	int ans;
	cin >> ans;

	int x = 0;

	for(int i=7;i < 14 ;i++){
       if((ans >> i) & 1) { // if ith bit is set
          x|=(1<<i);
       }
	}

	cout<<"? ";

	for(int i=0;i<100;i++){ 
		int cnt = i;
		cnt <<=7;
        cout<<cnt<<" ";  // 7 right most significant bits are 0
	}

	cin >> ans;
	for(int i=0;i < 7 ;i++){
       if((ans >> i) & 1) { // if ith bit is set
          x|=(1<<i);
       }
	}

	cout<<"! "<<x <<endl;

  return 0;
}