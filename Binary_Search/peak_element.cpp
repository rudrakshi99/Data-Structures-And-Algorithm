//A peak element is an element that is strictly greater than its neighbors. 

#include <bits/stdc++.h>
using namespace std;

int peakElement(vector<int>&nums){

    int n= nums.size();
    int l=0, r=n-1;

    while(l<r){
        int m = (l+r)/2;

        if(nums[m-1]<nums[m] && nums[m]>nums[m+1]){
            return m;
        }
        else if(nums[m]<nums[m+1]){
            l++;
        }
        else{
          r--;
        }
    }
    return l;
}

int main(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(auto &x:nums)cin>>x;
    cout<<peakElement(nums)<<"\n";
}

