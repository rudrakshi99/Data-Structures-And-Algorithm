#include<bits/stdc++.h>
using namespace std;

int query(int i, int j){

	cout<< "? "<<i << " "<<j<<endl;
	int ans;
	cin >> ans;
	return ans;
}

int main(){

	vector<int> v ={4, 8, 15, 16, 23,42};

	vector<int> a(4);

	for(int i=0;i<4;i++){
		a[i]  = query(i+1, i+2);
	}

	do{
		bool can = 1;
		for(int i=0;i<4;i++){
			if(a[i]!= v[i]*v[i+1]) {
				can = 0;
			}
		}

		if(can==1){
			cout<<"! ";
			for(auto x:v){
				cout<<x<<" ";
			}
			cout<<"\n";
			return 0;
		}
	}while(next_permutation(v.begin(),v.end()));

	return 0;
}