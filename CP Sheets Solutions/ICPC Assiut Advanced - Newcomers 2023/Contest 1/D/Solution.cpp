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
	/*
	A substring of a string is a contiguous subsequence of that string.
	So, string "bca" is a substring of the string "abcabc", but the string "cc" is NOT. Also, the whole string is considered a substring of itself.

	Given a string S what is the minimum number of characters to remove from the string so string S does not contain "TTT" as a substring.

	Get the position of each substring consisting of "TTT", if that substring exists, remove a 'T' of it
	*/
	string S;
	cin >> S;
	int pos;   // To get the position of each substring consisting of "TTT"
	int cnt{}; // To count characters that need to be removed

	// As long as pos is VALID (!= -1), i.e. a substring consisting of "TTT" EXISTS, we remove a 'T' of it
	while ((pos = S.find("TTT")) != string::npos)
	{
		S.erase(S.begin() + pos);
		cnt++;
	}
	cout << cnt;

	return 0;
}