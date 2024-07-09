#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPalindrome(const ll &N)
{
	ll rev = 0;

	ll k = N;
	while (k)
	{
		rev = (rev << 1) | (k & 1);
		k >>= 1; // drop last bit
	}

	return (N == rev);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		if ((N & 1) && isPalindrome(N))
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}