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
#endif // !ONLINE_JUDGE

	ll id, row, col;
	cin >> id;

	row = id / 4; // Because every row has the capacity of 4 seats

	// Each row is EXACTLY 4 seats. i.e. column's value is in the range [0, 3] (which is modulo 4) because it's 0-indexed

	// Seats at EVEN rows are numbered from left to right
	// Seats at ODD rows are numbered from right to left

	if (row & 1) // ODD
		col = 3 - (id % 4);
	// Because the numbering of ODD rows goes from right to left

	else // EVEN
		col = id % 4;
	// Because the numbering of EVEN rows goes from left to right

	cout << row << " " << col;
	return 0;
}