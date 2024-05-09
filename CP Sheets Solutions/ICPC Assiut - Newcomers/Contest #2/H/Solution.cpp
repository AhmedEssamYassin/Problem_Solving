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

	long long int N;
	cin >> N;
	// The trick is 0 % (any number) is equal 0
	// So all we need to do is to make (X² + Y²) = 0
	// Solving this equation we get X = 0 and Y = 0
	cout << "0 0";

	return 0;
}