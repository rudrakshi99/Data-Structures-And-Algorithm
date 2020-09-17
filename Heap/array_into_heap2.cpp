// optimised Approach - O(N)
#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v){
   for(int x : v){
      cout << x <<" ";
   }
   cout << endl;
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
void heapify(vector<int> &v,int ind){
        int left = 2*ind;
        int right = 2*ind +1;

        int min_idx = ind; //for pointing the idx
        int last = v.size()-1;

        //find the correct place for min_idx
        if(left <=last && compare(v[left],v[ind])){ //cmpare with left if it is  smaller then min_idx will be left
            min_idx = left;
        }
        if(right <= last && compare(v[right],v[min_idx])){ // compare new min_idx with right
            min_idx = right;
        }

        if(min_idx!=ind){
             swap(v[ind],v[min_idx]);
             heapify(v,min_idx);
        }

    }
void buildHeapOptimised(vector<int> &v){
   for(int i=(v.size()-1/2);i>=1;i--){  // starting from first non-leaf node
      heapify(v,i);
   }
}

int main(){
  vector<int> v{-1,10,20,5,6,1,8,9,4};
  print(v); //original
  buildHeapOptimised(v);
  print(v);//heap

  return 0;
}
