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
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		/*
		- The length of the password must be equal to N
		- The password should consist only of lowercase Latin letters
		- The number of distinct symbols in the password must be equal to k
		- Any two consecutive symbols in the password must be distinct.
		*/
		int N, k;
		cin >> N >> k;
		string Password = "";
		int cnt{}; // Counts the distinct symbols added to the string
		while (Password.length() < N)
		{
			if (cnt < k)
				Password += char(cnt++ + 97); // Guarantees that we choose a distinct character every time until we reach k distinct characters
			else
				// Concatenates the second to last character to the Password every time so that we guarantee that "any two consecutive symbols in the password are distinct."
				Password += *(Password.end() - 2);
		}
		cout << Password;
	}
	return 0;
}
