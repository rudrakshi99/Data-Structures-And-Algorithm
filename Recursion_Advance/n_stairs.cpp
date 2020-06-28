#include<bits/stdc++.h>
using namespace std;
int nstairs(int n, int k){
	int i=0;
	if(n-i==0)
		return 1;
	if(n-i<0)
		return 0;
	int ans=0;
	for(i=1;i<=k;i++){
		
       ans+=nstairs(n-i,k);
	}
	return ans;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
   int n, k;
   cin >>n >> k;
   cout<<nstairs(n, k);
   return 0;
}