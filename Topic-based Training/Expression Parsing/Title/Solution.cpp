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
	int N, K;
	string str;
	// cin >> t;
	while (t--)
	{
		cin >> K;
		cin >> str;

		// Min Heap
		priority_queue<char, vector<char>, greater<int>> missing;
		for (int i{}; i < K; i++)
		{
			if (str.find(char(i + 97)) == -1)
				missing.push(i + 97);
		}

		int len = str.length();
		// Counting critical positions
		int countCritical{};
		for (int i{}; i < len / 2; i++)
			countCritical += str[i] == '?' && str[len - i - 1] == '?';
		if (len & 1)
			countCritical += (str[(len - 1) / 2] == '?'); // The middle character

		int countMissing = missing.size();
		int L{}, R = len - 1;
		int diff = countCritical - missing.size(); // Critical positions MUST be greater than or equal to the missing characters
		bool palindrome = true;
		while (L <= R)
		{
			if (str[L] == '?' && str[R] != '?')
				str[L] = str[R];

			else if (str[L] != '?' && str[R] == '?')
				str[R] = str[L];

			else if (str[L] == '?' && str[R] == '?')
			{
				char preferred = 'a'; // Lexicographical minimum choice
				if (diff > 0)
					str[L] = preferred, str[R] = preferred, diff--;

				else
				{
					char C = missing.top();
					missing.pop();
					str[L] = C, str[R] = C;
				}
			}
			else // Both characters exist
			{
				if (str[L] != str[R]) // But NOT equal
				{
					palindrome = false;
					break;
				}
			}
			L++, R--;
		}
		if (palindrome && countCritical >= countMissing)
			cout << str;
		else
			cout << "IMPOSSIBLE";
	}
	return 0;
}