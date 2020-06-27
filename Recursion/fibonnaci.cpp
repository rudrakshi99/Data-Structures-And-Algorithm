#include<bits/stdc++.h>
using namespace std;
int fib(int n){
	if(n==0 || n==1)
		return n;
	int ans = fib(n-1)+fib(n-2);
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
    int n;
    cin >> n;
  cout<<fib(n);
return 0;
}