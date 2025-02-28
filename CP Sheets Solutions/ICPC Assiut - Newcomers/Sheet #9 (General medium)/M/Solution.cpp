#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPalindrome(const string &s)
{
	if (s.size() == 1)
		return true;

	int j = s.length() - 1;
	for (int i{}; i < s.length(); i++)
	{
		if (s[i] != s[j--])
			return false;
	}
	return true;
}
bool isAllTheSame(const string &s)
{
	for (int i{1}; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
			return false;
	}
	return true;
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
		string str;
		cin >> str;
		if (isAllTheSame(str))
			return cout << 0, 0;
		if (isPalindrome(str))
			cout << str.length() - 1;
		else
			cout << str.length();
	}
	return 0;
}
