#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
/*
|-------------|
|Prime numbers|
|-------------|

A prime number is a natural number greater than 1, which is only divisible by 1 and itself
In other words, the prime number N is a positive integer greater than 1 that has exactly two factors, 1 and N

|------------------------------------------|
|Some interesting facts about Prime numbers|
|------------------------------------------|

1. Except for 2, which is the smallest prime number and the only even prime number, all prime numbers are ODD numbers.
2. Every prime number can be represented in form of (6i + 1) or (6i - 1) except the prime numbers 2 and 3, where i is a natural number.
3. Two and Three are the ONLY two consecutive natural numbers that are primes.
4. Every EVEN integer greater than 2 can be expressed as the sum of two primes (Goldbach's conjecture).
5. Fermat's Little Theorem:
	If N is a prime number, then for every a, where 1 <= a < N,
	a^(N-1) % N = 1

|---------------------------|
|Properties of prime numbers|
|---------------------------|

1. Every number greater than 1 can be divided by at least one prime number.
2. Two prime numbers are always co-prime to each other.
3. Each composite number can be factored into prime factors and individually all of these are unique in nature.
(The fundamental theorem of arithmetic)

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

bool isPrime(ll N)
{
	for(ll i=2,i<N;i++)
	{
		if(N%i==0)
		return false;
	}
	return true;
}

Time Complexity: O(N) which is very slow
Can we do better?
---------------------------------------------------------------------------------------------------------------------------------------------------------
Check the divisibility of N by ALL numbers in range  [2, N / 2]

Proof 1:
NO factors > N/2 can exist except N itself
As factors exist on form of pairs, There CANNOT exist a number > N/2 that is, when multiplied by any number > 1
(because 1 is paired with N) gives a result <= N

Proof 2:
There CANNOT possibly be any factors > (N/2) EXCEPT (N) itself

Suppose (N/2) < a <= N and N = a * b
What could b be?
We know that factors exist on form of pairs {a , b}
If b = 1, then a * b = a * 1, so a = N
So, we have a pair {1, N}
This is the only pair that contains a factor of N which is > (N/2)

If b >= 2, then a * b > (N/2) * b
i.e.
a * b > N , So b CANNOT be any positive integer >= 2; thus ( (N/2) < a < N ) is NOT a factor of N

bool isPrime(ll N)
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

For any number N, it can be factored into two factors {a , b}

a and b can't be both greater than sqrt(N) since then the product (a * b) would be greater than sqrt(N)*sqrt(N) = N
So in any factorization of N, at least one of the factors must be smaller than sqrt(N)
and if we CANNOT find any factors less than or equal to sqrt(N), N must be a prime.
Proof:

Assume N = a * b
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
because the numbers [2, sqrt(N)] are way less than the numbers [sqrt(N), N]

bool isPrime(ll N)
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
*/

bool isPrime(ll N)
{
	if (N < 2)
		return false;

	if (N <= 3)
		return true;

	if (N % 2 == 0 or N % 3 == 0)
		return false;

	for (ll i = 5; i * i <= N; i += 6)
	{
		if (N % i == 0 || (N % (i + 2) == 0))
			return false;
	}
	return true;
}
// Time Complexity: O(sqrt(N))
// Can we do better?

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