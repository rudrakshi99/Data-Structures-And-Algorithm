#include <iostream>
#include <string>
using namespace std;

int sti(string s,int l){

	if(l==-1){
		return 0;
	}

	int last_digit = s[l] - '0';

	int ans = sti(s,l-1) *10 + last_digit;

	return ans;

}



int main()
{
	string s;
	cin >>s;

	int l = s.length(); //

	int x = sti(s,l-1);
	cout<<x<<" "<<x+5;
	return 0;
}