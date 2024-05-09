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
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == ',')
				cout << " ";
			else
			{
				if (isupper(S[i]))
					cout << (char)tolower(S[i]);
				else
					cout << (char)toupper(S[i]);
			}
		}
	}
	return 0;
}