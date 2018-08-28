#include <iostream>
#include <string>

using namespace std;

int n = 23;

void isPrime(int n)
{
    // preconditions:
    // 1. n/n=1 <-> n%n=0
    // 2. n%1 = 0
    // if I prove that n%m==0 where n!=m
    // n=6
    // 6%7 results in smallest number - 6

    if (7%7==0 && 7%1 ==0){

    }

    char result[10];
    char divisors[9] = {1,2,3,4,5,6,7,8,9};
    int i,m;
    for (m=2; i<m; i++) {
        if (n%m == 0) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {

}


/* NOTES
Sprint - write a quick program that checks to see if a number is prime, say yes/no - REVISIT

Type tells the computer to be prepared to allocate a certain amount of data
Memory Allocation - we use a binary system
Binary to Decimal, use positional system to say yes if you find a 1 at that position you don't are about that position
If you find a 1 at position 2, you raise that position (2) to the power of 2 which equals 4, so 

yes/no      0   0   0   0   0   0   0   0   
exponent    7   6   5   4   3   2   1   0
2^exp       0   0   0   0   0   0   0   0
Represents the decimal number 0   

yes/no      1   1   1   1   1   1   1   1    
exponent    7   6   5   4   3   2   1   0
2^exp       128 64  32  16  8   4   2   1
Represents the decimal number 256

yes/no      0   0   0   1   0   0   0   0    
exponent    7   6   5   4   3   2   1   0
2^exp       0   0   0   16  0   0   0   0
Represents the decimal number 16

yes/no      0   0   0   0   0   1   0   1    
exponent    7   6   5   4   3   2   1   0
2^exp       0   0   0   0   0   4   0   1
Represents the decimal number 5

Type    VAR     VAL
int     myInt   5
int     myInt   5x10^6

How do we know that 5,000,000 can fit in our variable definition of an integer?
Int can hold 32 bits = 2^33-1 at most

yes/no      1    1    1    ... ...  1   1   1
exponent    31   30   29   ... ...  2   1   0
2^exp       2^31 2^30 2^29 ... ...  0   0   0
Represents the LARGEST decimal number for 32 bits

Fixed bits create a safe environment
    Create a used allocation of space - stack
    Dynamic data generated in runtime - heap
Amount of bit used known before run time
Scoped to the module
Risk of wasting space or coming too short

Pointers point to where the real variable we need to use is located, they store an
address
*, &, type *var

int myInt = 5;
cout<<myInt<<endl;

int *myIntPtr = myInt;
cout<<*myIntPtr<<endl;  
These two lines are the same thing, but... this line will print out the memory address not the value

To initialize my pointer, I must write...
int *myIntPtr = &myInt
where &myInt tells the pointer where the value of &myInt is stored
This is BEST practice

Memory spots are represented in hexadecimal format (base 16)
0...9 and A...F, 16 digits
convenient b/c 16 is a power of 2!
We cannot store the entire address in a bit, because an x needs to be stored in 4 bits - check the book

Sometimes if the HEX numbers are preceeded by all 0's they are truncated and we may be left with a number
such as 0xFF02, where the full representation is 0X0000FF01
H   D   B
F   15  1111

QUIZ 2 = ZIUQ2


*/