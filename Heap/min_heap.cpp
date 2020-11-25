
#include<bits/stdc++.h>
using namespace std;


class Minheap{
public:
	vector<int> v;

	Minheap(){
		v.push_back(-1);
	}

	void push(int x){
        v.push_back(x);

        //restore heap property
        int li = v.size() - 1;
        int pi = li/2;

        while(li > 1 && v[li] < v[pi]){
           swap(v[li],v[pi]);
           li = pi;
           pi = pi/2;
        }

	}

   void heapify(int index){
   int parent = index;
   int left_child_index = 2*parent;
   int right_child_index = 2*parent +1;

   if(left_child_index< v.size() && v[parent] > v[left_child_index]){  //child should be part of index
   	parent = left_child_index;
   }
   if(right_child_index < v.size() && v[parent] > v[right_child_index]){  //child should be part of index
   	parent = right_child_index;
   }

   if(index != parent){ // base case
     swap(v[index], v[parent]);
     heapify(parent);

    }
  }

	void pop(){ //O(log N)
       swap(v[1],v[v.size()-1]);

       v.pop_back();

       heapify(1); // passing index of starting beacuse heapify starts from first
	}

	int size(){
       return v.size()-1; // ignore -1 at first position
	}
    
    int top_element(){
       return v[1];
    }
	bool empty(){
       return v.size() == 1;
	}
     

};
void print(Minheap h){

     	while(!h.empty()){
     		cout << h.top_element()<<" ";
     		h.pop();
     	}
     }

int main()
{
	Minheap h;
	h.push(1);
	h.push(2);
	h.push(3);
	h.push(17);
	h.push(19);
	h.push(36);
	h.push(7);
	h.push(25);
	h.push(100);

	cout << h.top_element()<<"\n";
	cout << h.size()<<"\n";
	print(h);  // print always sorted (heap sort) - time commplexity O(N logN)
	
	return 0;
}
