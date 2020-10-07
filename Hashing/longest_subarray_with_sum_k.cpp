#include<iostream>
#include<unordered_map>
using namespace std;

int longestsubarry(int arr[],int n,int k){
    
    unordered_map<int, int> m; // csum, index
    int pre = 0;

    int len = 0;

    for(int i=0;i<n;i++){
        pre += arr[i];

        if(pre==k){
           len = max(len, i+1); //i+1 because 0 based indexing
        }
        if(m.find(pre-k)!=m.end()){ //repeating number
           len = max(len, i - m[pre-k]); //i - first occurence of csum
        }
        else{
          //store the first occ
          m[pre] = i;
        }
    }
    return len;
}

int main(){
     int n,k;
     cin >> n>>k;

     int arr[n];

     for(int i=0;i<n;i++){
         cin >> arr[i];
     } 

     cout<<longestsubarry(arr,n,k);
  
  return 0;
}