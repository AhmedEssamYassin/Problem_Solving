#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
/*
We can actually use a mathematical expression (O(1)) to check the primality of N which is:
Fermat's Little Theorem: If N is a prime number, then for every a, 1 <= a < N, a^(N-1) % N = 1

bool Is_Prime(ll N)
{
	if(N < 2)
	return false;

	if(N <= 3)
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

Obviously, we take MOD N to the returned value of pow(2, N - 1). So, the final answer will always be [0, N-1]
Thus, we can use Binary Modular exponentiation to calculate pow(2, N-1) so as to avoid intermediate OVER-FLOW

Code:
ll binModExp(ll N, ll power, ll mod)
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
	if(N < 2)
	return false;

	if(N <= 3)
	return true;

	return (binModExp(2, N - 1, N) % N == 1);
}

2. This method does NOT work for all numbers

There are two types of Algorithms:
- Deterministic algorithms: Provides a definitive answer to a question
- Probabilistic algorithms: Provides a high-Probable answer to a question (NOT accurate 100%)

Fermat's Little Theorem to check primality is a probabilistic algorithm
It fails for ALL Carmichael numbers

The Fermat's Little Theorem expression actually executes in O(log N) time because of using binModExp() function

So the Time Complexity of this code is eventually O(log N) which is the fastest of all methods but it fails if the test cases contain Carmichael numbers!
---------------------------------------------------------------------------------------------------------------------------------------------------------
Miller-Rabin Primality test:
----------------------------
For an ODD number N --> (N - 1) Must be EVEN
We can write (N - 1) = d * 2^s where d is ODD
This allows us to factorize the equation of Fermat's little theorem:
a^(N - 1) % N = 1
a^(d * 2^s) % N = 1
a^(d * 2^s) % N - 1 = 0
Use the factorization of a difference between two squares:
(a^(d * 2^(s - 1)) % N - 1)*(a^(d * 2^(s - 1)) % N + 1) = 0
.
.
.
Eventually, 2^s will be 2^0 which is 1
So, after factorization:
(a^(d * 2^(s - 1)) % N - 1)*(a^(d * 2^(s - 1)) % N + 1).....(a^d % N + 1)*(a^d % N  - 1) = 0

If N is prime, then N has to divide one of these factors.
And in the Miller-Rabin primality test we check exactly that statement, which is a more stricter version of the statement of the Fermat's test.
For a base 2 =< a <= (N - 2) we check if either:
a^d % N = 1
or
a^(d * 2^r) % N = -1 for 0 =< r <= s - 1

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
Implementing a function for Modular multiplication causes OVERHEAD and is TOO SLOW compared to the regular arithmetic expression

But Modular multiplication Even when using the property (A * B)%mod = ((A % mod) * (B % mod)) % mod Can cause intermediate OVERFLOW
(A % mod) < mod
(B % mod) < mod
But their multiplication is very likely to be greater than mod and may be greater than the capacity of the whole type causing an OVERFLOW
Solutions to this problem:
1. Modular Binary Multiplication
*/

ll modMult(ll a, ll b, ll mod) //(a * b) % mod
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
/*
-----------------------------------------------------
2. Multiplication via type __int128
To multiply two 32-bit numbers, you need a 64-bit intermediate variable.
And to multiply two 64-bit numbers, you need a 128-bit variable!
Modern 64-bit C++ compilers (except perhaps Microsoft® Visual C++®) have a special type __int128, which allows performing operations on 128-bit numbers.
*/
ll binModExp(__int128 N, ll power, ll mod) //(N^power) % mod
{
	if (N % mod == 0 || !N)
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
	__int128 X = binModExp(a, d, N);
	if (X == 1 || X == N - 1)
		return false; // Not composite

	for (int r = 1; r < s; r++)
	{
		// X = modMult(X, X, N);
		X = ((X % N) * (X % N)) % N;
		if (X == 1 || X == N - 1)
			return false; // Not composite
	}
	return true; // Composite
}
bool Miller_Rabin(ll N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
	// returns true if N is probably a prime, else returns false.
	//(N - 1) = d * 2^s
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
/*
Deterministic version of Miller-Rabin:
--------------------------------------
Miller showed that it is possible to make the algorithm deterministic by only checking all bases <= O((ln N)²).
Bach later gave a concrete bound, it is only necessary to test all bases   a <= 2 ln(N²)

This is still a pretty large number of bases. So, people have invested quite a lot of computation power into finding lower bounds.
It turns out that,
For testing a 32-bit integer, it is only necessary to check the first 4 prime bases: 2, 3, 5 and 7. The smallest composite number that fails this test is  
3215031751 = 151 * 751 * 28351 .

For testing a 64-bit integer, it is enough to check the first 12 prime bases: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37
*/
bool Det_Miller_Rabin(ll N)
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

	for (const ll &a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
	{
		if (N == a)
			return true;
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

bool isPrime(ll N)
{
	if (N < 2)
		return false;
	if (N <= 3)
		return true;
	if (N % 2 == 0 || N % 3 == 0)
		return false;

	// return Miller_Rabin(N);
	return Det_Miller_Rabin(N);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		if (isPrime(N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}