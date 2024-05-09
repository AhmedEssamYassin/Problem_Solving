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
	int a, b;
	cin >> a >> b;
	/*
	Peter Parker had worked hard throughout his digital logic course, but when he was asked to implement a 32-bit adder for a machine,
	he made a mistake in the design part. After tracing the design for half an hour, he found his flaw!! He was doing bitwise addition, but the carry bit is always zero.

	The ONLY bitwise operator which is able to do so is the XOR operator
	*/

	// You must put parentheses to force higher precedence to the XOR operator
	// Otherwise, it yields an error because it evaluates the left-shift operator first
	cout << (a ^ b);
	return 0;
}