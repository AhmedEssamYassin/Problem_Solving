#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
ceil() function:
----------------
Sometimes we need to compute the division of an integer rounded up (i.e. by ceiling, not by rounding those with remainder r >= 0.5)
For example:
⌈3 / 2.0⌉ = ⌈1.5⌉ = 2
⌈13 / 3.0⌉ = ⌈4.333⌉ = 5

In C++,
If we use ceil(3 / 2), it returns 1, NOT 2 and This is because 3 and 2 are int data types,
so that their quotient (a / b) is in int and the decimal values are discarded (floored).
3 / 2 = 1 so ceil(3 / 2) = ceil(1) = 1
We can simply overcome this by type-casting one of the operands to double data type so that the decimal values are kept during intermediate calculations.
ceil(3/2.0), ceil(3.0/2), ceil(3.0/2.0), ceil(double(3)/2) ... ALL of these return the correct value which is 2

The problem here is that floating-point numbers cannot be reliably represented by computers.
That means, 4.11 is NOT actually represented as 4.11, but something very close to it.
When this "very close to 4.11" number is multiplied by 100 for example, the ceil of the product turns out to be 412 NOT 411

To overcome this problem we use:
*/
ll Ceil(ll a, ll b)
{
	return (a + b - 1) / b;
	// For a,b > 0
}
/*
-------------------------------------------------------------------------------------------------------------------------------------
First Number to be a multiple of Y after X:
-------------------------------------------
Let that number be Z,

In case Y is an integer:
Z = Y * (1 + X / Y), where (X / Y) is the floor of dividing X over Y

In case Y is rational: i.e. Y is on the form a/b
Z = a * Ceil( (1 + X/a) / double(b) ), where (X/a) is the floor of dividing X over a
-------------------------------------------------------------------------------------------------------------------------------------
*/

ll Sum_From_1_To_N(ll N)
{
	ll Sum = N * (N + 1) / 2;
	return Sum;
}

ll Sum_Of_ODD(ll N)
{
	ll Y = Ceil(N, 2);
	ll Sum = Y * Y;
	return Sum;
}

ll Sum_Of_EVEN(ll N)
{
	ll Y = (N / 2);
	ll Sum = Y * Y + Y;
	return Sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	Sum of ALL numbers from 1 to N:
	Or: Sum of the first N natural numbers:
	---------------------------------------
	Series: 1 2 3 4 5 6 ... N

	The General Term: G.T = X where 1 =< X <= N
	Σ(X) from 1 to N = N *(N + 1) / 2
	-------------------------------------------------------------------------------------------------------------------------------------
	Sum of all ODD numbers from 1 to N:
	-----------------------------------
	Series: 1 3 5 7 9 ... (N)
	There are Ceil(N, 2) ODD numbers in range [1, N]
	Let Y = Ceil(N, 2)
	Series: 1 3 5 7 9 ... (2 * Y - 1)

	The General Term: G.T = (2 * X - 1) where 1 =< X <= Y
	Sum of the first Y ODD numbers:
	Σ(2 * X - 1) from 1 to Y = 2 * Y * (Y + 1) / 2 - Y = Y² + Y - Y = Y²
	-------------------------------------------------------------------------------------------------------------------------------------
	Sum of all EVEN numbers from 1 to N:
	-----------------------------------
	Series: 2 4 6 8 ... (N)
	There are (N / 2) EVEN numbers in range [1, N]
	Let Y = floor(N / 2.0) which is Y = (N / 2)
	Series: 2 4 6 8 ... (2 * Y)

	The General Term: G.T = (2 * X) where 1 =< X <= Y
	Sum of the first Y EVEN numbers
	Σ(2 * X) from 1 to Y = 2 * Y * (Y + 1) / 2 = Y² + Y
	-------------------------------------------------------------------------------------------------------------------------------------
	Sum of numbers in range [L, R]:
	-------------------------------
	Σ(G.T) [L, R] =( Σ(G.T) [1, R] ) - ( Σ(G.T) [1, L-1] )

	1. Sum of ALL numbers from L to R:
	----------------------------------
	The General Term: G.T = X where L =< X <= R
	Σ(X) from L to R = R * (R + 1) / 2 - L * (L - 1) / 2

	2. Sum of all ODD numbers from L to R:
	--------------------------------------
	The General Term: G.T = (2 * X - 1) where L =< X <= R
	Y = Ceil(R, 2) , K = Ceil((L - 1),2)
	Σ(2 * X - 1) from L to R = Y² - K²

	3. Sum of all EVEN numbers from L to R:
	---------------------------------------
	The General Term: G.T = (2 * X) where L =< X <= R
	Y = (R / 2) , K = ((L - 1) / 2)
	Σ(2 * X) from L to R = (Y² + Y) - (K² + K)
	*/
	//-------------------------------------------------------------------------------------------------------------------------------------

	ll L, R;
	cin >> L >> R;
	if (L > R)
		swap(L, R); // Now L <= R
	cout << Sum_From_1_To_N(R) - Sum_From_1_To_N(L - 1) << endl;
	cout << Sum_Of_EVEN(R) - Sum_Of_EVEN(L - 1) << endl;
	cout << Sum_Of_ODD(R) - Sum_Of_ODD(L - 1);

	return 0;
}