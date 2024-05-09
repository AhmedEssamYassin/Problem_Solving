#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
#define endl "\n"

vector<int> Prime, LPF(1000001);
int Div_Count[1000001];
void Linear_Sieve_Of_Eratosthenes(int N)
{
	vector<bool> Is_Prime(N + 1, true); // Initially Assuming all numbers to be primes
	// LPF.resize(N + 1);
	LPF[1] = 1;
	Is_Prime[0] = Is_Prime[1] = 0; // 0 and 1 are NOT primes
	for (int i{2}; i <= N; i++)
	{
		if (Is_Prime[i])
		{
			Prime.push_back(i);
			LPF[i] = i; // The least prime factor of a prime number is itself
		}
		for (int j{}; j < (int)Prime.size() and i * Prime[j] <= N and Prime[j] <= LPF[i]; j++)
		{
			Is_Prime[i * Prime[j]] = 0; // Crossing out all the multiples of prime numbers
			LPF[i * Prime[j]] = Prime[j];
		}
	}
}
/*
Implementing a function for Modular multiplication causes OVERHEAD and is TOO SLOW compared to the regular arithmetic expression
But Modular multiplication Even when using the property (A * B) % mod = ((A % mod) *(B % mod)) % mod Can cause intermediate OVERFLOW
(A % mod) < mod
(B % mod) < mod
But their multiplication is very likely to be greater than mod and may be greater than the capacity of the whole type causing an OVERFLOW
Solutions to this problem:

1. Modular Binary Multiplication

2. Multiplication via wider type (__int128_t is enough for multiplying 64-bit integers)
To multiply two 32-bit numbers, you need a 64-bit intermediate variable.
And to multiply two 64-bit numbers, you need a 128-bit variable!
Modern 64-bit C++ compilers (except perhaps Microsoft® Visual C++®) have a special type __int128, which allows performing operations on 128-bit numbers.
*/

template <typename T>
T mult64(T a, T b, T mod)
{
	return (__int128_t)a * b % mod;
}

template <typename T>
T mult128(T a, T b, T mod)
{
	int largestBit = 127 - __countl_zero(b); // Position of MSB
	// int largestBit{};
	// while ((b >> largestBit))
	//   largestBit++;

	T result = 0;
	for (int currentBit = largestBit - 1; currentBit >= 0; currentBit--)
	{
		result = (result + result); // result *= 2;

		if (result >= mod)
			result -= mod; // result %= mod;

		// check whether current bit is set in b
		if ((b >> currentBit) & 1)
		{
			result += a;
			if (result >= mod)
				result -= mod; // result %= mod;
		}
	}
	return result;
}

template <typename T>
T Mod_Bin_Exp(T N, T power, T mod) //(N^power) % mod
{
	if (N % mod == 0 || N == 0)
		return 0;
	if (N == 1 || power == 0)
		return 1;

	if (N >= mod)
		N -= mod;

	T res{1};
	while (power)
	{
		if (power & 1) // ODD
			res = mult128(res, N, mod);

		N = mult128(N, N, mod);
		power >>= 1;
	}
	return res;
}

template <typename T>
bool Check_Composite(T N, T a, T d, int s)
{
	T X = Mod_Bin_Exp(a, d, N);
	if (X == 1 || X == N - 1)
		return false; // Not composite

	for (int r = 1; r < s; r++)
	{
		X = mult128(X, X, N);
		if (X == 1 || X == N - 1)
			return false; // Not composite
	}
	return true; // Composite
}

