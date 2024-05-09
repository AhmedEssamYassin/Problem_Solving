#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Sometimes, it is low-level optimization, so it's a better time order
- Although, ALL modern compilers perform this kind of optimization on all arithmetic operations automatically!

Sometimes, it drops memory by factor of 8, so it's a better memory order
For example, A boolean array of 1000'000'000 values will be 1 GB while a bitset of 1000'000'000 will be ONLY 128 MB !

Sometimes, it makes the code shorter and cleaner
- and other times it can make some expressions a little complicated, though sophisticated, and NOT intuitive unlike arithmetic operations

https://graphics.stanford.edu/~seander/bithacks.html#ParityNaive

In any bitset or bitmask, a bit which is 1 is called a "set" bit, while a bit which is 0 is called an "unset" or "cleared" bit

Logical operators:
------------------
&& (logical AND) : returns true (1) iff both operands are true. Otherwise, it returns false (0).
Example: (1 && 1) = 1    (0 && 1) = 0    (1 && 0) = 0    (0 && 0) = 0

|| (logical OR): returns false (0) iff both operands are false. Otherwise, it returns true (1).
Example: (1 && 1) = 1    (0 && 1) = 1    (1 && 0) = 1    (0 && 0) = 0

! (logical NOT): returns true (1) if the operand is false (0) and returns false (0) if the operand is true (1)
Example: !(0) = 1    !(1) = 0

