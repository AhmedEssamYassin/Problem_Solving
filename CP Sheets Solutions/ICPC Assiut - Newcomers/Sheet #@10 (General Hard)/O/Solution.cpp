#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll modBinExp(ll N, ll power, ll mod)
{
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

bool isPrime(ll N)
{
	if (N < 2)
		return false;
	if (N < 4)
		return true;
	if (N % 2 == 0 || N % 3 == 0)
		return false;

	for (ll i = 5; i * i <= N; i += 6)
	{
		if (N % i == 0 || (N % (i + 2) == 0))
			return false;
	}
	return true;
}
/*
|----------|
|Last Digit|
|----------|

The last k digits of a multiplication of N numbers:
---------------------------------------------------
If A, B, C, D, E, F, ...etc are multiplied

The last k digits of their multiplication is The last k digits of the multiplication of their last k digits
i.e. The last k digits of A * B * C * D * E * F * ...etc is calculated as: ((A % 10^k) * (B % 10^k) * (C % 10^k) * (D % 10^k) *...etc) % 10^k

NOTE:
The built-in pow() function returns a NON-integer value (double)
which is forbidden to use as an operand to the modular arithmetic operator
So, we must implement a user-defined function to calculate the power and return a long long int
Or we can easily use data type casting with the built-in pow() function

Edge cases to handle:
---------------------
1. If the last k digits of one of the numbers are zeros, the output will be 0 (which is NOT correct, it should be k zeros)
Example:
The last 4 digits in the multiplication (454651 * 100 * 121000):
(454651 * 100 * 121000) = 5501277100000
Correct Output should be: 0000
actual output: 0
---------------------
2. If the answer has leading zeros it will be ignored as it's calculated as a number
Example:
The last 3 digits in the multiplication (2132 * 542 * 421 * 32154 * 515556264546):
(2132 * 542 * 421 * 32154 * 515556264546) = 8064541080062802597746016
Correct answer should be: 016
actual output: 16

We can solve BOTH edge cases using setw() and setfill()
- setw(k) : sets the field width or number of characters that are to be displayed before a particular field to int type k
As per the width set, the output is printed after replacing spaces from right to left.

- setfill(C) : used to fill the stream with char type C specified as a parameter.
i.e.
cout << setw(k) << setfill('0') << Ans;

Code:
-----
int k, N;
ll num;
cin >> k >> N;
ll Ans{1};
ll mod = pow(10, k);
while(N--)
{
	cin >> num;
	Ans = (Ans % mod * num % mod) % mod;
}

cout << setw(k) << setfill('0') << Ans;
----------------------------------------------------------------------------------------------------------------------------------------
The last k digits of N^X (a multiplication of N * N * N ... (X times)):
---------------------------------------------------------------------
Similarly, the last k digits of the multiplication of N * N * N ... (X times) is The last k digits of the multiplication of their last k digits
i.e. The last k digits of N * N * N * N * ... (X times) is calculated as: ((N % 10^k) * (N % 10^k) * (N % 10^k) * ... (X times)) % 10^k
which, by definition, is the modular exponentiation: modBinExp(N, X, 10^k);

Code:
-----
int k;
ll N, X;
cin >> k >> N >> X;
ll mod = pow(10, k);
ll Ans = modBinExp(N, X, mod);

cout << setw(k) << setfill('0') << Ans;
----------------------------------------------------------------------------------------------------------------------------------------
For k = 1 :
The last digit of N^X:
---------------------------------------------------
The last digit of N^X is the last digit of (the last digit of N)^X
let the last digit of N be d, So the The last digit of N^X is (d^X) % 10
We can calculate (d^X) % 10 using modular exponentiation as explained in the previous case
but since d is a single-digit number, we can make use of a good property of d^X which is the "Cyclicity of numbers"

Cyclicity Of Numbers:
The cyclicity of any number is focused on its unit digit mainly (its last digit).
Every unit digit has its own repetitive pattern when raised to any power.
This concept is of tremendous use while solving aptitude problems.
The concept of cyclicity of numbers can be learned by figuring out the unit digits of all the single-digit numbers from 0 to 9 when raised to certain powers.
These numbers can be broadly classified and listed as follows:

Number		d^1		d^2		d^3		d^4		Cyclicity
	0			0		0		0		0			1
	1			1		1		1		1			1
	2			2		4		8		16			4
	3			3		9		27		81			4
	4			4		16		64		256			2
	5			5		25		125		625			1
	6			6		36		216		1296		1
	7			7		49		343		2401		4
	8			8		64		512		4096		4
	9			9		81		729		6561		2

Let's define a function that gets the last digit of a number (N^X),
*/
int Get_Last_Digit(ll N, ll X)
{
	if (X == 0)
		return 1; // N^0 = 1

	int d = N % 10; // Last digit of N
	int Power;

	// If d is of cyclicity 1
	if (d == 1 or d == 5 or d == 6)
		return d;

	// If d is of cyclicity 2
	if (d == 4 or d == 9)
		Power = X % 2 == 0 ? 2 : X % 2; // Because if (X % 2 == 0), Power should be 2 or an equivalent power to 2

	// If d is of cyclicity 4
	if (d == 2 or d == 3 or d == 7 or d == 8)
		Power = X % 4 == 0 ? 4 : X % 4; // Because if (X % 4 == 0), Power should be 4 or an equivalent power to 4

	return modBinExp(d, Power, 10); // returns (N^Power)%10 which is the last digit of (d^X)
}
/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Counting numbers with same first and last digits in an interval [L, R]
---------------------------------------------------------------------
Example: 121	33	 454 ... and so on
- First, Let's consider Counting numbers with same first and last digits in an interval [1,X]
- Let the answer of each query be Q,
We can observe that in each ten-number span we have only one number which has the given property.
Except Q[1, 10] which has 9 numbers because (all one-digit numbers) DO have the same first and last digit.
So, it's obvious that the answer this query is counting the number of ten-number spans in X
and take into consideration that one of the spans contains 9 numbers satisfying this property.
How to count ten-number spans? or let's paraphrase our question... How many 10's in X?
This is by definition the integer division of X/10
Then, we need to add 9 to X/10 because Q[1, 10] = 9 NOT 1 as all other ten-number spans

Edge cases to handle:
1. if(X < 10) the answer to the query Q[1, X] is directly X because (all one-digit numbers) DO have the same first and last digit.

2. if(Last_Digit < First_Digit), then 1 should be subtracted from the answer in order to discard the last ten-span number because that number is out of range.
Examples:
64  --> (4 < 6) so 66 is out of range
452 --> (2 < 4) so 454 is out of range

Back to the query Q[L, R]:
Q[L, R] = Q[1,R] - Q[1, L - 1]

To calculate Q[1,X]
*/
ll Q(ll X)
{
	int First_Digit, Last_Digit;
	if (X < 10)
		return X;

	ll Ans = (X / 10) + 9;

	First_Digit = X / (long long)pow(10, floor(log10(X) + 1) - 1);
	Last_Digit = X % 10;
	if (Last_Digit < First_Digit)
		Ans--;

	return Ans;
}

ll Numbers_in_range(ll L, ll R)
{
	// Calculate Q[1, R]
	ll Query_to_end = Q(R);

	// Calculate Q[1, L - 1]
	ll Query_from_start = Q(L - 1);

	return (Query_to_end - Query_from_start);
}
/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
Back to our question "Help Koko":
---------------------
Let our number be N, and its last digit is d
if Q = 1
------
We should check if the number is prime or not,
- If it's not a prime number then we should print −1
- If it's a prime number we should multiply it by 5^X then multiply it by 3^X and print the last digit of the result.

5^X is of Cyclicity = 1, i.e. Get_Last_Digit(5^X) = 5 whatever the value of X is
3^X is of Cyclicity = 4, i.e. Get_Last_Digit(3^X) = (3^(X%4))%10

Since the last digit of the multiplication of an (EVEN number * (a number whose d = 5)) is 0
and
Since the last digit of the multiplication of an (ODD number * (a number whose d = 5)) is 5
we deduce that:
-The last digit of (N * 5^X) is 0 if (N is EVEN)
-The last digit of (N * 5^X) is 5 if (N is ODD)

Since the possible last digits of 3^X are {3, 9, 7, 1} are all ODD numbers
The last digit of (N * 5^X) * 3^X is NOT dependent on 3^X
because any number * 0 is 0
and the last digit of the multiplication of an ODD number * 5 is 5
So multiplying (N * 5^X) * 3^X doesn't change the last digit of (N * 5^X)
-------------------------------------------------------------------------
if Q = 2
------
We should multiply the number by 2^X then multiply it by 5^X and print the last digit of the result.
Since the last digit of (2^X) is element of {2, 4, 6, 8}, i.e. its last digit is always an EVEN number,
If we multiply (N * 2^X) the last digit will be also an EVEN number
hence, the result of multiplying (N * 2^X) * 5^X MUST have a last digit = 0
because the last digit of the multiplication of an (EVEN number * (a number whose d = 5)) is 0
*/

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
		int N, X;
		int Q;
		cin >> N >> X;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		for (int i{}; i < N; i++)
		{
			cin >> Q;
			if (Q == 1)
			{
				if (!isPrime(arr[i])) // If NOT prime
					cout << -1 << " ";
				else
				{
					if (arr[i] % 2 == 0)
						cout << 0 << " ";
					else
						cout << 5 << " ";
				}
			}
			else if (Q == 2)
			{
				cout << 0 << " ";
			}
		}
		delete[] arr;
	}
	return 0;
}
