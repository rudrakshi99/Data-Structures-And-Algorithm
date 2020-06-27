#include<bits/stdc++.h>
using namespace std;
void print_dec(int arr[],int i,int n){
	if(i==n)
		return;
	
	print_dec(arr, i+1,n);
    cout<< arr[i]<<" ";  
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
    print_dec(arr,0,n);
return 0;
}