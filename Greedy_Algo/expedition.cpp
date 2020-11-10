#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2 ){
     return p1.first > p2.first;
}

int main() {

   int n,t,x,d,f,D,F,prev=0;
   cin >> t;
   while(t--) {
      
      int flag=0, ans = 0;
      vector<pair<int, int> > v;
      priority_queue<int> pq; //max heap

      cin >> n;
      for(int i=0;i<n;i++){
         cin >> d >> f;
         v.push_back({d,f}); // dist, fuel
      }

      sort(v.begin(),v.end(),compare);

      cin >>D >> F;

      // update the distance of the fuel station from the truck
      for(int i=0;i<n;i++){
         v[i].first = D - v[i].first;
      }

      //prev denotes the prev city we have visited
      prev = 0;
      x = 0; // current city

      while(x<n) {
        //if we have enough fuel to go to next city
        if(F >= (v[x].first - prev)){
           
           F = F- (v[x].first - prev);
           pq.push(v[x].second);// adding fuel
           prev = v[x].first;
        }

        else {
           //check if you have some fueling station visited in the priority
        	if(pq.empty()){
               flag = 1;
               break;
        	}

        	//otherwise refuel the truck with fuel stations with higher capacity
        	F += pq.top();
        	//Remove that fuel station from priority queue
        	pq.pop();
        	ans += 1;
        	continue;
        }

        x++;
      }

      //actually travelled through n fuel stations
      //what is left you have reach the town from the last fuel station
      if(flag==1){
         cout<<-1<<endl;
         continue;
      } 

      //otherwise
      D = D - v[n-1].first;
      if(F>=D){ //if it can cover last distance
         cout<<ans<<endl;
         continue;
      }

      //otherwise
      while(F<D){

        if(pq.empty()){
           flag = 1;
           break;
        }

        F += pq.top();
        pq.pop();
        ans+=1;
      }


      if(flag==1){
          cout<<-1<<endl;
          continue;
      }

      cout<<ans<<endl;

   }
   return 0;
}