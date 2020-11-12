#include<iostream>
using namespace std;

int countBitsFast(int n){

   int ans = 0;
   while(n>0){
      n = n&(n-1); //remove set countBitsFast
      ans++;
   }
   return ans;
}

int main(){

    int n ;
    cin >> n;
    cout << countBitsFast(n);
}