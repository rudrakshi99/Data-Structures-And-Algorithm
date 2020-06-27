#include <iostream>
using namespace std;

int main()
{

	int a[]={5,3,1,2,4};
	int n = sizeof(a)/sizeof(int);
	//selectio sort

	for(int i=0;i<n-1;i++){
		//aage search kra h ki small to ahi h		
		int assumption = i;
		int min_index = i;
		for(int j= i+1;j<n;j++){
			if(a[j]<a[min_index]){
				min_index = j;
			}
		}

		// int t=a[assumption];
		// a[assumption]=a[min_index];
		// a[min_index]=t;
		swap(a[min_index],a[assumption]);

	}


	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	





	return 0;
}
