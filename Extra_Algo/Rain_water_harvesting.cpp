#include<bits/stdc++.h>
using namespace std;
int rwh(int a[], int n){
	int larr[n];
	int rarr[n];
	larr[0]=0;
    int lmax = a[0];
	rarr[n-1]=0;
	int rmax = a[n-1];
	for(int i=1;i<n;i++){
		larr[i]=lmax;
		lmax = max(lmax, a[i]);
	}
	for(int i=n-2;i>=0;i--){
		rarr[i]=rmax;
		rmax = max(rmax,a[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(min(larr[i],rarr[i])-a[i]>0)
		ans+=min(larr[i],rarr[i])-a[i];
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin  >> a[i];
	}
    cout << rwh(a,n);
	return 0;
}