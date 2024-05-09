#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Is_mirrored(const string &str)
{
	string Mirrored_characters = "AHIMOTUVWXY";
	// Checking if ALL characters are mirrored characters
	for (const char &C : str)
	{
		if (Mirrored_characters.find(C) == string::npos)
			return false;
	}

	// Checking if the string is palindrome
	// Two-pointer technique
	int Left{}, Right = str.length() - 1;
	while (Left <= Right)
	{
		if (str[Left++] != str[Right--])
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
#endif // !ONLINE_JUDGE

	string Input;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> Input;
		if (Is_mirrored(Input))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}