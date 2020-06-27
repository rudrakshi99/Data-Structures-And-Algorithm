#include<bits/stdc++.h>
using namespace std;
 int fact(int n){
 	if(n==0)
 		return 1;
 	int ans = n*fact(n-1);

 	return ans;
 }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
    int n;
    cin >> n;
  cout<<fact(n);
return 0;
}