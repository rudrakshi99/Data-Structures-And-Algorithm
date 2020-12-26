#include<bits/stdc++.h>
using namespace std;
string key[] = {".%","+*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(char a[], int i,char output[], int j ){
	// base 
	if(a[i]=='\0'){
		output[j]='\0';
		cout<<output<<"\n";
		return;
	}
	int digit = a[i]-'0';// converting into int
	if(digit==1 || digit==0){ //contain null str
	      keypad(a, i+1, output,j); //move to next
	}
    for(int index=0; key[digit][index]!='\0';index++){
    	output[j]=key[digit][index];
    	keypad(a, i+1, output,j+1);
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);  
#endif
    char a[100];
	cin >> a;
	char output[100];
    keypad(a,0,output,0);
  return 0;
}
