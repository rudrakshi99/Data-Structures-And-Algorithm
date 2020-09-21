//median in a running stream of integers 
#include<iostream>
#include<queue>
using namespace std;

int main(){
   
  priority_queue<int> leftheap; //maxheap - contains smaller elements than mid
  priority_queue<int, vector<int>, greater<int> >  rightheap; //min heap -contains larger elements than mid

  int d;
  cin >> d;
  leftheap.push(d);
  float med = d;
  cout<<"Med "<<med << endl;
  //input all elements

  while(d!=-1){
     cin >> d;
     
    if(leftheap.size()>rightheap.size()){
       if(d<med){
          rightheap.push(leftheap.top()); //for balancing 
          leftheap.pop();
          leftheap.push(d);
       }
       else{
         rightheap.push(d);
       }
       med = (leftheap.top()+rightheap.top())/2.0;
    }
    else if(leftheap.size()==rightheap.size()){ // when both heap has even number of elements

    	if(d < med){
           leftheap.push(d);
           med = leftheap.top();
    	}
    	else{
           rightheap.push(d);
           med = rightheap.top();
    	}
       
    }
    else{
     if(d>med){
          leftheap.push(rightheap.top()); //for balancing 
          rightheap.pop();
          rightheap.push(d);
       }
       else{
         leftheap.push(d);
       }
       med = (leftheap.top()+rightheap.top())/2.0;
       
    }




     cout<<"Med "<<med << endl;
    
  }


  return 0;
  
}