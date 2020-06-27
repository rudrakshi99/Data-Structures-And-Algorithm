// sortedarray
#include <iostream>
using namespace std;

bool sortedarray(int a[],int i,int n){


	//ase 

	if(i==n-1){
		return true;
	}


	//ek kamm

	if(a[i]>a[i+1]){
		return false;
	}

	//rec

	bool kyaaagekasortedh = sortedarray(a,i+1,n);
	return kyaaagekasortedh;
}


int main()
{
	int n ;
	cin >> n;

	int a[100];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<boolalpha << sortedarray(a,0,n);
	
	return 0;
}

