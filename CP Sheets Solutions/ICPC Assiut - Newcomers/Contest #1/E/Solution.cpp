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
	Assuming that number of EVEN numbers in an interval is denoted as a and number of ODD numbers is denoted as b
	In any arbitrary interval there are ONLY three possibilities:
	1. a = b + 1
	2. b = a + 1
	3. a = b
	4. and basically, neither a nor b can be zero
	*/
	if (((a == b + 1) || (b == a + 1) || (a == b)) && (a != 0 || b != 0))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}