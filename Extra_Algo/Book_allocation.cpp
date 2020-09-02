#include<iostream>
#include<climits>
using namespace std;

bool ispossible(int arr[], int n, int m, int curr){

	int std = 1;
	int pages = 0;

	for(int i =0;i<n;i++){
         if(pages+arr[i]>curr){
			 std ++;
			 pages = arr[i];
			 if(std > m)
			 return false;
		 }
		 else{
			 pages+=arr[i];
		 }
	}
	return true;
}
int pages(int arr[], int n, int m){
	int s =arr[n-1];
	int sum =0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	int e = sum;
    int ans = INT_MAX;
	while(s<=e){
		int mid = (s+e)/2;
		if(ispossible(arr,n,m,mid)){
			ans = min(mid,ans);
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n>> m;
		int arr[n];
		for(int i=0;i<n;i++){
			cin >> arr[i];
		}
      cout << pages(arr, n, m)<<"\n";
	}
	
	return 0;
}