
#include <iostream> 
#include <vector> 
using namespace std; 


void printSubArrays(int arr[], int start, int end,int n) 
{	 
	
	if (end == n) 
		return; 
	
	else if (start > end) 
		printSubArrays(arr, 0, end + 1,n); 
			
	else
	{ 
		cout << "["; 
		for (int i = start; i < end; i++){ 
			cout << arr[i] << ", "; 
		} 
		
		cout << arr[end] << "]" << endl; 
		printSubArrays(arr, start + 1, end,n); 
	} 
	
	return; 
} 

int main() 
{ 
int arr[] = {1, 2, 3}; 
printSubArrays(arr, 0, 0,3); 
return 0; 
} 
