#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int abs(int i,int j){

     if(i-j>0){
        return i-j;
     }
     return j-i;
}

int main() {
     
     int arr[100000] = {0};
     int t,n;
     cin >> t;

     while(t--) {

        memset(arr,0,sizeof(arr));
        string name;
        int n,rank ,sum=0;
        cin >> n;

        for(int i=0;i<n;i++){

            cin >> name >> rank;
            arr[rank]++;
        }

        //assign the team nearest rank avilable
        int actual_rank = 1;
        for(int i=1;i<=n;i++){
           
           while(arr[i]){
             sum += abs(actual_rank,i);
             arr[i]--;
             actual_rank++;
           }

        }
        cout<<sum<<"\n";
     }
     
    return 0;
}