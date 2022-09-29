# Bit Manipulation

### 6 bitwise operators in c++

| Precedence  |   Operator  |   Associativity |
|-------------| ------------| ----------------|
|  1 	        |        ~     |   Right to left
|  2  	      |     <<, >>   |   Left to Right
|  3	        |       & 	   |  Left to Right
|  4		      |       ^	     |  Left to Right
|  5		      |       \|      |  Left to Right
 


### Properties of XOR operator 
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
	
#### Not Operator (~)
	Reverses all the bits

	eg: 5: 00000000000000000000000000000101
	   ~5: 11111111111111111111111111111010

	Left most bit is the sign bit: 1 for negative numbers
				                   0 for positive numbers   

	Internally -ve numbers store in 2s complement form
	
### Left shift operator (<<)
	Same as multiplication num by 2^k

	eg: 5: 00000000000000000000000000000101
	 5<<1: 00000000000000000000000000001010 = 10 = 5*2  
	 5<<2: 00000000000000000000000000010100 = 20 = 5*(2^2)  
 
### Right shift operator (>>)
	Same as divide num by 2^k

	eg: 5: 00000000000000000000000000000101
	 5>>1: 00000000000000000000000000000010 = 2 = 5/2
	 5>>2: 00000000000000000000000000000001 = 1 = 5/(2*2)

### Most important in-built methods
```cpp
	1. __builtin_popcount(num) // The number of set bits
	2. __builtin_parity(num) // The parity(even or odd) of the number of ones 
	3. __builtin_clz(num) // Number of zeroes at the beginning of a number
	4. __builtin_ctz(num) // Number of zeroes at the end of a number
````
	eg: 10: 00000000000000000000000000001010
	__builtin_popcount(10): 2
	__builtin_parity(10):   0 
	__builtin_clz(10):     28
	__builtin_ctz(10):      1
`````

 All these methods are also present for long long type
	
	Append ll to all the methods:
	1. __builtin_popcountll(num) 
	2. __builtin_parityll(num) 
	3. __builtin_clzll(num) 
	4. __builtin_ctzll(num) 
	
