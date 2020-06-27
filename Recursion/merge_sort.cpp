#include<bits/stdc++.h>
using namespace std;
void merge(int arr, int x[],int y[], int s, int e){
     int mid =(s+e)/2;
     int j = mid+1;
     int k=s;
     int i=s;
     while(i<=mid && j<=e){
     	if(x[i]<y[i]){
     		arr[k]=x[i];
     		i++;
     		k++;
     	}
     	else{
     		arr[k]=y[j];
     		i++;
     		k++;
     	}
     }
     while(i<=mid){
     	arr[k]=x[i];
     		i++;
     		k++;
        }
        while(j<=e){
     	arr[k]=y[j];
     		j++;
     		k++;
        }
  return;
}
void merge_sort(int arr[], int n, int s, int e){
   int mid = (s+e)/2;
   int x[100];
   int y[100];
   for(int i=s;i<=mid;i++){
       x[i]=arr[i];
   }
   for(int i=mid+1;i<=e;i++){
       x[i]=arr[i];
   }
   merge_sort(x,n,s,mid);
   merge_sort(y,n,mid+1,e);
   merge(arr,x,y,s,e);

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
    merge_sort(arr,n,0,n-1);
  return 0;
}