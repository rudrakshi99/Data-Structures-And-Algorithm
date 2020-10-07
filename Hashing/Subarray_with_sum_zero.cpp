//check if sum is alrady present i.e. if we add and subtract same ammount the sum become equal
/// implies that subarraywith 0 sum is present
#include<iostream>
#include<unordered_set>
using namespace std;

bool checksum(int arr[],int n){
    
    unordered_set<int> s;

    int pre = 0;
    for(int i=0;i<n;i++){
       pre+= arr[i];

       //check if the sum was already present in the set
       if(pre== 0 or s.find(pre)!=s.end()){
           return true;
       }
       s.insert(pre);
    }
  return false;
}

int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i=0;i<n;i++){
         cin >> arr[i];
     } 

     if(checksum(arr, n)){
         cout<<"Yes";
     }
     else{
        cout<<"No";
     }
  
  return 0;
}