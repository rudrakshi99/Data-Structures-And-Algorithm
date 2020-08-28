// deque - double ended queue
#include<iostream>
#include<deque>
using namespace std;

int main(){
	int n;
	int a[10000];
	int k; // size of window
    
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> a[i];
    }
    cin >> k;

    // we have to process first k elements separetly
    deque<int> Q(k);
   
    int i;
    for( i=0;i<k;i++){

    	while(!Q.empty() && a[i]>a[Q.back()]){
    		Q.pop_back();
    	}
    	Q.push_back(i); // pushing indexes
    }
 
   // Process the remaining elements
   for(;i<n;i++){
   	  cout << a[Q.front()]<<" "; // printing the index of max element

   	  //1. Remove the elements which are not the part of the window (Contration)
   	  while(!Q.empty() && (Q.front()<=i-k)){
   	  	 Q.pop_front();
   	  }

   	  //2.Remove the elements which are not useful and are in window
   	  while(!Q.empty() && a[i]>=a[Q.back()]){
   	  	Q.pop_back();
   	  }

   	  //3. Add the new elements(Expansion)
   	  Q.push_back(i); 

   }
  
  cout << a[Q.front()]<<endl;

    return 0;
}