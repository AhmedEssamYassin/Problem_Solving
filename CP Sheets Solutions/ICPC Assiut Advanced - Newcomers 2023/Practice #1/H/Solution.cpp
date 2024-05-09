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
	int t, N;
	cin >> t;
	string str;
	/*
	- A string S1 is a prefix of a string S2 iff S1 can be obtained from S2 by deletion of several (possibly, zero or all) characters from the end.
	- A string S1 is a suffix of a string S2 iff S1 can be obtained from S2 by deletion of several (possibly, zero or all) characters from the beginning.
	- The input contains (2 * N − 2) strings. All are NON-empty prefixes and suffixes of S, NOT including S itself, in arbitrary order.

	That means there will exist two strings of length (N - 1) representing S without the last character and S without the first character
	The string: [0][1][2][3][4][5]...[N-2][N-1]
	The prefix: [0][1][2][3][4][5]...[N-2]
	The suffix:    [1][2][3][4][5]...[N-2][N-1]
	If the prefix is the reverse of the suffix, the string is a palindrome
	*/
	while (t--)
	{
		vector<string> Vec;
		cin >> N;
		int k = 2 * N - 2;
		while (k--)
		{
			cin >> str;
			if (str.length() == N - 1)
				Vec.push_back(str);
		}
		reverse(Vec[0].begin(), Vec[0].end());

		if (Vec[0] == Vec[1])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}