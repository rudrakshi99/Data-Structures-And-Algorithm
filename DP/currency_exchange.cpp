#include<iostream>
#include<climits>
using namespace std;

int top_down(int coins[],int n,int amount, int dp[]){

	if(amount == 0){
		dp[amount] = 0;
		return 0;
	}
   
    if(dp[amount]!=-1){
    	return dp[amount];
    }

	int ans = INT_MAX;

	for(int i=0;i<n;i++){

		if(amount>=coins[i]){ // can give coin
           int remaining = top_down(coins, n, amount-coins[i], dp) + 1;
           ans = min(remaining, ans);
           
		}
	}
    dp[amount] = ans;
	return ans;
}

int bottom_up(int coins[],int n,int amount){
	int dp[1000];

	for(int i=0;i<1000;i++){  
    	dp[i] = INT_MAX;
    }

	dp[0] = 0;

	for(int rupay = 1; rupay<=amount; rupay++){

		for (int i = 0; i < n; i++)
		{
			if(rupay >= coins[i]){
                dp[rupay] = min(dp[rupay], dp[rupay-coins[i]]+1);
			} 
		}
	}
	return dp[amount];
}

int main(){

	int coins [] = {1, 7, 10};

	int n = sizeof(coins)/sizeof(int);

	int amount;
	cin >> amount;
    int dp[10000];

   
    for(int i=0;i<10000;i++){ //initilize with -1 
    	dp[i] = -1;
    }
	cout << top_down(coins, n, amount, dp)<<"\n";
	cout<<bottom_up(coins, n, amount);

	return 0;
}