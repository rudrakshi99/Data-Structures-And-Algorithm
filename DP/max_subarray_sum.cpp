#include<iostream>
using namespace std;

//o(n)
int maxSum(int a[], int n){
   
   int dp[100] = {0};
   dp[0] = a[0]>0?a[0]:0; //only take +ve value otherwise 0
   int max_so_far = dp[0];

   for(int i=1;i<n;i++){
       dp[i] = dp[i-1] + a[i];
       if(dp[i]<0){ //when sum became -ve
           dp[i] = 0;
       }
       max_so_far = max(dp[i],max_so_far);
   }

   return max_so_far;
}

//space optimized code
// kadane's algo

int maxSumSpaceOpt(int a[], int n){
   
   int current_sum = 0;
   int max_so_far = 0;

   for(int i=0;i<n;i++){
      current_sum+=a[i];
      if(current_sum<0){
         current_sum = 0;
      }
      max_so_far = max(current_sum, max_so_far);
   }

   return max_so_far;
}

//special case 
//if array contains all -ve elements
// you need output the smallest -ve elements
int main(){
  
  int a[] ={-3,2,5,-1,6,3,-2,7,-5,2};
  int n = sizeof(a)/sizeof(int);

  cout << maxSum(a,n);
  return 0;
}