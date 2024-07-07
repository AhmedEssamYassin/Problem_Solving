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
	// Just try all subsequences and take the Lexicographically largest one
	int t = 1, N;
	string str;
	// cin >> t;
	while (t--)
	{
		cin >> str;
		string ans = "";
		for (int i{}; i < (1 << str.length()); i++)
		{
			string t = "";
			for (int j{}; j < str.length(); j++)
			{
				if (i & (1 << j))
					t += str[j];
			}
			if (isPalindrome(t))
			{
				if (t > ans)
					ans = t;
			}
		}
		cout << ans << endl;
	}
	return 0;
}