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
#endif // !ONLINE_JUDGE
	int t = 1, N, A, B;
	string Code;
	regex Digits_reg("[0-9]+"); // Matches Any string of characters from '0' to '9'
	// cin >> t;
	while (t--)
	{
		cin >> A >> B;
		cin >> Code;
		int pos = Code.find('-');
		if (pos == string::npos) // If NOT found
			return cout << "No", 0;

		string First = Code.substr(0, pos); // substring from 0 to pos should be of size A
		string Last = Code.substr(pos + 1); // substring from (pos + 1) to the end should be of size B
		if (!regex_match(First, Digits_reg) || !regex_match(Last, Digits_reg) || First.size() != A || Last.size() != B)
			return cout << "No", 0;

		// Otherwise
		return cout << "Yes", 0;
	}

	return 0;
}