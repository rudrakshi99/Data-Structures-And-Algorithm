//numbers in small range
//O(n)
#include<iostream>
using namespace std;

void counting_sort(int *arr, int n){
    
    int largest = -1;
    //largest in the arr
    for(int i=0;i<n;i++){
        largest = max(largest, arr[i]);
    }

    // create a frequency arr
    int *freq = new int[largest+1];

    for(int i=0; i<n;i++){
       freq[arr[i]]++;
    }

    // put the elements back into the array by reading freq arr
      int j=0;
    for(int i=0;i<=largest;i++){
        
        while(freq[i] > 0){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}
int main() {

	int arr[] = {88, 97, 10, 12, 15 ,1,5,6,12,5,8};
	int n = sizeof(arr)/ sizeof(int);
    
    counting_sort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }


   return 0;
}