Any NON-zero value is considered true (1) and ONLY the zero is false (0)
-------------------------------------------------------------------------------------------------------------------------------------------------
Bitwise Operators:
------------------
& (bitwise AND) : Takes 2 numbers and does && on every two corresponding bits of these 2 numbers
Example:
(143 & 23) = 7
10001111
&
00010111
=
00000111 = 7
-------------------------------------+-------------------------------------+-------------------------------------
| (bitwise OR) : Takes 2 numbers and does || on every two corresponding bits of these 2 numbers
Example:
(143 | 23) = 159
10001111
|
00010111
=
10011111 = 159
-------------------------------------+-------------------------------------+-------------------------------------
~ (bitwise NOT) : Takes 1 number and does ! on every bit of this number (the toggled bits are in two's complement representation)
Example:
~N = -1*(N + 1)
~7 = ~(0111) = (1000) = -8
To know the actual value of the toggled bits you should convert from two's complement to decimal representation:

1. Know the sign
Negative if the MSB is 1
Positive if the MSB is 0

2. Get the one's complement (toggle all bits again)

3. add 1 to the number

Example:
~7 = ~(0111) = (1000)
1. It's Negative because the MSB is 1
2. Its one's complement is (0111)
3. add (0001) to (0111) you get (1000) which is 8
apply the sign you get the answer which is -8
-------------------------------------+-------------------------------------+-------------------------------------
^ (bitwise XOR) : Takes 2 numbers and does XOR on every two corresponding bits of these 2 numbers
Example:
(143 ^ 23) = 152
10001111
^
00010111
=
10011000 = 152
-------------------------------------+-------------------------------------+-------------------------------------
<< (left-shift) : Takes 2 numbers, left shifts the bits of the first operand, and the second operand decides the number of places to shift
(X << Y) is equivalent to multiplying X by pow(2, Y)
Example:
(1 << 5) = 100000 = 32 (1 * pow(2, 5) = 1*32 = 32)
(5 << 3) = shifts (101) three places to the left = 101000 = 40 (5 * pow(2, 3) = 5*8 = 40)
-------------------------------------+-------------------------------------+-------------------------------------
>> (right-shift) : Takes 2 numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift
(X >> Y) is equivalent to dividing X by pow(2, Y)
Example:
(1 >> 5) = 00000 = 0 (1 / pow(2, 5) = 1/32 = 0)
(5 >> 3) = shifts (101) three places to the right = 000 = 0 (5 / pow(2, 3) = 5/8 = 0)
(40 >> 3) = shifts (101000) three places to the right = 101 = 5 (40 / pow(2, 3) = 40/8 = 5)
-------------------------------------+-------------------------------------+-------------------------------------
More Examples:
X = 1152 = 	10010000000
Y = 1428 = 	10110010100

X & Y 	 = 	10010000000
X | Y 	 = 	10110010100
X ^ Y 	 = 	00100010100
X >> 1	 = 	1001000000 			Equivalent to X/2
X >> 2	 = 	100100000 			Equivalent to X/4
X << 1	 =  100100000000		Equivalent to X*2
X << 2	 =  1001000000000		Equivalent to X*4
-------------------------------------------------------------------------------------------------------------------------------------------------
Precedence of bitwise operators:
--------------------------------
1. ( )
2. ~
3. << >>
4. &
5. ^
6. |
7. =
8. <<= >>=
9. &= ^= |=
10. , (comma operator)

Be careful with operators precedence problems
X & 7 == 1 		is interpreted as 			X & (7 == 1)	instead do: (X & 7) == 1
1<<10 - 1 		is interpreted as			1 << 9			instead do: (1<<10) - 1

Be careful NOT to overflow:
1 << 60 Fails. 1 is 32-bit integer		instead do:	1LL << 60
-------------------------------------------------------------------------------------------------------------------------------------------------
Some useful calculations on bits:
---------------------------------
(1 << i) is a number with ONLY the i-th bit set

~(i << i) is a number with all bits set and ONLY the i-th bit cleared

(N - 1) flips all bits after the rightmost set bit of N, including the rightmost set bit
Assume N = 00110100
00110100
-
00000001
=
00110011
Explanation:
(0 - 1) is NOT possible, so we should borrow a 1, which is the rightmost set bit, here it's 4 so it flips to 0 and 4 - 1 is 3 which is 11 in binary
and all other bits will be either (1 - 0) or (0 - 0) so they remain without any change

(N + 1) flips all bits after the rightmost cleared bit of N, including the rightmost cleared bit
Assume N = 0011011111
001101011111
+
000000000001
=
001101100000
Explanation:
(1 + 1) is 2 which is in binary 10 i.e., 0 with a carry = 1.
This carry will still give (10) base 2, if added with any set bit and ONLY gives 1 when added with a cleared bit (which will be the rightmost cleared bit)
and all other bits will be either (1 + 0) or (0 + 0) so they remain without any change

1. set the i-th bit of the number N: (N | (1 << i))
2. flip the i-th bit of the number N: (N ^ (1 << i))
3. clear the i-th bit of the number N: (N & ~(1 << i))
4. check if the i-th bit is set: bool(N & (1 << i))
5. clear the rightmost set bit: (N & (N - 1))
6. Brian Kernighan's algorithm: A way to count set bits using the previous fact
it simply clears the rightmost set bit and counts it iteratively until the number is 0
7. count cleared bits: count set bits in (N ^ 0b11111111)
8. clear ALL trailing 1's: (N & (N + 1))
9. set the last cleared bit: (N | (N + 1))
10. get the rightmost set bit: (N & (-N)) or (N & ~(N - 1))
11. Clear all bits from LSB to ith bit:         mask = ~((1 << i+1 ) - 1); x &= mask;
12. Clearing all bits from MSB to i-th bit:     mask = (1 << i) - 1; x &= mask;
*/

// Bits indices are traversed from right to left, i.e., the bit at index 0 is the rightmost bit (LSB)

template <typename T>
void Set_ith_bit(T &N, uint16_t i) // 0-based
{
    // 11100101(0)11 | 00000000(1)00 = 11100101(1)11
    N = (N | (T(1) << i));
}

template <typename T>
void Flip_ith_bit(T &N, uint16_t i) // 0-based
{
    // 111001010(1)1 ^ 000000000(1)0 = 111001010(0)1
    N = (N ^ (T(1) << i));
}

template <typename T>
void Clear_ith_bit(T &N, uint16_t i) // 0-based
{
    // 1110010(1)011 & 1111111(0)111 = 1110010(0)011
    N = (N & ~(T(1) << i));
}

template <typename T>
bool Check_ith_bit_set(T &N, uint16_t i) // 0-based
{
    // 11100101(0)11 & 00000000(1)00 = 00000000000 (it's a cleared bit)
    return (N & (T(1) << i));
    // return ((N >> i) & 1) == 1; // 110100, i = 4  -->  110 & 1 = 0
}

template <typename T>
void Clear_rightmost_set_bit(T &N)
{
    // 11100101(1)00 & 11100101(0)11 = 11100101(0)00
    N = (N & (N - 1));
}

template <typename T>
int Count_set_bits(T N)
{
    int cnt{};

    while (N)
    {
        Clear_rightmost_set_bit(N);
        cnt++;
    }
    return cnt;
}

template <typename T>
int Count_cleared_bits(T N)
{
    int MSB = 31 - __builtin_clz(N); // For signed integers
    return __builtin_popcount(N ^ ((T(1) << ++MSB) - 1));
}

template <typename T>
void Clear_all_trailing_ones(T &N)
{
    // 111001010(11) & 111001011(00) = 111001010(00)
    N = (N & (N + 1));
}

template <typename T>
void Set_last_cleared_bit(T &N)
{
    // 11100101(0)11 | 11100101(1)00 = 11100101(1)11
    N = (N | (N + 1));
}

template <typename T>
int Get_rightmost_set_bit_number(const T &N)
{
    // 11100101(1)00 & ~(11100101(0)11) = 11100101(1)00 & 00011010(1)00 = 00000000(1)00
    return (N & ~(N - 1));
    // return (N & (-N));
    // return log2(N & (N - 1)) + 1; // gives the index of the rightmost_set_bit (0-indexed)
}

/*
Count numbers up to (N) having the Kth bit set
--------------------------------------------------
1. Right-shift N, K+1 times followed by left-shifting the result K times
   which gives the count of numbers satisfying the given condition till the nearest Power_of_2 less than N

2. Now, check if the Kth bit is set in N or NOT

3. If the Kth bit is set in N, then add the count of numbers from the nearest Power_of_2 less than N to the answer
   Then add 1 to count N itself

Let's figure out why this method works!
consider a range of numbers until N = 22 and we want to count how many number with bit K = 2 set
0000
0001
0010
0011
0100 ✓
0101 ✓
0110 ✓
0111 ✓
1000
1001
1010
1011
1100 ✓
1101 ✓
1110 ✓
1111 ✓
10000
10001
10010
10011
10100 ✓
10101 ✓
10110 ✓
.
.
.

We can observe that starting from 2² we have 2² numbers with Kth = 2 bit set and 2² NOT and this pattern keeps repeating
That means we need to know how many 2² are in N which is easily calculated using integer division res = (N / 2²)
but NOT ALL 2²'s are satisfying the condition, ONLY half of them, so we need to further divide by 2 (res / 2)
Now, res value is number of groups of numbers with Kth = 2 bit set, each group is 2²
That means total count of numbers with Kth = 2 bit set is res *= 2²
That totally reasons the first step in the algorithm:
res = (N >> (K + 1)) << K
which is equivalent to (N / 2^K / 2) * 2^K

What about an incomplete group of 2^K?
In our example, 22/2²/2 = 2 because integer division ONLY counts complete 2^K's existing in N
so we did NOT count the last group of 2²!
Now we need to check if this group satisfies our condition and if so, we add it the result

If the Kth bit is set in N itself, that means we are in a valid group
then add (N & ((1 << K) - 1))
10110
&
00011

Then add 1 to count N itself
*/

template <typename T>
int Count_Kth_set_bit(const T &N, const int &K)
{
    int res = (N >> (K + 1)) << K;

    if (N & (T(1) << K))
        res += (N & ((T(1) << K) - 1)) + 1; // Adds 1 to count N itself

    return res;
}

/*
Check if a number is divisible by 2^K
A number N is divisible by 2^K iff (N % 2^K) == 0
That means, if we subtract ALL bits having 2^K, all remaining bits will be cleared
So, if the count of trailing zeros is greater than or equal to K, that means N is divisible by 2^K

It's also a way to count the  number of times a number N can be divided by 2
*/

template <typename T>
bool Is_Divisible(const T &N, const int &K)
{
    int Val = __builtin_ctz(N); // Number of times a number N can be divided by 2
    return (Val >= K);
}

/*
C++ supports some of those operations since C++20 via the <bit> standard library:

has_single_bit (unsigned_integral)
checks if the number is a power of two (has ONLY one set bit)

bit_ceil (unsigned_integral)
round up to the next power of two (e.g., rounds 7 to 8)

bit_floor (unsigned_integral)
round down to the previous power of two (e.g., rounds 7 to 4)

bit_width (unsigned_integral)
finds the smallest number of bits needed to represent the given value (returns 0 if the number is 0)

rotl (N, S)
Computes the result of bitwise left-rotating the value of N by S positions.
This operation is also known as a left circular shift.

rotr (N, S)
Computes the result of bitwise right-rotating the value of N by S positions.
This operation is also known as a right circular shift.

countl_zero (unsigned_integral)
counts the number of consecutive 0 bits, starting from the most significant bit (Leading zeros)

countr_zero (unsigned_integral)
counts the number of consecutive 0 bits, starting from the least significant bit (Trailing zeros)

countl_one (unsigned_integral)
counts the number of consecutive 1 bits, starting from the most significant bit (Leading ones)

countr_one (unsigned_integral)
counts the number of consecutive 1 bits, starting from the least significant bit (Trailing ones)

popcount (unsigned_integral)
count the number of set bits

Additionally, there are also predefined functions in some compilers that help working with bits.
E.g. GCC defines a list at Built-in Functions Provided by GCC that also work in older versions of C++:

__builtin_popcount(unsigned int): returns the number of set bits        (__builtin_popcount(0b0001'0010'1100) == 4)
__builtin_ffs(int): finds the index of the first (rightmost) set bit    (__builtin_ffs(0b0001'0010'1100) == 3)
__builtin_clz(unsigned int): the count of leading zeros                 (__builtin_clz(0b0001'0010'1100) == 23)
__builtin_ctz(unsigned int): the count of trailing zeros                (__builtin_ctz(0b0001'0010'1100) == 2)

Note that some of the operations (both the C++20 functions and the Compiler Built-in ones) might be quite slow in GCC
That's why, Enable the specific compiler target with #pragma GCC target("popcnt").
-----------------------------------------+-----------------------------------------+-----------------------------------------
letter case changing using bitwise operators:
----------------------+----------------------
A -> 01000001          a -> 01100001
B -> 01000010          b -> 01100010
C -> 01000011          c -> 01100011
  .                      .
  .                      .
Z -> 01011010          z -> 01111010

char C;
1. Uppercase latin letter to lowercase:
As we can see if we set the 5th bit of upper case characters, it will be converted into lower case characters.
We have to prepare a mask having the 5th bit set (1) and others are cleared (0) i.e., (00100000).
This mask is the bit representation of the space character (' ').
C |= ' '; // Is like adding 32

2. Lowercase latin letter to uppercase:
As we can see if we clear the 5th bit of lower case characters, it will be converted into upper case characters.
We have to prepare a mask having the 5th bit cleared (0) and others are set (1) i.e., (11011111).
This mask is the bit representation of the underscore character ('_').
C &= '_'; //
-------------------------------------------------------------------------------------------------------------------------------------------------

/*
If N is small (N <= 31), we can generate ALL possible subsets (2^31 subsets) using a Bitmask

Assume S = {1, 2, 2}, Here, N = 3
The binary digits from 0 to 7 are

0 –> 000    –> number formed with no setbits                          –> { }
1 –> 001    –> number formed with setbit at position 0                –> { 1 }
2 –> 010    –> number formed with setbit at position 1                –> { 2 }
3 –> 011    –> number formed with setbit at position 0  and 1         –> { 1 , 2 }
4 –> 100    –> number formed with setbit at position 2                –>  { 2 }
5 –> 101    –> number formed with setbit at position 0 and 2      	  –> { 1 , 2}
6 –> 110    –> number formed with setbit at position 1 and 2          –> { 2 , 2}
7 –> 111    –> number formed with setbit at position 0 , 1 and 2      –> {1 , 2 , 2}
After removing duplicates final result will be { }, { 1 }, { 2 }, { 1 , 2 }, { 2 , 2 }, { 1 , 2 , 2}

Code:
-----
for (int Bitmask = 0; Bitmask < (1 << N); Bitmask++)
{
    for (int ith_bit = 0; ith_bit < N; ith_bit++)
    {
        if (Bitmask & (1 << ith_bit)) // If ith_bit is set
        {
            //Include it in this subset
        }
    }
    //A possible subset has been formed or traversed
}
*/

/*
void printNumber(int n, int len)
{
    if (!len)
        return;

    printNumber(n >> 1, len - 1); // remove last bit
    cout << (n & 1);              // print last bit
}

// Exercise: rotate a bit to right. 0000000000000000000011001101110 -> rotate 5 -> 0111000000000000000000000110011

// len = 3: 000, 001, 010, 011, 100, 101, 110, 111

void printAllSubsets(int len) // Remember we did it recursively! This is much SIMPLER!
{
    for (int i = 0; i < (1 << len); ++i)
        printNumber(i, len);

    // For reversed order. Either reverse each item or work from big to small
    // for (int i = (1<<len); i >= 0 ; --i)
    //	printNumber(i, len);
}

// What about trying the given mask - 1 till zero! Wrong 1s are added! Simply remove them
// 110101000 -1 = 110100111 & 110101000 = 110100000
void getAllSubMasks(int mask)
{

    for (int subMask = mask; subMask; subMask = (subMask - 1) & mask)
        printNumber(subMask, 32); // this code doesn't print 0

    // For reverse: ~subMask&mask = subMask^mask
}

// Efficiency
void intersection(int A[60], int len1, int B[60], int len2)
{
    int mask1 = 0;
    int mask2 = 0;
    for (int i = 0; i < len1; ++i)
        mask1 = setBit1(mask1, A[i]);

    for (int i = 0; i < len2; ++i)
        mask2 = setBit1(mask2, B[i]);

    int inter = mask1 & mask2; // In O(1) noes intersection

    for (int i = 0; i < max(len1, len2); ++i)
    {
        if (getBit(inter, i))
            cout << i << " ";
    }
    cout << "\n";
}

// In small graphs, E.g. nodes < 64, we could maintain graph node neighbors in a mask

// Better Memory
// Say you have numbers in range 100 Million, and you want to know if some number visited before or NOT
// Simply: bool vis[100 * 1000 * 1000];	// and mark in it.

// But 100 Million is too much! What about 100 Million / 8 = 12500000	12 Million and half!
// You know that each character is 8 bits. Bool too takes 8 bits. UTILIZE byte!

const int MAX = 100000000;
char vis[MAX / 8 + 1];

void setVisited(int i)
{ // in past vis[i] = 1
    // Now each byte is responsible for 8 bits.
    // So first we need to know which char is for us. Then my byte is in i / 8
    // And then which bit with us. Any inside this byte i am is i % 8

    vis[i / 8] |= (1 << (i % 8));

    // Or more efficiently
    vis[i >> 3] |= (1 << (i & 7));
}

bool isVisited(int i)
{ // in past if(vis[i])
    return vis[i >> 3] & (1 << (i & 7));
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    return 0;
}