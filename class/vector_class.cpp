#include <iostream>
using namespace std;


class Vector{


public:
	//data member

	int *a;
	int curr_size;
	int capacity;


	Vector(int x = 1){
		curr_size = 0;
		capacity = x;

		a = new int[capacity];
	}

	void Push_back(int y){

		if(curr_size == capacity){
			capacity = 2*capacity;
			int *oldptr = a;
			a = new int[capacity];

			//copy
			for(int i=0;i<curr_size;i++){
				a[i]=oldptr[i];
			}

			delete []oldptr;
		}

		a[curr_size]=y;
		curr_size++;

	}

	void Pop_back(){
		if(curr_size>0){
			curr_size--;
		}
	}

	int size(){
		return curr_size;
	}

	int Capacity(){
		return capacity;
	}

	bool is_empty(){
		return curr_size == 0;
	}

	int front(){
		return a[0];
	}

};
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	Vector v;
	cout<<v.size()<<" "<<v.Capacity()<<endl;

	for(int i=1;i<=5;i++){
		v.Push_back(i);
	}
	cout<<v.size()<<" "<<v.Capacity()<<endl;
	cout<<v.front()<<endl;
	


	return 0;
}