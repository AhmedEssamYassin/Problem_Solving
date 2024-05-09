#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
/*
Notes and problems on XOR:
--------------------------
A ^ B ^ C ^ D = E	For any bit in E with 1, there MUST be ODD number of 1's
X ^ 0 = X
X ^ X = 0
That means,
1. X ^ X ^ X ^ X .... ODD number of times = X
2. X ^ X ^ X ^ X ... EVEN number of times = 0
3. (A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E
4. XOR is cumulative and associative.
5. (X ^ Y) < 0 iff X and Y have opposite signs
----------------------------------------------
Problem 1:
https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/E
Given two numbers, your task is to swap those two numbers
Solution:
---------
Since X ^ X ^ X ^ X ... EVEN number of times = 0, and X ^ X ^ X ^ X .... ODD number of times = X
i.e.,
(X ^ Y ^ Y) = X
(X ^ Y ^ X) = Y
NOTE:
It fails if (X == Y)
*/
void Swap(ll &X, ll &Y)
{
	if (X != Y)
	{
		X = X ^ Y; // assigned (X ^ Y) to X
		Y = X ^ Y; // assigned ((X ^ Y) ^ Y) = X to Y
		X = X ^ Y; // assigned ((X ^ Y) ^ X) = Y to X
	}
}

/*
Problem 2:
https://leetcode.com/problems/single-number/
Given a set of numbers where all elements occur an EVEN number of times except one number, find the ODD occurring number
Solution:
---------
Since X ^ X ^ X ^ X ... EVEN number of times = 0, and X ^ X ^ X ^ X .... ODD number of times = X
That means, doing XOR to all numbers will cause all EVEN-occurring numbers to vanish and ONLY keep the ODD-occurring number
*/
ll Find_The_ODD_Occurring_Number(vector<ll> &V)
{
	ll res{};
	for (int i{}; i < V.size(); i++)
		res ^= V[i];
	return res;
}
/*
Problem 3:
https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
https://codeforces.com/gym/101915/problem/F

Given an array of size (N-1) with integers in the range of [1, N], your task is to find the missing number from the first N integers.
Note: There are no duplicates in the list.

Solution:
---------
1. Using summation of the first N natural numbers : N*(N + 1)/2
The subtraction of N*(N + 1)/2 - Sum_Of_array = The missing number
Example:
arr[5] = {1, 3, 4, 5, 6}
6*(6 + 1)/2 - (1 + 3 + 4 + 5 + 6) = 2 which is the missing number

2. Using XOR operator:
Assume that:
(A ^ B ^ C ^ D ^ E) = X
(A ^ B ^ C ^ D) = Y
(X ^ Y) = E
i.e., ((1 ^ 2 ^ 3 ^ 4 ... ^ N) ^ (arr[0] ^ arr[1] ^ arr[2] ^ ... ^ arr[N-2])) = The missing number
*/
int Find_The_Missing_Number(vector<int> &arr)
{
	ll N = arr.size() + 1; // Its size is (N-1)
	/*
	ll sum{};
	for (int i{}; i < arr.size(); i++)
		sum += arr[i];
	return (N * (N + 1) / 2 - sum);
	*/
	int A{}, B{};
	for (int i{1}; i <= N; i++)
		A ^= i;
	for (int i{}; i < arr.size(); i++)
		B ^= arr[i];
	return (A ^ B);
}
/*
Problem 4:
https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
https://leetcode.com/problems/single-number-iii/

different problem statements:

1. Given an array in which all numbers are repeated twice except for two elements are repeated once.
(i.e. we have 2n+2 numbers and n numbers are occurring twice and the remaining two have occurred ONLY once). Find those two numbers in the most efficient way.

2. Given an integer array, in which exactly two elements appear ONLY once and all the other elements appear exactly twice.
Find the two elements that appear only once. You can return the answer in any order

3. Find the two numbers with odd occurrences in an unsorted array

Solution:
---------
Let X and Y be the two NON-repeating elements we are looking for
First, calculate the XOR of all the array elements. let's Call it XOR_Of_All_elements
All the bits that are set (which are 1's) in XOR_Of_All_elements MUST be set in ONLY one of the two NON-repeating elements (X or Y).
- Because if it was set in both of them, their XOR will evaluate to 0 (and basically ALL other numbers appear twice so their XOR will evaluate to 0 at this bit)
So if we take any set bit of XOR_Of_All_elements and divide elements in two sets, One set of elements with the same bit set and another set with the same bit unset.
- Since we can easily get the rightmost set bit, let us use it.
rightmost_set_bit_number = XOR_Of_All_elements & ~(XOR_Of_All_elements - 1)
or simply:
rightmost_set_bit_number = XOR_Of_All_elements & (-XOR_Of_All_elements)

By doing so, we will get X in one set and Y in the other set.
Now if we do XOR of all the elements in the first set, we will get one of the two NON-repeating elements
and by doing same in the other set we will get the other NON-repeating element.

ALL numbers with this rightmost bit set (1) will be XORed together
(If they happen to be of the twice-repeating numbers they will cancel each other and ONLY one of the two once-repeating numbers will remain)

ALL numbers with this rightmost bit cleared (0) will be XORed together
(If they happen to be of the twice-repeating numbers they will cancel each other and ONLY the other once-repeating number will remain)
*/
pair<ll, ll> Find_2_Non_Repeating_elements(vector<ll> &V)
{
	ll XOR_Of_All_elements{};
	for (int i{}; i < V.size(); i++)
		XOR_Of_All_elements ^= V[i];

	ll rightmost_set_bit_number = XOR_Of_All_elements & ~(XOR_Of_All_elements - 1); // N & (-N) gets the rightmost set bit
	ll X{}, Y{};
	for (int i{}; i < V.size(); i++)
	{
		if (rightmost_set_bit_number & V[i]) // if It's 1
			X ^= V[i];
		else
			Y ^= V[i];
	}
	return {X, Y};
}
/*
Problem 5:
https://practice.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once.

Solution:
---------
The solution is NOT easy like other XOR-based solutions, because all elements appear an odd number of times here (three times).
Run a loop for all elements in the array. At the end of every iteration, maintain the following two values.
ones: The bits that have appeared 1st time or 4th time or 7th time ... etc.
twos: The bits that have appeared 2nd time or 5th time or 8th time ... etc.
Finally, we return the value of ‘ones’
How to maintain the values of ‘ones’ and ‘twos’?
- ‘ones’ and ‘twos’ are initialized as 0
- For every new element in the array, find out the common set bits (1's) in the new element and the previous value of ‘ones’.
These common set bits (1's) are actually the bits that should be added to ‘twos’.
So do bitwise XOR of the common set bits with ‘twos’. ‘twos’ also gets some extra bits that appear the third time. These extra bits are removed later.
Update ‘ones’ by doing XOR of new element with the previous value of ‘ones’. There may be some bits that appear 3rd time. These extra bits are also removed later.
Both ‘ones’ and ‘twos’ contain those extra bits which appear 3rd time. Remove these extra bits by finding out common set bits in ‘ones’ and ‘twos’.

Another approach is to Add each number once and multiply the sum by 3, we will get thrice the sum of each element of the array.
- Store it as thrice_sum.
- Subtract the sum of the whole array from the thrice_sum and divide the result by 2
- The number we get is the required number (which appears once in the array).
Example:
Array [] : [a, a, a, b, b, b, c, c, c, d]
Mathematical Equation = ( 3*(a + b + c + d) – (a + a + a + b + b + b + c + c + c + d) ) / 2 = (2 * d) / 2 = d which is the once-occurring number
In more simple words: ( 3*(sum_of_array_without_duplicates) – (sum_of_array) ) / 2

Using a map to count occurrences of each number

Using STL count()
*/
ll Find_element_appearing_once(vector<ll> &V)
{
	ll ones{}, twos{};

	ll common_bit_mask;

	for (int i = 0; i < V.size(); i++)
	{

		/* The expression "one & arr[i]" gives the bits that
		are there in both 'ones' and new element from arr[].
		We add these bits to 'twos' using bitwise OR

		Value of 'twos' will be set as 0, 3, 3 and 1 after
		1st, 2nd, 3rd and 4th iterations respectively */
		twos = twos | (ones & V[i]);

		/* XOR the new bits with previous 'ones' to get all
		bits appearing odd number of times

		Value of 'ones' will be set as 3, 0, 2 and 3 after
		1st, 2nd, 3rd and 4th iterations respectively */
		ones = ones ^ V[i];

		/* The common bits are those bits which appear third
		time So these bits should not be there in both
		'ones' and 'twos'. common_bit_mask contains all
		these bits as 0, so that the bits can be removed
		from 'ones' and 'twos'

		Value of 'common_bit_mask' will be set as 00, 00, 01
		and 10 after 1st, 2nd, 3rd and 4th iterations
		respectively */
		common_bit_mask = ~(ones & twos);

		/* Remove common bits (the bits that appear third
		time) from 'ones'

		Value of 'ones' will be set as 3, 0, 0 and 2 after
		1st, 2nd, 3rd and 4th iterations respectively */
		ones &= common_bit_mask;

		/* Remove common bits (the bits that appear third
		time) from 'twos'

		Value of 'twos' will be set as 0, 3, 1 and 0 after
		1st, 2nd, 3rd and 4th iterations respectively */
		twos &= common_bit_mask;

		// uncomment this code to see intermediate values
		// printf (" %d %d n", ones, twos);
	}

	return ones;
}
/*
Problem 6:
https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

Count number of bits to be flipped to convert A to B

Solution:
---------
Calculate (A XOR B)
Since (0 XOR 1) = 1 and (1 XOR 0) = 1
while (0 XOR 0) = 0 and (1 XOR 1) = 0
So calculating the number of set bits (1's) in (A XOR B) will give us the number of mis-matching bits in A and B, which needs to be flipped
*/
int Number_of_bits_to_flip(ll A, ll B) // Counts different bits between to bitmasks
{
	return __builtin_popcount(A ^ B);
}

