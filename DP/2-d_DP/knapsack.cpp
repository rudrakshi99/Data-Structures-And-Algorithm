#include <iostream>
using namespace std;


int maxprofit(int price[],int weigth[],int n,int capacity){

	if(n==0 || capacity==0){
		return 0;
	}

	int inc=0,exc=0;


	if(capacity>=weigth[n-1]){
		inc = price[n-1] + maxprofit(price,weigth,n-1,capacity-weigth[n-1]); //include
	}
	exc =  0 +  maxprofit(price,weigth,n-1,capacity);  //exclude


	return max(inc,exc);

}

int topdown(int price[],int weigth[],int n,int capacity,int dp[][100]){

	if(n==0 || capacity==0){
		dp[n][capacity] = 0;
		return 0;
	}



	if(dp[n][capacity]!=-1){
		return dp[n][capacity];
	}

	int inc=0,exc=0;


	if(capacity>=weigth[n-1]){
		inc = price[n-1] + topdown(price,weigth,n-1,capacity-weigth[n-1],dp); 
	}
	exc =  0 +  topdown(price,weigth,n-1,capacity,dp);


	dp[n][capacity] = max(inc,exc);
	return max(inc,exc);

}

int bottom_up(int price[], int weight[],int n, int capacity){

	int dp[100][100] = {0};

	for(int items = 0; items<=n;items++){
		for(int wei = 0; wei<=capacity;wei++){
			if(items==0 || wei == 0){
				dp[items][wei] = 0;
			}
			else{

				int inc = 0, exc = 0;
				if(wei >= weight[items-1]){
					inc = price[items-1] + dp[items-1][wei-weight[items-1]];

				}
				exc = 0 + dp[items-1][wei];

				dp[items][wei] = max(inc, exc);
			}
		}
	}

  return dp[n][capacity];
}

int main()
{
	int price[]={10,20,10,15};
	int weigth[]={2,2,3,1};

	int capacity;
	cin>>capacity;

int dp[100][100];
for(int i=0;i<100;i++){
	for(int j=0;j<100;j++){
		dp[i][j]=-1;
	}
}

	int n = 4; //no.of elements
	cout<<maxprofit(price,weigth,n,capacity)<<endl;
	cout<<topdown(price,weigth,n,capacity,dp)<<endl;
	cout<<bottom_up(price,weigth,n,capacity);
	return 0;
}