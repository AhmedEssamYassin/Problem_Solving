#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool Is_Palindrome(ll N)
{
	// 160
	string num = to_string(N); // num="160"

	reverse(num.begin(), num.end()); // num="061"

	ll rev = stoll(num); // rev=61 and any leading zeros are ignored because it's converted to a decimal number
	cout << rev << endl;
	return (N == rev);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int N;
	cin >> N;
	if (Is_Palindrome(N))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}