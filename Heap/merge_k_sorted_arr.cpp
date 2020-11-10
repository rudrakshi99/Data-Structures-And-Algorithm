// used k size heap and pop top element to store in array
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeksortedArrays(vector<vector<int> > arr){
      vector<int> result;
      priority_queue<node, vector<node>, greater<node> > pq; //min heap
      
     //insert the 0th element of every array in the pq - means pushing first k elements
      for(int i=0;i<arr.size();i++){
           pq.push({arr[i][0],{i,0}}); // push(value, (array_idx, element_idx))
      }
      // remove the elements one by one from the min heap and add to result vector
      while(!pq.empty()){

          node current = pq.top();
          pq.pop();
          int element = current.first;
          int x = current.second.first; // row in which element present
          int y = current.second.second; //col in which element present

          result.push_back(element);

          //you need to push the PQ the next element of current element x, y+1
          if(y+1 < arr[x].size()){ //check if exist
             pq.push({arr[x][y+1],{x,y+1}});

          }
      }

      return result;
}

int main(){

	vector<vector<int> > arr{{2,6,12,15},
	                         {1,3,14,20},
	                         {3,5,8,10}};

	vector<int> output = mergeksortedArrays(arr);
	for(auto x: output){
        cout<<x<<" ";
	}

    
  return 0;
}