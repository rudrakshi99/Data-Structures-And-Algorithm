#include <iostream>
using namespace std;

bool isOdd(int n){
	return (n&1);
}

int getBit(int n, int i){
	int mask = (1<<i);
	int bit = (n & mask)>0? 1:0;
	return bit;
}

int setBit(int n, int i){
	int mask = (1<<i);
	int ans = n|mask;
	return ans;
}
int clearBit(int n,int i){
	int mask = ~(1<<i);
	n = n & mask;
	return n;
}
int updateBit(int n, int i,int v){
	int mask = ~(1<<i);
	int cleared_n = n & mask;
	n = cleared_n | (v<<i);
	return n;
}
int clearLastBits(int n, int i){
	int mask = (-1 << i);
	return n & mask;
}
int clearRangeItoJ(int n, int i,int j){
	int ones = (~0);
	int a = ones << (j+1);
	int b = (1<<i) - 1;
	int mask = a|b;
	int ans = n & mask;
	return ans;
}
int main()
{
	int n = 5;
	int i = 2;
	cout<<isOdd(n)<<"\n";
	cout<<getBit(n,i)<<"\n";
	cout<<setBit(n,i)<<"\n";
	cout<<clearBit(n,i)<<"\n";
	cout<<updateBit(n,2,1)<<"\n"; // update the 2nd bit by 1
	n = 15;
	i = 3;
	 int j;
	cout<<clearLastBits(n,i)<<"\n";
    n = 31;
    i=1, j=3;
    cout<<clearRangeItoJ(n,i,j)<<"\n";
	
	return 0;
}