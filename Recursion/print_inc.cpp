#include<bits/stdc++.h>
using namespace std;
void print_inc(int arr[],int i,int n){
	if(i==n)
		return;
	cout<< arr[i]<<" ";
	print_inc(arr, i+1,n);  
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
    int n;
    cin >> n;
    int arr[100];
    for(int i=0;i<n;i++)
    	cin >> arr[i];
    print_inc(arr,0,n);
return 0;
}