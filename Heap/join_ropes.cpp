/* Given N ropes of different sizes, we have to join them.
The cost of joining two ropes A and B is A+B. Find the minimum cost. */

#include<iostream>
#include<queue>
using namespace std;


int join_ropes(int ropes[],int n){
   priority_queue<int,vector<int>,greater<int> > pq(ropes, ropes+n); //min heap
   int cost = 0;

   while(pq.size() > 1){
      int A = pq.top();
      pq.pop();

      int B = pq.top();
      pq.pop();

      // find two smallest ropes and add them
      int new_rope = (A+B);
      cost+= new_rope;
      pq.push(new_rope);

   }
  return cost;
}

int main(){
  int ropes[] = {4,3,2,6};
  int n = 4;

  cout<< join_ropes(ropes, n)<<endl;

}