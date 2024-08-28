#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPalindrome(const vector<ll> &arr, int idx)
{
	if (idx > arr.size() / 2)
		return true;
	return (arr[idx] == arr[arr.size() - idx - 1]) && isPalindrome(arr, idx + 1);
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
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		if (isPalindrome(vc, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}