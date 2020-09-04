#include <iostream>
using namespace std;

// 6 bitwise operators in c++
	    Precedence    Operator    Associativity
            1 	         ~         Right to left
            2  	       <<, >>      Left to Right
	        3	          & 	   Left to Right
	        4		      ^	       Left to Right
	        5		      |        Left to Right
 


// Properties of XOR operator (Very Important) 
	1. A ^ A = 0
    eg: 5 = 101
	    5 = 101
	    --------
            000
	    --------
	
	2. A ^ 0 = A
	eg: 5 = 101  //(For simplicity considering only last 3 bits)
	    0 = 000
	    --------
		    101
	    --------

	3. A ^ B = B ^ A     // Commutative
	4. (A ^ B ) ^ C = A ^ (B ^ C)   // Associative
	
	// Not Operator (~)
	Reverses all the bits

	eg: 5: 00000000000000000000000000000101
	   ~5: 11111111111111111111111111111010

	Left most bit is the sign bit: 1 for negative numbers
				                   0 for positive numbers   

	Internally -ve numbers store in 2s complement form
	
	// Left shift operator (<<)
	Same as multiplication num by 2^k

	eg: 5: 00000000000000000000000000000101
	 5<<1: 00000000000000000000000000001010 = 10 = 5*2  
	 5<<2: 00000000000000000000000000010100 = 20 = 5*(2^2)  
 
	// Right shift operator (>>)
	Same as divide num by 2^k

	eg: 5: 00000000000000000000000000000101
	 5>>1: 00000000000000000000000000000010 = 2 = 5/2
	 5>>2: 00000000000000000000000000000001 = 1 = 5/(2*2)

bool isOdd(int n){
	return (n&1);
}
bool isOdd(int n){
	return (n&1^1);
}
bool isPoweroftwo(int n){
	return (!(n&(n-1)));
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
// Most important in-built methods

	1. __builtin_popcount(num) // The number of set bits
	2. __builtin_parity(num) // The parity(even or odd) of the number of ones 
	3. __builtin_clz(num) // Number of zeroes at the beginning of a number
	4. __builtin_ctz(num) // Number of zeroes at the end of a number

	eg: 10: 00000000000000000000000000001010
	__builtin_popcount(10): 2
	__builtin_parity(10):   0 
	__builtin_clz(10):     28
	__builtin_ctz(10):      1

	// All these methods are also present for long long type
	// Append ll to all the methods
	1. __builtin_popcountll(num) 
	2. __builtin_parityll(num) 
	3. __builtin_clzll(num) 
	4. __builtin_ctzll(num) 


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