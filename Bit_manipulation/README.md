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
