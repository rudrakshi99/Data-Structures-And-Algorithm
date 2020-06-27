#include <iostream>
#include <string>
using namespace std;

//gloal
string s[] = {"zero","one","two","three","four","five","sixe","seven","eight","nine"};

void inttoword(int x){


	//ase co

	if(x==0){
		return;
	}

	inttoword(x/10);

	cout<< s[x%10]<<" ";

}



int main()
{
	int x;
	cin >>x;


	inttoword(x);

	
	return 0;
}