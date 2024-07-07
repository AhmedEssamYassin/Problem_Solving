#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPalindrome(string str)
{
	string rev = str;
	reverse(rev.begin(), rev.end());
	return (str == rev);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	At each bit, we need to choose the dominant bit in ALL given numbers
	i.e., we need to choose the bit to be either 1 (set) or 0 (cleared) based on the higher occurrence
	We can count the ones appeared at each bit position, then the count of zero will be (N - cnt[1])
	*/
	int t = 1;
	ll N, L, X;
	cin >> t;
	while (t--)
	{
		cin >> N >> L;
		int *arr{new int[L]{0}};

		for (int c{}; c < N; c++)
		{
			cin >> X;
			for (int i{}; i < L; i++, X >>= 1)
				arr[i] += (X & 1);
		}
		int ans{};
		for (int i{}; i < L; i++)
		{
			if (N - arr[i] < arr[i])
				ans |= (1 << i);
		}
		cout << ans << endl;
	}
	return 0;
}