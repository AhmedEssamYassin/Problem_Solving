#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	/*
	Given two positive integers X and Y, you have to do exactly one operation:
	Choose two positive integers a and b, change X to (X / a), and change Y to (Y / b), (a must be a divisor of X, b must be a divisor of Y and gcd(X/a, Y/b) = 1 ).
	Find the minimum value of (a * b)

	The gcd(X, Y) means the greatest common divisor between X and Y

	The gcd(X, Y) means the product of ALL common prime factors between X and Y

	Since we want the minimum possible value of (a * b), where (a >= 1) and (b >= 1)
	Let's Assume a = 1 (minimum possible value of a)
	what is the minimum required value of b in order to make gcd(X, Y/b) = 1 ?
	If we divided Y over the product of ALL common prime factors between X and Y, there won't be any common prime factors so gcd(X, Y) becomes 1
	Actually, we don't know if gcd(X, Y/gcd(X, Y) ) = 1 or gcd(X/gcd(X, Y), Y) = 1
	i.e. we do NOT know whether it's correct to:
	let a = 1 and b = gcd(X, Y)
	or
	let b = 1 and a = gcd(X, Y)
	Example:
	X = 12, Y = 8
	let a = gcd(12, 8), b = 1 --> gcd(12/4, 8) = gcd(3, 8) = 1
	let a = 1, b = gcd(12, 8) --> gcd(12, 8/4) = gcd(12,2) != 1
	but since we are ONLY interested in the result of (a * b), it does NOT matter which is which! The answer will always be gcd(X, Y)
	We deduce that the required (a * b):
	(a * b) = 1 * gcd(X, Y) = gcd(X, Y)
	*/
	int t, X, Y;
	cin >> t;
	while (t--)
	{
		cin >> X >> Y;
		cout << gcd(X, Y) << endl;
	}

	return 0;
}