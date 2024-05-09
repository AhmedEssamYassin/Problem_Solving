/*
|-------------|
|Prime numbers|
|-------------|

A prime number is a natural number greater than 1, which is only divisible by 1 and itself
In other words, the prime number is a positive integer greater than 1 that has exactly two factors, 1 and the number itself

|------------------------------------------|
|Some interesting facts about Prime numbers|
|------------------------------------------|

1. Except for 2, which is the smallest prime number and the only even prime number, all prime numbers are ODD numbers.
2. Every prime number can be represented in form of (6i + 1) or (6i - 1) except the prime numbers 2 and 3, where i is a natural number.
3. Two and Three are the ONLY two consecutive natural numbers that are primes.
4. Every EVEN integer greater than 2 can be expressed as the sum of two primes.
5. Fermat's Little Theorem:
	If N is a prime number, then for every a, where 1 <= a < N,
	a^(N-1) % N = 1

|---------------------------|
|Properties of prime numbers|
|---------------------------|

1. Every number greater than 1 can be divided by at least one prime number.
2. Every EVEN positive integer greater than 2 can be expressed as the sum of two primes.
3. Except for 2, ALL other prime numbers are ODD. In other words, we can say that 2 is the only even prime number.
4. Two prime numbers are always co-prime to each other.
5. Each composite number can be factored into prime factors and individually all of these are unique in nature.

|----------------------------------|
|Prime numbers and co-prime numbers|
|----------------------------------|

1. A co-prime number is always considered as a pair, whereas a prime number is considered as a single number.
2. Co-prime numbers are numbers that have NO common factor except 1. In contrast, prime numbers do not have such a condition.
3. A co-prime number can be either prime or composite, but its greatest common factor (GCD) must always be 1.
Unlike composite numbers, prime numbers have only two factors, 1 and the number itself.

Example of co-prime:
13 and 15 are co-primes. The factors of 13 are 1 and 13 and the factors of 15 are 1, 3 and 5.
We can see that they have only 1 as their common factor, therefore, they are co-prime numbers.

Example of prime: A few examples of prime numbers are 2, 3, 5, 7 and 11 etc.

|-----------------------------------------|
|How to check the primality of a number N?|
|-----------------------------------------|

A naive approach:
-----------------
Check the divisibility of N by ALL numbers in range [2, N-1]
If N is divisible by any of them, then N is NOT prime. Otherwise, N is prime

bool Is_Prime(ll N)
{
	for(ll i=2,i<N;i++)
	{
		if(N%i==0)
		return false;
	}
	return true;
}

Time Complexity: O(N) which is relatively slow
Can we do better?
---------------------------------------------------------------------------------------------------------------------------------------------------------
Check the divisibility of N by ALL numbers in range  [2, N/2]


Proof 1:
NO factors > N/2 can exist except N itself
As factors exist on form of pairs, There CANNOT exist a number > N/2 that is, when multiplied by any number > 1 (because 1 is paired with N) gives a result <= N

Proof 2:
There CANNOT possibly be any factors > (N/2) EXCEPT (N) itself

Suppose (N/2) < a <= N and N = a * b
What could b be?
We know that factors exist on form of pairs {a , b}
If b = 1, then a * b = a * 1, so a = N
So, we have a pair {1, N}
This is the only pair that contains a factor of N which is > (N/2)

If b >= 2, then a * b > (N/2) * 2
i.e.
a * b > N , So b CANNOT be any positive integer >= 2; thus ( (N/2) < a < N ) is NOT a factor of N

bool Is_Prime(ll N)
{
	for(ll i=2,i <= N/2;i++)
	{
		if(N % i == 0)
		return false;
	}
	return true;
}

but still Time Complexity is O(0.5 N) which is === O(N)
Can we do better?
---------------------------------------------------------------------------------------------------------------------------------------------------------
Check the divisibility of N by ALL numbers in range  [2, sqrt(N)]

If a number N is not a prime, it can be factored into two factors {a , b}

a and b can't be both greater than sqrt(N) since then the product (a * b) would be greater than sqrt(N)*sqrt(N) = N
So in any factorization of N, at least one of the factors must be smaller than sqrt(N)
and if we CANNOT find any factors less than or equal to sqrt(N), N must be a prime.
Proof:

N = a * b
Assume a <= b
Multiplying both sides by a we get a² <= a * b
Multiplying both sides by b we get a * b <= b²
and since N = a * b
we get a² <= N <= b²
taking square root of all sides we get a <= sqrt(N) <= b

We know that factors exist on form of pairs {a , b}
So, b is corresponding to a
i.e. If a|N then b = N/a
So, existence of b is dependent on the existence of a
i.e. If a does NOT exist, b does NOT exist either

So, the idea is to check the divisibility of N by ALL numbers in range  [2, sqrt(N)]
i.e. Check if there exists any a and if there is NOT any a there CANNOT exist any b
which means N is NOT divisible by any numbers neither <= sqrt(N) nor >=sqrt(N), thus N is a prime

NOTE:
we can check on the factors that are greater than the sqrt(N) and still get the same answers but the needed time differs!
because the numbers [2,sqrt(N)] are way less than the numbers [sqrt(N),N]

bool Is_Prime(ll N)
{
	for(ll i=2;i <= sqrt(N);i++)
	{
		if(N % i == 0)
		return false;
	}
	return true;
}
Time Complexity: O(sqrt(N))

We can do further improvements that don't significantly affect the Time Complexity but can handle some edge cases:
1. Use (i * i <= N) instead of (i <= sqrt(N)) To avoid the OVERHEAD of the sqrt() function and to avoid repeated calculations
but be careful for (i*i) NOT to OVERFLOW (Use long long)
2. Skip all multiples of 2 (all EVEN numbers) and 3

What is Overhead?
-----------------
In general, it's resources (most often memory and CPU time) that are used, which do not contribute directly to the intended result
but are required by the technology or method that is being used.
Examples:
Data structure memory overhead: A linked list requires at least one pointer for each element it contains. If the elements are the same size as a pointer,
this means a 50% memory overhead, whereas an array can potentially have 0% overhead.

Method call overhead: A well-designed program is broken down into lots of short methods. But each method call requires setting up a stack frame,
copying parameters and a return address. This represents CPU overhead compared to a program that does everything in a single monolithic function.
Of course, the added maintainability makes it very much worth it, but in some cases, excessive method calls can have a significant performance impact.

bool Is_Prime(ll N)
{
	if(N<2)
	return false;

	if(N<=3)
	return true;

	if(N%2==0 or N%3==0)
	return false;

	for(ll i=5;i * i <= N;i += 6)
	{
		if(N % i == 0 ||(N % (i + 2) == 0))
		return false;
	}
	return true;
}
Time Complexity: O(sqrt(N))
Can we do better?
---------------------------------------------------------------------------------------------------------------------------------------------------------
We can actually use a mathematical expression (O(1)) to check the primality of N which is:
Fermat's Little Theorem: If N is a prime number, then for every a, 1 <= a < N, a^(N-1) % N = 1

bool Is_Prime(ll N)
{
	if(N<2)
	return false;

	if(N<=3)
	return true;

	return (pow(2, N-1) % N == 1);
}
This code actually has some crucial problems:

1. The term pow(2, N-1) is increasing exponentially, which means that an intermediate OVER-FLOW will definitely occur

|----------------------|
|Intermediate OVER-FLOW|
|----------------------|

Means that the final answer is small enough to be represented in C++ language but there is a potential OVER-FLOW in intermediate calculations
We can avoid this type of OVER-FLOW by using properties of the modular arithmetic operator:
Assume N = (The greatest possible expected output)
Choose a number X where X > N
keep TAKING MOD X for all intermediate calculations to prevent the OVER-FLOW

Obviously, we take MOD N to the returned value of pow(2, N-1). So, the final answer will always be [0, N-1]
Thus, we can use Modular exponentiation to calculate pow(2, N-1) so as to avoid intermediate OVER-FLOW

Code:
ll Mod_Bin_Exp(ll N, ll power, ll mod) //(N^power) % mod
{
	if (N % mod == 0 || !N)
		return 0;
	if (N == 1 || power == 0)
		return 1;
	N %= mod;
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = (res % mod * N % mod) % mod;
		N = (N % mod * N % mod) % mod;
		power >>= 1;
	}
	return res;
}

bool Is_Prime(ll N)
{
	if(N<2)
	return false;

	if(N<=3)
	return true;

	return (Mod_Bin_Exp(2, N-1, N) % N == 1);
}

2. This method does NOT work for all numbers

There are two types of Algorithms:
- Deterministic algorithms: Provides a definitive answer to a question
- Probabilistic algorithms: Provides a high-Probable answer to a question (NOT accurate 100%)

Fermat's Little Theorem to check primality is a probabilistic algorithm
It fails for ALL Carmichael numbers

The Fermat's Little Theorem expression actually executes in O(log N) time because of using Mod_Bin_Exp() function

So the Time Complexity of this code is eventually O(log N) which is the fastest of all methods but it fails if the test cases contain Carmichael numbers!
---------------------------------------------------------------------------------------------------------------------------------------------------------
Miller-Rabin Primality test:
----------------------------
For an ODD number N --> (N-1) Must be EVEN
We can write (N-1) = d * 2^s where d is ODD
This allows us to factorize the equation of Fermat's little theorem:
a^(N-1) % N = 1
a^(d * 2^s) %N = 1
a^(d * 2^s) %N - 1 = 0
Use the factorization of a difference between two squares:
(a^(d* 2^(s-1))%N - 1)*(a^(d* 2^(s-1))%N + 1) = 0
.
.
.
Eventually, 2^s will be 2^0 which is 1
So, after factorization:
(a^(d* 2^(s-1))%N - 1)*(a^(d* 2^(s-1))%N + 1).....(a^d %N + 1)*(a^d %N  - 1) = 0

If N is prime, then N has to divide one of these factors.
And in the Miller-Rabin primality test we check exactly that statement, which is a more stricter version of the statement of the Fermat's test.
For a base 2 =< a <= N-2 we check if either:
a^d %N = 1
or
a^(d* 2^r)%N = -1 for 0 =< r <= s-1

If we found a base a which doesn't satisfy any of the above equalities, than we found a witness for the compositeness of N
In this case we have proven that N is not a prime number.

Similar to the Fermat test, it is also possible that the set of equations is satisfied for a composite number.
In that case the base a is called a strong liar.
If a base a satisfies the equations (one of them), N is only strong probable prime.
However, there are NO numbers like the Carmichael numbers, where all NON-trivial bases lie.
In fact it is possible to show, that at most 25% of the bases can be strong liars.
If N is composite, we have a probability of 75% that a random base will tell us that it is composite.
By doing multiple iterations, choosing different random bases, we can tell with very high probability if the number is truly prime or if it is composite.

Code:
-----
/*
Implementing a function for Modular multiplication causes OVERHEAD and is TOO SLOW compared to the regular arithmetic expression

But Modular multiplication Even when using the property (A * B)%mod = ((A % mod) *(B % mod)) % mod Can cause intermediate OVERFLOW
(A % mod) < mod
(B % mod) < mod
But their multiplication is very likely to be greater than mod and may be greater than the capacity of the whole type causing an OVERFLOW
Solutions to this problem:
1. Modular Binary Multiplication

ll Mod_Mult(ll a, ll b, ll mod) //(a * b) % mod
{
	ll res = 0; // Initialize result

	for (a %= mod; b > 0; a <<= 1, b >>= 1)
	{
		if (a >= mod)
			a -= mod;
		if (b & 1)
		{
			res += a;
			if (res >= mod)
				res -= mod;
		}
	}

	return res;
}
-----------------------------------------------------
2. Multiplication via type __int128_t or __int128
To multiply two 32-bit numbers, you need a 64-bit intermediate variable.
And to multiply two 64-bit numbers, you need a 128-bit variable!
Modern 64-bit C++ compilers (except perhaps Microsoft® Visual C++®) have a special type __int128, which allows performing operations on 128-bit numbers.


ll Mod_Bin_Exp(__int128 N, ll power, ll mod) //(N^power) % mod
{
	if (N % mod == 0 || N == 0)
		return 0;
	if (N == 1 || power == 0)
		return 1;
	N %= mod;
	__int128 res{1};
	while (power)
	{
		if (power & 1)
			res = ((res % mod) * (N % mod)) % mod;
		N = ((N % mod) * (N % mod)) % mod;
		power >>= 1;
	}
	return res;
}

bool Check_Composite(ll N, ll a, ll d, int s)
{
	__int128 X = Mod_Bin_Exp(a, d, N);
	if (X == 1 || X == N - 1)
		return false;//Not composite

	for (int r = 1; r < s; r++)
	{
		//X = Mod_Mult(X, X, N);
		X = ((X % N) * (X % N)) % N;
		if (X == 1||X == N - 1)
		return false;//Not composite
	}
	return true;//Composite
}
bool Miller_Rabin(ll N, int K=5)// k is the number of trials (bases). If k increases the accuracy increases
{
	// returns true if N is probably a prime, else returns false.
	//(N-1) = d * 2^s
	int s = 0;
	ll d = N - 1;
	while ((d & 1) == 0)//if d is EVEN
	{
		d >>= 1;// d/=2
		s++;
	}

	for (int i = 0; i < K; i++)
	{
		int a = 2 + rand() % (N-3);// 2 =< a <= N-2
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

Deterministic version of Miller-Rabin:
--------------------------------------
Miller showed that it is possible to make the algorithm deterministic by only checking all bases <= O((ln N)²).
Bach later gave a concrete bound, it is only necessary to test all bases   a <= 2 ln(N²)

This is still a pretty large number of bases. So, people have invested quite a lot of computation power into finding lower bounds.
It turns out that,
For testing a 32-bit integer, it is only necessary to check the first 4 prime bases: 2, 3, 5 and 7. The smallest composite number that fails this test is  
3215031751 = 151 * 751 * 28351 .

For testing a 64-bit integer, it is enough to check the first 12 prime bases: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37

bool Det_Miller_Rabin(ll N)
{
	// returns true if N is probably a prime, else returns false.
	//(N-1) = d * 2^s
	int s = 0;
	ll d = N - 1;
	while ((d & 1) == 0)//if d is EVEN
	{
		d >>= 1;// d/=2
		s++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
	{
		if (N == a)
			return true;
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

bool Is_Prime(ll N)
{
	if (N < 2)
	return false;
	if(N <=3)
	return true;
	if(N%2==0 ||N%3==0)
	return false;

	return Miller_Rabin(N);
	//return Det_Miller_Rabin(N);
}
---------------------------------------------------------------------------------------------------------------------------------------------------------
Generating ALL primes in range [1, N]
|---------------------|
|Sieve Of Eratosthenes|
|---------------------|
The idea behind is this:
A number is prime, if NONE of the smaller prime numbers divides it.
Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible.
Hence if we reach a cell and it is NOT marked, then it isn't divisible by any smaller prime number and therefore has to be prime.

Obviously, to find all the prime numbers until N , it will be enough just to perform the sifting only by the prime numbers, which do NOT exceed the sqrt(N)

bool* Sieve_Of_Eratosthenes(long long N)
{
	bool *Prime = new bool[N + 1]; // true means Prime and false means NOT prime
	memset(Prime, true, N + 1); // Assuming all numbers are initially primes
	Prime[0] = false, Prime[1] = false; // 0 and 1 are NOT primes
	for (int i{2}; i * i < N + 1; i++)
	{
		if (Prime[i]) // If Prime
		{
			for (int j = 2 * i; j <= N; j += i)
				Prime[j] = false; // Mark all multiples of i as NOT primes
		}
	}
	return Prime;
}

|----------------------------|
|Linear Sieve Of Eratosthenes|
|----------------------------|

vector<int> Prime;

void Linear_Sieve_Of_Eratosthenes(ll N)
{
	vector<bool> Is_Prime(N + 1, 1); // Initially Assuming all numbers to be primes
	vector<int> LPF(N + 1);
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
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
vector<int> Prime;

void Linear_Sieve_Of_Eratosthenes(int N)
{
	vector<bool> Is_Prime(N + 1, 1); // Initially Assuming all numbers to be primes
	vector<int> LPF(N + 1);
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

ll Mod_Mult(ll a, ll b, ll mod) //(a*b)%mod
{
	ll res = 0; // Initialize result

	for (a %= mod; b > 0; a <<= 1, b >>= 1)
	{
		if (a >= mod)
			a -= mod;
		if (b & 1)
		{
			res += a;
			if (res >= mod)
				res -= mod;
		}
	}

	return res;
}

ll Mod_Bin_Exp(__int128 N, ll power, ll mod) //(N^power) % mod
{
	if (N % mod == 0 || N == 0)
		return 0;
	if (N == 1 || power == 0)
		return 1;
	N %= mod;
	__int128 res{1};
	while (power)
	{
		if (power & 1)
			res = ((res % mod) * (N % mod)) % mod;
		N = ((N % mod) * (N % mod)) % mod;
		power >>= 1;
	}
	return res;
}

bool Check_Composite(ll N, ll a, ll d, int s)
{
	__int128 X = Mod_Bin_Exp(a, d, N);
	if (X == 1 || X == N - 1)
		return false; // Not composite

	for (int r = 1; r < s; r++)
	{
		X = ((X % N) * (X % N)) % N;
		if (X == 1 || X == N - 1)
			return false; // Not composite
	}
	return true; // Composite
}
bool Miller_Rabin(ll N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
	// returns true if N is probably a prime, else returns false.
	//(N-1) = d * 2^s
	int s = 0;
	ll d = N - 1;
	while ((d & 1) == 0) // if d is EVEN
	{
		d >>= 1; // d/=2
		s++;
	}

	for (int i = 0; i < K; i++)
	{
		int a = 2 + rand() % (N - 3); // 2 =< a <= N-2
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

// Deterministic version of Miller-Rabin
bool Det_Miller_Rabin(ll N)
{
	// returns true if N is probably a prime, else returns false.
	// (N - 1) = d * 2^s
	int s = 0;
	ll d = N - 1;
	while ((d & 1) == 0) // if d is EVEN
	{
		d >>= 1; // d/=2
		s++;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
	{
		if (N == a)
			return true;
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

bool Is_Prime(ll N)
{
	if (N < 2)
		return false;
	if (N <= 3)
		return true;
	if (N % 2 == 0 || N % 3 == 0)
		return false;

	return Miller_Rabin(N);
	// return Det_Miller_Rabin(N);
	// return (Mod_Bin_Exp(2,N-1,N)%N==1);

	/*for (ll i = 5; i * i <= N; i += 6)
	{
		if (N % i == 0 || (N % (i + 2) == 0))
			return false;
	}
	return true;
	*/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int t = 1;
	ll N;
	// cin >> t;

	while (t--)
	{
		cin >> N;
		if (Is_Prime(N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	// Generating ALL primes until N
	/*
	cin >> N;
	Linear_Sieve_Of_Eratosthenes(N);
	for (int i{}; i < Prime.size(); i++)
		cout << Prime[i] << " ";
	*/
	/*
	Problems:
	* https://www.spoj.com/problems/PON/
	* https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/B
	* https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/D
	* https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/J
	* https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/H
	* https://codeforces.com/problemset/problem/230/B
	*/
	return 0;
}