// brute force
#include<iostream>
using namespace std;

int main(){
     
    string text = "abaacadbacad";
    string pat = "aaca";

    int n = text.size(), m = pat.size();

    for(int i=0; i+4 <=n;i++){
       if(text.substr(i,m)==pat){
           cout << "Yes found at index " << i;
           return 0;
       }
    }

    cout<<"Not found";
  }