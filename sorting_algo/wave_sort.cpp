//O(n)
#include<iostream>
using namespace std;

int main() {
    

    int a[] = {1,3,4,2,7,4};
    //sort the arr in wave form
     
     int n = sizeof(a)/sizeof(int);

     for(int i=0;i<n;i=i+2){

        //Prev element
        if(i!=0 && a[i] < a[i-1]){

           swap(a[i],a[i-1]);
        }

        //next element
        if(i!=n-1 && a[i] < a[i+1]){
             swap(a[i],a[i+1]);
        }
     }

     for(int i=0;i<n;i++){
         cout<<a[i] <<" ";
     }

    return 0;
}