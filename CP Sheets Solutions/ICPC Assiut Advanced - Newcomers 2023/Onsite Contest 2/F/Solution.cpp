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
	You have a wire of length L meters, how many rectangles of length h and width w can be created from this wire?
	The perimeter of the rectangle is 2*(h + w)
	The problem is to find how many 2*(h + w) can we make from L? which is obtained directly by the integer division: L / (2 * (h + w))
	*/
	ll L, h, w;
	cin >> L >> h >> w;
	cout << L / (2 * (h + w));

	return 0;
}