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
	int N;
	// cin >> t;
	while (t--)
	{
		string S;
		cin >> S;
		int arr[26] = {0}; // To count occurrences of all lowercase latin characters
		for (int i{}; i < S.size(); i++)
			arr[S[i] - 97]++; // index 0 stores the frequency of 'a', index 1 stores the frequency of 'b',... etc.

		for (int i{}; i < 26; i++)
		{
			if (arr[i]) // If the frequency is NOT 0, it means that the character has appeared in the given string
				cout << char(i + 97) << " : " << arr[i] << endl;
		}
	}
	return 0;
}