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
	Nour has N candies, he wants to distribute all N candies to the children.
	What's the maximum number of children who can get candies if Nour gives each child a distinct number of candies.

	If (1 + 2 + 3 + 4 + 5 + ... X) = N, where X is the number of terms
	Then, X * (X + 1) / 2 = N
	i.e., X * (X + 1) = 2 * N
	X² + X - 2 * N = 0
	Using the quadratic formula,
	X = (-1 + sqrtl(1 + 8 * N)) / 2
	If there are N candies, he can give candies to AT MOST floor((-1 + sqrtl(1 + 8 * N)) / 2) distinct children
	Casting the expression ((-1 + sqrtl(1 + 8 * N)) / 2) to (long long) will get the same result EXACTLY as using the floor() function.

	Example:
	If there are 15 candies, He can give candies to AT MOST 5 distinct children (which is the floor of solution to the quadratic equation X² + X - 2 * N = 0)
	i.e., gives the children (1 + 2 + 3 + 4 + 5) candies (here X = 5)
	He won't get the chance to give a candy to a 6th children before he has 21 candies
	Which means, in the interval [16, 20], solving the equation X² + X - 2 * N = 0 will always give a solution S, where  5 < S < 6
	So, the answer will STILL be 5 in that interval which is the floor of solution to the quadratic equation until we reach 21 whose solution will be 6 when floored.
	*/
	ll N;
	cin >> N;
	cout << (ll)(-1 + sqrtl(1 + 8 * N)) / 2;

	return 0;
}