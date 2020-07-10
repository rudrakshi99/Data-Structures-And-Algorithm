#include <iostream>
using namespace std;

bool prime[10000000] ;

int ans[10000000];
int index = 0; 



void prime_seive(int n){

	for(int i=0;i<10000000;i++){
		prime[i] = true;


	prime[0]=false;
	prime[1]=false;

	for(int i=2;i*i<10000000;i++){
		if(prime[i]==true){
			for(int j=i;j*i<10000000;j++){
				prime[i*j]=false;
			}
		}
	}

	for(int i=0;i<10000000;i++){
		if(prime[i]==true){
			ans[index]=i;
			index++;
		}
	}

	cout<<ans[n-1];

}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	
	prime_seive(n);

while(t--){
	int n;

	cin >> n;

	cout<<ans[n-1]<<endl;	
}
	return 0;
}
