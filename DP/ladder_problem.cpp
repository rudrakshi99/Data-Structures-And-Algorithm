#include<iostream>
using namespace std;

//o(nk)
int ladders_topdown(int n, int k, int dp[]){
 
    //base case
    if(n==0){
       return 1;
    }
    //look up

    if(dp[n]!=0){
         return dp[n];
    }

    //rec case
    int ways = 0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
           ways += ladders_topdown(n-i,k,dp);
        }
    }

    return dp[n] = ways;
}

int ladders_bottomup(int n, int k){
  
    int dp[100] = {0};

    dp[0] = 1;
    for(int i=1;i<=n;i++){
       dp[i] = 0;
       for(int j=1; j<=k;j++){
         if(i-j>=0){
            dp[i] += dp[i-j];
         }
       }
    }
     return dp[n];
}

//another optimise implementation
int ladders_optimised(int n, int k){
    
    int dp[100] = {0};

    dp[0] = dp[1] = 1;
    for(int i=2;i<=k;i++){
       dp[i] = 2*dp[i-1];
    }
 
    for(int i=k+1; i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    return dp[n];
}
int main(){

   int n,k;
   int dp[100] = {0};
   cin >> n >> k;
   cout<<ladders_topdown(n,k,dp)<<"\n";
   cout<<ladders_bottomup(n,k)<<"\n";
   cout<<ladders_optimised(n,k)<<"\n";

   return 0;
}