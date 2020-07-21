#include <iostream>
#include <cstring>
using namespace std;


int sas(string s,int len,int k,char ch){


	int i=0;
	int j=0;

	int totalswap = 0;


	for(j=0;j<len;j++){
		if(s[j]!=ch){
			totalswap++;
		}
		if(totalswap == k){
			break;
		}
	}


	int finalans = 0;

	while(i<j){

		while(j <len && s[j+1]==ch){
			j++;
		}

		int ans = j-i+1;

		finalans = max(finalans,ans);

		i++;

		if( j<len && s[i-1]!=ch){
			j++;
		}


	}	


	return finalans;


}

int main()
{
	int k;
	cin>>k;

	cin.ignore();
	string s;

	cin >>s;


	int len = s.length();

	if(k>=len){
		cout<<len;
	}
	else{

		int x = sas(s,len-1,k,'a');

		int y = sas(s,len-1,k,'b');

		cout<<max(x,y);


	} 

	
	return 0;
}