template <typename T>
bool Miller_Rabin(T N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
	T d = N - 1;
	int s{};
	while (!(d & 1))
		d >>= 1, ++s;

	for (const T &a : {11, 13, 17, 19, 23, 29, 31, 37, 73})
	{
		if (N == a)
			return true;
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

template <typename T>
bool Is_Prime(T N)
{
	if (N < 2)
		return false;

	if (N <= 3)
		return true;
	if (N == 5 || N == 7)
		return true;

	if (!(N & 1) || N % 3 == 0 || N % 5 == 0 || N % 7 == 0)
		return false;

	return Miller_Rabin(N);
	/*for (ll i = 5; i * i <= N; i += 6)
	{
		if (N % i == 0 || (N % (i + 2) == 0))
			return false;
	}
	return true;
	*/
}
/*
|---------------|
| Factorization:|
|---------------|

|------------------------|
| Factorizing a Number N:|
|------------------------|

First, We make a vector to store all the factors of the number N
vector<ll> Factors;
--------------------------
1. A naive solution is to iterate over all numbers from 1 to N to get ALL divisors

for(int i=1;i<=N;i++)
{
	if(N%i==0)
	Factors.push_back(i);
}
These Factors are SORTED
Time Complexity: O(N)
------------------------
NOTE: We can also iterate JUST to N/2 :

Proof 1:
NO factors > N/2 can exist except N itself
As factors exist on form of pairs, There CANNOT exist a number > N/2 that is, when multiplied by any number > 1 (because 1 is paired with N) gives a result <= N

Proof 2:
There CANNOT possibly be any factors > (N / 2) EXCEPT (N) itself

Suppose (N / 2) < a <= N and N = a * b
What could b be?
We know that factors exist on form of pairs {a , b}
If b = 1, then a * b = a * 1, so a = N
So, we have a pair {1, N}
This is the only pair that contains a factor of N which is > (N / 2)

If b >= 2, then a * b > (N / 2) * 2
i.e.
a * b > N , So b CANNOT be any positive integer >= 2; thus ( (N / 2) < a < N ) is NOT a factor of N

for(int i=1;i <= N / 2;i++)
{
	if(N%i==0)
	Factors.push_back(i);
}
Factors.push_back(N);// The only Factor > N/2
These Factors are SORTED
Time Complexity is still O(N) (Still a LINEAR behaviour)
---------------------------------------------------------------------------------------------------------------------------------
2. A better solution is to iterate over all numbers until sqrt(N) to get all pairs of factors
Assume N = (a * b)
Assume a <= b
multiply both sides by a --> a² <= ab
multiply both sides by b --> ab <= b²
So a² <= (a * b) <= b²
and since N = (a * b)
a² <= N <= b²
Taking the square root of all sides: a <= sqrt(N) <= b
So if a exists, there must exist some b = N/a, that's why all factors exist on form of pairs
EXCEPT for a = sqrt(N) because b will be also sqrt(N) (a = b) which means it's ONLY one factor

// Use (i * i <= N) instead of i <= sqrt(N) to avoid the repeated calculation of sqrt() function and also because sqrt() is slow
// Use (long long i) to avoid OVERFLOW (Can cause an infinite loop because of signed integer overflow)
for(ll i=1;i * i <= N;i++)
{
	if(N % i==0)
	{
		if(N / i == i) //i = sqrt(N) i.e. a = b
		Factors.push_back(i);
		else //a and b are distinct
		Factors.push_back(i), Factors.push_back(N / i);
	}
}
//These Factors are NOT SORTED
Time Complexity: O(sqrt(N)
---------------------------------------------------------------------------------------------------------------------------------
|-----------------------------------|
| Prime Factorization of a Number N:|
|-----------------------------------|

Fundamental theorem of arithmetic:
|-----------------------------------------------------------------------------------------------|
| Every number > 1 is either a prime or a product of primes (Unique-Prime-Factorization Theorem)|
|-----------------------------------------------------------------------------------------------|

We can use several methods to get the prime factorization of a number N:
----------------------
First we create a map:
map<int , int>mp; //Stores the contribution of each prime in N (the Power of each prime)

NOTE: Extracting a prime p of a number N means keeping dividing N/p until there is NO more p's in N

------------------
1. Generate All primes up to N using Sieve of Eratosthenes (Better use Linear Sieve of Eratosthenes)
then iterate over all primes until N and at each prime, if it's a factor (N % p == 0), we extract it from N and get its contribution (power)
------------------
for(const int& p : Prime)
{
	if(N == 1) break;//If N is 1, it means that we have Extracted all primes of that number, so we don't need to iterate over all the following primes
	int cnt{};
	while(N % p == 0)
	{
		N /= p;
		cnt++;
	}
	if(cnt)// if the Power is NOT zero i.e. that prime is a factor of N (contributes to the prime factorization of N), we store it in the map
	mp[p]=cnt;
}
Worst Time Complexity: O(N) (where N is Prime)
----------------------------------------------
Another way is to iterate over all PRIMES until sqrt(N), then if (N > 1) it must be a prime number
Why?
For Any Number N, either all its primes exist before sqrt(N), or ONLY the greatest Prime Factor exists after sqrt(N)
Proof:
Assume a and b are two distinct prime factors of N
Assume a > sqrt(N) and b > sqrt(N)
Let C = a * b
C must be also a factor of N but C > N as both a and b are greater than sqrt(N)
This Contradicts our assumption, hence there can only be one prime factor greater than sqrt(N)

for(const int& p : Prime)
{
	if(p * p > N) break;
	int cnt{};
	while(N % p == 0)
	{
		cnt++;
		N /= p;
	}
	if(cnt)// if the Power is NOT zero i.e. that prime is a factor of N (contributes to the prime factorization of N), we store it in the map
	mp[p]=cnt;
}
if(N > 1)
mp[N]++;

Time Complexity: O(sqrt(N)); Works fine Until approximately 10¹²
-----------------------------------------------------------------
2. Similar to the Sieve-of-Eratosthenes logic, We can iterate over all numbers from 2 to sqrt(N) and at each number, if it is a factor, we extract it from N
Proof:
Any prime number p is ONLY divisible by 1 and itself (p), i.e. Any prime number is NOT divisible by any of its preceding numbers
Example:
A number like 72
Extracting all 2's is just like crossing out all multiples of 2 in the factors of 72
When we come to 3 if it's a factor of 72 that means it wasn't crossed out by any of its preceding numbers i.e. it is NOT divisible by any of them so, it MUST be a prime
but when we come to 4, although it's a factor of 72, the remaining of 72 (which is 1 because 72 = 2^3 * 3^2) wouldn't be divisible by 4 because it's crossed out by 2
and so is 6,9,12...etc.
72's factors:1	2	3	4	6	8	9	12	18	24	36	72
Extract 2's: 72/2 = 36
36/2 = 18
18/2 = 9 --> 2³
Now 9 isn't divisible by 4, 6, 8, 12, 18, 24, 36 or 72
Extract 3's: 9/3 = 3
3 / 3 = 1 --> 3²
Now 72 reached 1 i.e. it was totally factorized to its primes
------------------
// Use (i * i <= N) instead of i <= sqrt(N) to avoid the repeated calculation of sqrt() function and also because sqrt() is slow
// Use (long long i) to avoid OVERFLOW (Can cause an infinite loop because of signed integer overflow)
for(ll i = 2;i * i <= N;i++)
{
	int cnt{};
	while(N % i == 0)
	N /= i,cnt++;

	if(cnt)
	mp[i] = cnt;

}
//What about prime factors that are greater than sqrt(N) ?
if(N > 1)
mp[N]++;
Time Complexity: O(sqrt(N))
------------------------------------
3. Using LPF for answering multiple queries
------------------
Linear_Sieve_Of_Eratosthenes(10000000);// To get LPF of all numbers until 1000'000'0
while(N!=1)
{
	mp[LPF[N]]++;
	N/=LPF[N];
}
Time Complexity: O(Log(N)); Works fine for N <= 10^7 because beyond that we will face memory issues (We won't be able to store LPF of more than 10^7 numbers)
---------------------------------------------------------------------------------------------------------------------------------
|-----------------------------------------|
| Counting Number of Factors of a Number N|
|-----------------------------------------|

1. A naive solution is to iterate over ALL numbers from 1 to N to count ALL divisors
for(int i=1;i <= N;i++)
{
	if(N % i == 0)
	cnt++;
}
Time Complexity: O(N)
---------------------
NOTE: We can also iterate JUST to N/2 : (Proved preciously)
for(int i=1;i <= N/2;i++)
{
	if(N % i == 0)
	cnt++;
}
cnt++;// The only Factor > N/2 which is N itself
Time Complexity is still O(N) (Still a LINEAR behaviour)
---------------------------------------------------------------------------------------------------------------------------------
2. A better solution is to iterate over all numbers until sqrt(N) to get and count ALL pairs of factors (Proved previously)

// Use (i * i <= N) instead of i <= sqrt(N) to avoid the repeated calculation of sqrt() function and also because sqrt() is slow
// Use (long long i) to avoid OVERFLOW (Can cause an infinite loop because of signed integer overflow)
for(ll i=1;i * i <= N;i++)
{
	if(N % i==0)
	{
		if(N / i == i)//i = sqrt(N)
		cnt++;
		else
		cnt+=2;
	}
}
Time Complexity: O(sqrt(N)
---------------------------------------------------------------------------------------------------------------------------------
A better solution is to use the prime factorization of a number N to count its factors --> This method ONLY counts the factors but doesn't find the factors themselves
Preface:
---------------
if N = a^p * b^q * c^r ..... (Prime factorization of N)
Then, the number of factors of N = (p+1)*(q+1)*(r+1).....
WHY?
---------------
let's consider a^p which is: 1 a a^2 a*3 .... a^p which gives (1+p) divisors
when having other prime factors, all of them will be multiplied by all previous factors making new ones
Let's Consider for sake of simplicity a number N = a^p * b^q
The divisors of N would be:
1		p		p^2			...		p^a
q		p*q		p^2*q		...		p^a*q
q^2		p*q^2	p^2*q^2		...		p^a*q^2
...		...		...			...		...
q^b		p*q^b	p^2*q^b		...		p^a*q^b

Example:
72= 2³ * 3²
There are (3+1)*(2+1) --> 12 factors of 72
Different Combinations of (1 2 2 2)(3 3) will form ALL possible factors
1		2		2^2				2^3
3		2*3		2^2 * 3			2^3 * 3
3^2		2*3^2	2^2 * 3^2		2^3 * 3^2

1--> 2^0 and 3^0 *2^0
2--> 2^1 = 2
4--> 2^2 = 4
8--> 2^3 = 8
3--> 3^1 * 2^0 = 3
6--> 3^1 * 2 = 6
12--> 3^1 * 2^2 = 12
24--> 3^1 * 2^3 = 24
9--> 3^2 * 2^0 = 9
18--> 3^2 * 2^1 = 18
36--> 3^2 * 2^2 = 36
72--> 3^2 * 2^3 = 72
which are the 12 factors of 72
So, it's easily noticed that the number of factors can be calculated as (p+1)*(q+1)*(r+1).....

We can use any of the previous methods to get the prime factorization of N then use this rule but they were also of time complexity O(sqrt(N)), can we do better?
Yes!

3. A better solution is to iterate over all PRIMES until cbrt(N)
---------------
Assume N = a * b * c
Assume a <= b <= c
We will split our number N into two numbers X and Y such that X * Y = N.
Further, X contains only prime factors in range [2,cbrt(N)] and Y deals with higher prime factors (>cbrt(N)).
Thus, gcd(X , Y) = 1.
Let the count of divisors of a number N be denoted by the function F(N).
It is easy to prove that this function is multiplicative in nature, i.e., F(m * n)=F(m) * F(n), if gcd(M, N) = 1.
So, if we can find F(X) and F(Y), we can also find F(X * Y) or F(N) which is the required quantity.

For finding F(X), we use the naive trial division to prime factorize X and calculate the number of factors. Once this is done, we have Y = N / X remaining to be factorized.
This may look tough, but we can see that there are only three cases which will cover all possibilities of Y :

Y is a prime number : F(Y) = 2 -->(1 and Y)
Y is square of a prime number : F(Y) = 3 --> (1, Y and Y^2)
Y is product of two distinct prime numbers : F(Y) = 4 --> (a * b where a and b are primes so they give (1+1)*(1+1) --> 4 factors)
We have only these three cases since there can be at max two prime factors of Y.
If it would have had more than two prime factors, one of them would surely have been , and hence it would be included in X and not in Y.

So once we are done with finding F(X) and F(Y), we are also done with finding F(X*Y) or F(N).
*/
template <typename T>
T countDivisors(T N)
{
	T Ans = 1;
	for (const int &p : Prime)
	{
		if (T(1) * p * p * p > N)
			break;

		T cnt{1};
		while (N % p == 0)
		{
			N /= p;
			cnt++;
		}
		Ans *= cnt;
	}
	ll Sqrt_N = sqrt(N);
	if (Is_Prime(N))
		return Ans * 2;
	else if (Sqrt_N * Sqrt_N == N && Is_Prime(Sqrt_N))
		return Ans * 3;
	else if (N != 1)
		return Ans * 4;
	else
		return Ans;
}
/*
NOTE: Checking for primality can be done quickly using Miller-Rabin but this decreases the accuracy of this method because it's a probabilistic algorithm but the trade-off deserves!
---------------------------------------------------------------------------------------------------------------------------------
4.If the problem was to find the number of divisors for a range of numbers (NOT Exceeding 10^6) it's useful to use precalculation to store the answers to all queries
The Idea is to traverse all numbers from 1 to N and for each number i we will increase all its multiples (i,2i,3i,4i,...) by 1

vector<int>Num_Of_Divs(1000001,1);//Initially all numbers have just one factor which is the {1}
for(int i{2};i<=1000001;i++)
{
	for(int j=i;j<=1000001;j+=i)
	Num_Of_Divs[j]+=1;
}
---------------------------------------------------------------------------------------------------------------------------------
5.A better solution is to use the LPF to get the prime factorization of N

Linear_Sieve_Of_Eratosthenes(10000000);// To get LPF of all numbers until 10000000
int cnt{1};
while(N!=1)
{
	if(LPF[N/LPF[N]]!=LPF[N])//If a new prime factor is being extracted
	{
		r *= (cnt + 1);
		r%=(1073741824);
		cnt=0;
	}
	N/=LPF[N];
	cnt++;
}
Time Complexity: O(Log(N)); Works for N <= 10^7 because beyond that we will face memory issues (We won't be able to store LPF of more than 10^7 numbers)

|-------------------------------------------|
| Counting Number of Factors of a Number N^x|
|-------------------------------------------|

if N = a^p * b^q * c^r ..... (Prime factorization of N)
Then, N^x =  (a^p * b^q * c^r .....)^x = a^(xp) * b^(xq) * c^(xr) .....
Hence, the number of factors of N^x = (xp+1)*(xq+1)*(xr+1).....
So we can calculate it Using the Prime factorization of N not N^x

|-------------------------------------------|
| Counting Number of Factors of a Number N! |
|-------------------------------------------|

Obviously we can just calculate N! then work as the shown previous cases, but what if N! is too way large?
We would face two problems:
1. It's NOT possible to represent that N! in any of the primitive data types of integers in C++
2. If we could somehow represent N!, we would get a TLE because the fastest algorithm we got is O(cbrt(N)) and cbrt(N!) is still too way large
What if we could get the prime factorization of N! without really calculating N! ?

The prime factorization of N!
-----------------------------
N! = 1 * 2 * 3 * 4 * 5 .... (N-1) * N
For Example:
33! = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33
		2   2   2   2    2     2     2     2     2     2     2     2     2     2     2     2
			2       2          2           2           2           2           2           2
					2                      2                       2                       2
										   2                                               2
																						   2
		  3     3     3        3        3        3        3        3        3        3        3
					  3                          3                          3
																			3
			  5          5              5              5              5              5
																	  5
				  7                  7                    7                    7
						   11                               11                               11
								 13                                     13
											 17
												   19
															   23
																				 29    31
Do you see The Pattern?

33! = 2^( 33 / 2 + 33 / 4 + 33 / 8 + 33 / 16 + 33 / 32) *
	  3^( 33 / 3 + 33 / 9 + 33 / 27) *
	  5^( 33 / 5 + 33 / 25) *
	  ----
	  7^( 33 / 7) * 11^( 33 / 11) * 13^( 33 / 13) *
	  ----
	  17 * 19 * 23 * 29 * 31

Or we can say:

33! = 2^( 33 / 2 + 16 / 2 + 8 / 2 + 4 / 2 + 2 / 2) *
	  3^( 33 / 3 + 11 / 3 + 3 / 3) *
	  5^( 33 / 5 + 5 / 5) *
	  ----
	  7^( 33 / 7) * 11^( 33 / 11) * 13^( 33 / 13) *
	  ----
	  17 * 19 * 23 * 29 * 31

This is called the Legendre's Formula
-------------------------------------
ll expFactor(ll N, int p)
{
	ll exponent=0;
	while ((N = N / p) != 0)
		exponent+=N;

	return exponent;
}

|------------------------------|
| Sum of factors of a number N |
|------------------------------|

Let N = a^p * b^q * c^r ..... (Prime factorization of N)

Sum of factors of N = (a^(p+1) - 1) / (a - 1) * (b^(q+1) - 1) / (b - 1) * (c^(r+1) - 1) / (c - 1) .....

|--------------------------------|
| Sum of factors of a number N^x |
|--------------------------------|

N^x =  (a^p * b^q * c^r .....)^x = a^(xp) * b^(xq) * c^(xr) .....

Sum of factors of N^x = (a^(xp+1) - 1) / (a - 1) * (b^(xq+1) - 1) / (b - 1) * (c^(xr+1) - 1) / (c - 1) .....

|----------------------------------|
| Product of factors of a number N |
|----------------------------------|

First, we mention a fact about the divisors of N. It is easy to see that (d) is a divisor of N iff (N/d) is also a divisor of N.
That means that all factors of N appear on the form of pairs of distinct numbers: {d,N/d} EXCEPT for the divisor {sqrt(N)}, in case N is a perfect square,  which is solitary
Example:
N = 12
All pairs of factors are: {1, 12}, {2, 6} and {3, 4}

N=25
All pairs of factors are: {1, 25} and {5}

Let the number of factors of N be d(N)
In Case N is NOT a perfect square:
There are d(N)/2 pairs of factors, the product of each pair of them MUST give N
Product of factors of N = N^(d(N)/2)

In Case N is a perfect square:
There are (d(N)-1)/2 pairs of factors plus a solitary individual sqrt(N), the product of each pair of them MUST give N
Product of factors of N = N^((d(N)-1)/2) * sqrt(N) = N^(d(N)/2)

So, whether N is a perfect square or NOT:
Product of factors of N = N^(d(N)/2)
*/

//---------------------------------------------------------------------------------------------------------------------------------

ll Num_Of_Divisors(ll N)
{
	int &r = Div_Count[N];
	if (r != -1) // If already calculated
		return r;

	else
	{
		r = 1;
		int cnt{1};
		while (N != 1)
		{
			if (LPF[N / LPF[N]] != LPF[N])
			{
				r *= (cnt + 1);
				r %= (1073741824);
				cnt = 0;
			}
			N /= LPF[N];
			cnt++;
		}
		return r;
	}
}

ll Sum_Of_Divisors(ll N)
{
	if (N == 1) // 1 Has ONLY 1 divisor which is itself (1)
		return 1;

	// Use powl() NOT pow() to avoid double-precision issues
	// Use (i * i <= N) instead of i <= sqrt(N) to avoid the repeated calculation of sqrt() function and also because sqrt() is slow
	// Use (long long i) to avoid OVERFLOW (Can cause an infinite loop because of signed integer overflow)
	ll Sum{1};
	for (ll i = 2; i * i <= N; i++)
	{
		int cnt{};
		while ((ll)(N) % i == 0)
			N /= i, cnt++;

		if (cnt) // A prime factor was Extracted
			Sum *= ((powl(i, cnt + 1) - 1) / (i - 1));
	}
	if (N > 1)
		Sum *= ((powl(N, 2) - 1) / (N - 1));

	return Sum;
}
void Prime_Factorize(ll N)
{
	// Use (i * i <= N) instead of i <= sqrt(N) to avoid the repeated calculation of sqrt() function and also because sqrt() is slow
	// Use (long long i) to avoid OVERFLOW (Can cause an infinite loop because of signed integer overflow)
	for (ll i = 2; i * i <= N; i++)
	{
		int cnt{};
		while (N % i == 0)
			N /= i, cnt++;

		if (cnt)
		{
			cout << "(" << i << "^" << cnt << ")";
			if (N > 1)
				cout << "*";
		}
	}

	if (N > 1)
		cout << "(" << N << "^1"
			 << ")";
}
ll Min_number_to_get_perfect_square(ll N)
{
	/*
	Let P be a prime number
	The prime factorization of N is:
	N = P1^a1 * P2^a2 * P3^a3 ... Pk^ak
	Now if ai is EVEN that means it's a perfect square, Otherwise, that means it's NOT
	So, we should multiply by ALL NON-perfect-square terms (Pi's) (to raise their power by 1) so that the whole number becomes a perfect square
	Example:
	360 = 2³ * 3² * 5¹
	if we multiply by (2 * 5) we get 3600 which is a perfect square
	*/
	ll ans{1};
	for (ll i{2}; N > 1; i++)
	{
		int cnt{};
		while (N % i == 0)
			++cnt, N /= i;

		if (cnt % 2 == 1)
			ans *= i;
	}
	return ans;
}
//---------------------------------------------------------------------------------------------------------------------------------

/*
Target: finding g(N!) = f(a) + f(b) + f(c) ...... where a, b, c ...... are the factors of N! and f(a) means the number of divisors of the number a

The number of divisors for some number N with prime factorization p^a1 * q^a2 ...... r^ak is: (a1+1)*(a2+1)......(ak+1)

You can try to find the value of the function g for some number N with a simple prime factorization p^a : g(p^a)= ∑ (x+1) =(a+1)*(a+2)2
How?
if N = p^a then all possible factors of N are: p^0, p^1, p^2 .....and p^a
number of divisors of p^0 is directly (0+1) which is 1 because p is a prime number, so p^0 is its prime factorization
number of divisors of p^1 is directly (1+1) which is 2 for the same reason
.
.
and so on
So you can easily notice that the sum of number of divisors of the factors of N (which is the definition of g) is: 1 + 2 + 3 + 4 + ...... +(a+1)
which is reduced to (a+1)*(a+2)/2

Then you can try to find the value of the function g for some number N with a bit more complex prime factorization p^a * q^b
: g(p^a * q^b) = ∑∑(x+1)(y+1) = (a+1)*(a+2)/2 * (b+1)*(b+2)2
.
.
.
And so on. You can easily see that the function g is multiplicative.
So the problem is reduced to the prime factorization of N!
*/
//---------------------------------------------------------------------------------------------------------------------------------

// Returns the highest exponent of p in N! (Legendre's Formula)
int Sum_Of_Bin(ll N, int base)
{
	// implementing it iteratively to Avoid Recursive function Call Over-Head
	/*
	What is Overhead??
	In general, it's resources (most often memory and CPU time) that are used, which do not contribute directly to the intended result, but are required by the technology or method
	that is being used. Examples:
	Data structure memory overhead: A linked list requires at least one pointer for each element it contains. If the elements are the same size as a pointer,
	this means a 50% memory overhead, whereas an array can potentially have 0% overhead.
	Method call overhead: A well-designed program is broken down into lots of short methods. But each method call requires setting up a stack frame,
	copying parameters and a return address. This represents CPU overhead compared to a program that does everything in a single monolithic function.
	Of course, the added maintainability makes it very much worth it, but in some cases, excessive method calls can have a significant performance impact.
	*/
	int res{};
	while (N != 0)
	{
		res += (N % base);
		N /= base;
	}
	return res;
}
ll expFactor(ll N, int p)
{
	ll exponent = (N - Sum_Of_Bin(N, p)) / (p - 1);
	/*ll exponent = 0;
	while ((N = N / p) != 0)
		exponent+=N;*/
	return exponent;
}

ll g(ll N)
{
	ll Ans{1};
	for (const int &p : Prime)
	{
		if (p > N)
			break;
		if (p <= N / 2)
		{
			ll cnt = expFactor(N, p);
			if (cnt != 0)
				Ans = (Ans % 10000007 * (cnt + 1) * (cnt + 2) / 2) % 10000007;
		}
		else
			Ans = (Ans % 10000007 * 3) % 10000007;
	}

	return Ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	Linear_Sieve_Of_Eratosthenes(1000001);

	int N;
	// cin >> N;
	// cout << Num_Of_Factors(N);
	// cout << (ll)(Sum_Of_Divisors(N));
	// Prime_Factorize(N);

	// All About Divisors
	// https://codeforces.com/group/H10hR2t6Sj/contest/338701/problem/J
	/*
	while (cin >> N)
	{
		if (N == 0)
			return 0;
		cout << g(N) % 10000007 << "\n";
	}
	*/

	// Easy Number Challenge
	// https://codeforces.com/problemset/problem/236/B
	/*
	int a, b, c;
	cin >> a >> b >> c;
	memset(Div_Count, -1, sizeof Div_Count);
	ll Sum{};
	for (int i{1}; i <= a; i++)
	{
		for (int j{1}; j <= b; j++)
		{
			for (int k{1}; k <= c; k++)
				Sum = (Sum % 1073741824 + 1LL * Num_Of_Divisors(i * j * k) % 1073741824) % 1073741824;
		}
	}
	cout << Sum;
	*/

	/*
	 * More Problems:
	 * https://codeforces.com/gym/100753 : F
	 * https://cses.fi/problemset/task/1713
	 * https://codeforces.com/problemset/problem/26/A
	 * https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/G
	 * https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/J
	 * https://codeforces.com/contest/1062/problem/B
	 */
	return 0;
}