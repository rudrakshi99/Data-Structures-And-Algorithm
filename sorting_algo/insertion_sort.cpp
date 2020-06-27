// isertio sort
#include <iostream>
using namespace std;

int main()
{
	int a[]={5,3,1,2,4};
	int n = sizeof(a)/sizeof(int);
	
	for(int i = 1;i<n ;i++ ){
		for(int j = i; j>0 ; j-- ){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}
			else{
				break;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}


	return 0;
}