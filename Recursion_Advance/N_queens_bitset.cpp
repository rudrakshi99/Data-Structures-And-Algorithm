//1/n(previous t.c.)
#include<bits/stdc++.h>
using namespace std;

bitset<30> col, d1, d2;

void solve(int r, int n, int &ans){
   
    if(r==n){
        ans++;
        return;
    }

    for(int c=0;c<n;c++){
       if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){  ///column , right dia, left dia in o(1)
           col[c] = d1[r-c+n-1] = d2[r+c] = 1;  //place
           solve(r+1, n, ans);
           col[c] = d1[r-c+n-1] = d2[r+c]=0; //backtrack 
       }
    }

 }
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
   
	int n;
	cin >>n;

	int ans = 0;
	solve(0,n,ans);
	cout<< ans <<"\n";
return 0;
}