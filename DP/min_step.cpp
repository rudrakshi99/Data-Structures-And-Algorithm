#include<iostream>
#include<climits>
using namespace std;

int top_down(int n, int dp[]){
	if(n==1){
		dp[n] = 0;
		return 0;
	}

	int op1,op2,op3;
	op1=op2=op3 = INT_MAX;
    
    if(dp[n]!=-1){ // check
    	return dp[n];
    }
    op1 = 1 + top_down(n-1, dp);

    if(n%2==0){
    	op2 = 1 + top_down(n/2, dp);
    }
    if(n%3==0){
    	op3 = 1 + top_down(n/3, dp);
    }
    
    dp[n] = min(op1,min(op2,op3));
    return dp[n];
}

int bottom_up(int n){
    int dp[10000];

    dp[1] = 0;

    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        op1=op2=op3 = INT_MAX;

        op1 = 1 + dp[i-1];

        if(i%2==0){
        op2 = 1 + dp[i/2];
        }
        if(i%3==0){
           op3 = 1 + dp[i/3] ;
         }
         dp[i] = min(op1,min(op2,op3));
   
    }
 return dp[n];
}
int main() {

    int n;
    int dp[10000];
    cin >> n;
    for(int i=0;i<10000;i++){ //initilize with -1 
    	dp[i] = -1;
    }
    cout<<top_down(n,dp)<<"\n";
    cout<<bottom_up(n)<<"\n";
return 0;
}