// O(N log N)
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

int main(){
  vector<int> v{-1,10,20,5,6,1,8,9,4};
  print(v); //original
  buildHeap(v);
  print(v);//heap

  return 0;
}