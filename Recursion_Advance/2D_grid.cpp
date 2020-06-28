#include<bits/stdc++.h>
using namespace std;
int grid(int n, int m){
	// stand on first block
	if(n==0 && m==0){
		return 1;
	}
	if(n<0 || m<0){
		return 0;
	}
	int ans = grid(n-1,m)+grid(m,n-1);

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
    int n , m;
    cin >> n >> m;
    cout << grid(n-1, m-1);
   return 0;
}