/*
Problem 7:
Given a range [L, R], Find two integers in this range such that their XOR is maximum among all possible choices of two integers.
More Formally, given [L, R], find max (A ^ B) where L <= A, B <= R

Solution:
---------
An efficient solution is to consider pattern of binary values from L to R.
We can see that first bit from L to R either changes from 0 to 1 or it stays 1
i.e., if we take the XOR of any two numbers for maximum value their first bit will be fixed which will be same as first bit of XOR of L and R itself.
After observing the technique to get first bit, we can see that if we XOR L and R, the most significant bit of this XOR will tell us the maximum value we can achieve
i.e. let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get is 1111 because from L to R we have all possible combinations of xxx
and it is always possible to choose these bits in such a way from two numbers such that their XOR becomes all 1
*/
ll Get_The_MSB_No(ll N)
{
	// MSB = No. of bits - No. of leading zeros
	int No_Of_Leading_Zeros = __builtin_clz(N);
	return (1 << (63 - No_Of_Leading_Zeros));
}

ll Find_a_Pair_With_Max_XOR(ll L, ll R)
{
	unsigned ll XOR = (L ^ R);
	int cnt = __builtin_clz(XOR);
	return (1 << (31 - cnt)) - 1;
}

/*
https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/A
https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/D

*/

/*
// The Least Significant Bit (LSB) shows the Parity of a number
X = 11010 = 26
X = 11011 = 27

X % 2 = X & 1 = LSB

Generally:	X % (2^N)  = X & ((1 << n) - 1)

ODDity test:

if(N%2 == 1)	// Fails if N is negative

if( (N&1) == 1)	// Always works

Checking if two numbers are of the same parity:
-----------------------------------------------
If a number is ODD, its LSB = 1, whereas if a number is EVEN, its LSB = 0
For two numbers X and Y, to be of the same parity, they should be both EVEN or both ODD
i.e., The LSB should be 0 or 1 in both numbers
For example:
xxxxxxx0 and xxxxxxx0 are of the same parity
xxxxxxx1 and xxxxxxx1 are also of the same parity
while the two numbers xxxxxxx1 and xxxxxxx0 or the two numbers xxxxxxx0 and xxxxxxx1 are NOT

i.e., Both numbers, X and Y, should have the same LSB, which will make the LSB of (X ^ Y) always be 0
*/
bool Check_if_same_parity(ll X, ll Y)
{
	return (((X ^ Y) & 1) == 0);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	return 0;
}