#include <iostream>
#include "mymap.h"
using namespace std;


int main()
{
	Hashmap menu;

	menu.insert("Pepsi", 50);
	menu.insert("Burger", 30);
	menu.insert("Pizza", 120);
	menu.insert("Noodles", 75);
	menu.insert("Coke", 50);
	
	menu.print();

	node* a = menu.search("Coke");
	if(a!= NULL){
		cout << a->value;
	}
	else{
		cout<<"Not found";
	}
	
	return 0;
}