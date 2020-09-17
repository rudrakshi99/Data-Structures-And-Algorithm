// make array into max heap and then swap top and last element of heap  and then heapify
// repeat the same process on reduced size of heap
// building heap O(n) + swaping in heap after heapify O(n log n)
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> v){
   for(int x : v){
      cout << x <<" ";
   }
   cout << endl;
}
void buildHeap(vector<int> &v){
   for(int i=1;i<v.size();i++){
        int idx = i; //current
        int parent = i/2;
        while(idx>1 and v[idx]>v[parent]){ // building maxheap
           swap(v[idx],v[parent]);
           idx = parent;
           parent = parent/2;
        }
   }
}
bool minHeap = false;//build max heap
bool compare(int a, int b){ // a-current element, b-parent
       if(minHeap){
          return a < b;
       }
       else{
          return a > b;
       }
    }
void heapify(vector<int> &v,int ind,int size){
        int left = 2*ind;
        int right = 2*ind +1;

        int min_idx = ind; //for pointing the idx
        int last = size-1;

        //find the correct place for min_idx
        if(left <=last && compare(v[left],v[ind])){ //cmpare with left if it is  smaller then min_idx will be left
            min_idx = left;
        }
        if(right <= last && compare(v[right],v[min_idx])){ // compare new min_idx with right
            min_idx = right;
        }

        if(min_idx!=ind){
             swap(v[ind],v[min_idx]);
             heapify(v,min_idx,size);
        }

    }
void heapsort(vector<int> &arr){
   
   buildHeap(arr);
   int n = arr.size();// size of heap

   // remove n-1 elements from the heap
   while(n>1){
     swap(arr[1],arr[n-1]);
     //remove that element from the heap
     n--; //shrinking heap size
     heapify(arr,1,n);  //O(log n) 
   }
}

int main(){

   vector<int> v;
   v.push_back(-1);
   int n;
   cin >> n;
   int temp;
   for(int i=0;i<n;i++){
      cin >> temp;
      v.push_back(temp);
   }
   heapsort(v);
   print(v);
  return 0;
}
