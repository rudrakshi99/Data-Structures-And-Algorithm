#include<iostream>
using namespace std;


int main(){

	int n;
	int a[100000];
	cin >> n;
	int no;
	int xo = 0;
	for(int i=0;i<n;i++){
      cin >> no;
      a[i]=no;
      xo = xo^no;
	}

	int temp = xo;
    int pos = 0;
	while((temp&1)!=1){ 
       pos++;           //find the postion of set bit in the result
       temp = temp>>1;
	}

    int mask = (1<<pos);

    //find those number which contain set bit at postion pos
    int x = 0;
    int y = 0;

    for(int i=0;i<n;i++){
       if(a[i]&mask > 0){
          x = x^a[i];
       }
    }

    y = xo^x;
    cout<<min(x,y) <<" "<<max(x,y)<<endl;

  return 0;
}
