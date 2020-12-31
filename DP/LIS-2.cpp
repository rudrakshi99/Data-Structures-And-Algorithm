
#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
          cin >> a[i];
	}

	int dp[n+1];

	dp[0]=INT_MIN;
	for(int i=1;i<=n;i++){
       dp[i] = INT_MAX;
	}

	// for(int i=0;i<n;i++){ //O(N^2)
 //       for(int len = 0;len <n;len++){
 //           if(dp[len] < a[i] && a[i] < a[len+1]){
 //               dp[len+1] = a[i];
 //           }
 //       }
	// }

	for(int i=0;i<n;i++){ //O(Nlog n)
        
        int len = upper_bound(dp, dp+n+1, a[i])-dp;
           if(dp[len-1] < a[i] && a[i] < a[len]){
               dp[len] = a[i];
           }
       
	}

	int lis= 0;
	for(int i=1;i<=n;i++){
       if(dp[i]!=INT_MAX){
           lis = i;
       }
	}
   return 0;
	
}