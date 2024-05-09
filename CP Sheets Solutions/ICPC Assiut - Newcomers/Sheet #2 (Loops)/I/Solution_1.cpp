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
	int N;
	cin >> N;
	int num = N, digit, rev{};
	while (num)
	{
		digit = num % 10;
		rev = rev * 10 + digit;
		num /= 10;
	}

	cout << rev << endl;
	if (N == rev)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}