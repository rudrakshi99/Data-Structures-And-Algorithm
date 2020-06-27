#include <iostream>
using namespace std;

int main()
{
	int a[]={5,3,1,2,4};
	int n = sizeof(a)/sizeof(int);

	for(int i=0;i<n-1 ;i++){
		for(int j =0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}	 	
	return 0;
}