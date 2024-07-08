#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	Initially, the box is empty.
	Each morning, you can put any number of bacteria into the box. And each night, every bacterium in the box will split into TWO bacteria.
	You hope to see EXACTLY X bacteria in the box at some moment.

	What is the minimum number of bacteria you need to put into the box across those days?

	Assume we put one bacterium at the first morning, as bacteria split into TWO bacteria it will be as follows: 2, 4, 8, 16, 32 ... etc
	So, obviously, if X is Power_of_two, we just need to put ONLY 1 bacterium
	Otherwise, We need to add some other bacteria in some other days to see EXACTLY X at some moment.
	NOTE:
	-----
	The earlier we put a bacterium, the greater it will produce and vice versa
	i.e., The latter we put a bacterium, the less it will produce

	More formally, for EVERY Power_of_two in in position i in binary of X
	We need to put 1 bacterium on the (N + 1 - i)th day

	Example:
	25 in binary is 11001
	For 2^0 we need 1 bacterium
	For 2^3 we need another 1 bacterium
	For 2^4 we need another 1 bacterium
	i.e., We put 1 bacterium on the first day morning
	1st day night, it will split into 2 bacteria
	2nd day morning, we add another bacterium
	2nd day night, they will split into 4 + 2 bacteria
	2rd day night, they split into 8 + 4
	4th day night, they split into 16 + 8
	5th day morning, we add another bacterium, we get EXACTLY (16 + 8 + 1 = 25)

	Approach:
	Write down X into its binary form. e.g., 20 is 10100 in binary or 25 is 11001 ... etc.
	If the ith least significant bit is 1 and X contains N bits, we put one bacterium into this box in the morning of (N + 1 - i)th day.
	Then at the noon of the N-th day, the box will contain X bacteria.
	So the answer is the number of ones in the binary form of X

	We can easily get that using __popcount() or the GCC __builtin_popcount()
	*/
	int t = 1;
	ll X;
	// cin >> t;
	while (t--)
	{
		cin >> X;
		cout << __popcount(X);
	}
	return 0;
}