//number of subarrays such that subarray is divisible by sum of elements of that subarray
//is divisible by N.

//pigeonhole principle 
//(b - a)%n = 0
//b%n = a%n

#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

ll a[1000005], pre[1000005]; // pre - prefix sum array

int main() {
    
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       memset(pre, 0, sizeof(pre));


       pre[0] = 1; // frequency of null subarray =1

       //read the input
       int sum = 0;
       for(int i=0;i<n;i++){
           cin >> a[i];
           sum+= a[i];
           sum %= n;
           sum = (sum+n)%n; // for negative values
           pre[sum]++;
       }

       ll ans = 0;
       for(int i=0; i<n;i++){
           
           ll m = pre[i];
          ans += m*(m-1)/2; //nC2
       }

       cout<<ans<<endl;

    }
    

  return 0;
}