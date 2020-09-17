// functional object

#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Fun{
public:
	void operator()(){ // operator overloading
      cout <<"class";
	}

};

class Person{
public:
	string name;
	int age;

	Person(){

	}
	Person(string n,int a){
       name = n;
       age = a;
    }
};

class PersonCompare{
	public:
		bool operator()(Person A, Person B){
             return A.age < B.age;
		}

};
int main(){
    
    int n;
    cin >> n;
    priority_queue< Person, vector<Person>, PersonCompare > pq;
    for(int i=0;i<n;i++){
       string name;
       int age;
       cin >>name>>age;
       Person p(name,age);
       pq.push(p);
    }
    int k = 3;
    // find top 3 elements - O( K log N)
    for(int i=0;i<k;i++){
       Person p = pq.top();
       cout<<p.name<<" "<<p.age<<endl;
       pq.pop();
    }
  return 0;
}