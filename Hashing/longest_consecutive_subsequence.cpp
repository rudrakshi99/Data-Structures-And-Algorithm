// hashing
#include<iostream>
#include<unordered_map>
using namespace std;

int findseq(int arr[], int n){
   
    unordered_map<int,int> m; //number, streak_len

    for(int i=0;i<n;i++){

       int no = arr[i];

       if(m.count(no-1)==0 and m.count(no+1)==0){ //check not  present of just smaller and greater no.
       	   m[no] = 1;
       }
       else if(m.count(no-1) and m.count(no+1)){ //both present
           int len1 = m[no-1];//left len
           int len2 = m[no+1]; //right len

           int streak = len1 + 1 + len2;

           m[no-len1] = streak; //update at first ele of streak
           m[no-len2] = streak; //update at last ele of streak
       }
       else if(m.count(no-1) and !m.count(no+1)){
           int len = m[no-1];  // 1 2 3  7 8 9. [4]
           m[no-len] = len + 1;
           m[no] = len + 1;
       }
       else{
         int len = m[no+1]; //5 6 7. 10 11 12. [9]
         m[no+len] = len + 1;
         m[no] = len + 1;
       }
    }
    int largest = 0;
    for(auto p: m){
       largest = max(largest, p.second);
    }

    return largest;

}




int main(){

	int arr[] = {14,5,1,26,3,7,8,9,13,15,11,12,13,17};
	int n = sizeof(arr)/sizeof(int);

	cout<<findseq(arr, n);

   return 0;
}