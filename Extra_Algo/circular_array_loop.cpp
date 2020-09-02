/*You are given an array of positive and negative integers. If a number k at an index is positive,
then move forward k steps. Conversely, if it's negative (-k), move backward k steps. Since the array is circular,
 you may assume that the last element's next element is the first element, and the first element's previous
 element is the last element.

Determine if there is a loop (or a cycle) in array. A cycle must start and end at the same index and
the cycle's length > 1. Furthermore, movements in a cycle must all follow a single direction. 
In other words, a cycle must not consist of both forward and backward movements. Print 1 if cycle present else print 0.
*/
#include <iostream>
#include <vector>
using namespace std;
int next(vector<int> a,int i){ // next index
	return (i+a[i]+a.size())%a.size();
}

bool CircularLoop(vector<int> v){
	int n = v.size();
	for(int i=0;i<n;i++){
		int slow = i, fast = i;
		if(v[i] == 0){
			continue;
		}

		while(v[slow]*v[next(v,slow)]>0 &&
			  v[fast]*v[next(v,fast)]>0 &&
			  v[fast]*v[next(v,next(v,fast))]>0){ // check for positive magnitude
			slow = next(v,slow);
			fast = next(v,next(v,fast));

			if(slow == fast){
				// That means cycle is present, but cycle length should be >1
				if(slow == next(v,slow)){
					break;
				}
				return true;
			}
		}

		slow = i;
		int val = v[slow];
		while(val*v[slow]>0){ // marking 0 to positive elements
			int x = slow;
			slow = next(v,slow);
			v[x]=0;
		}
	}
	return false;
}

int main(){
	int n;
	cin>>n;

	vector<int> v;
	for(int i=0;i<n;i++){
		int x; cin>>x;     // 2 -1 1 2 2
		v.push_back(x);  
	}
	cout<<CircularLoop(v)<<endl;  // 1

	cout<<endl;
	return 0;
}