#include<iostream>
using namespace std;

int query(int middle){
   
    cout<<middle<<endl;
    string res;
    cin >> res;

    if(res=="<") return 1;

    else return 2;

}

int main(){

   int l = 1, r = 1e6, ans = 0;
   while(l <= r){
      
      int middle = (l+r)/2;


      if(query(middle) == 1){
      	  ans = middle;
          r = middle - 1;
      }
      else{
            l = middle + 1;
      }
     cout<<"! "<<ans<<endl;
   }

  return 0;
}