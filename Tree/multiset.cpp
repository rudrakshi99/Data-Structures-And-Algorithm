#include<iostream>
using namespace std;

// associative container - elements are refered by their value and not by the index
//underlying data structure = BST
int main() {


  int arr[] = {10, 20, 30, 20, 10, 10};

  multiset<int> m(arr, arr+6);

  for(int x:m) {
     cout<<x<<",";
  }

  return 0;
}