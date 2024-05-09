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
		char str[1000001];
		cin.getline(str, 1000001, '\n');
		char *ch_ptr = strtok(str, " !.?,"); // Tokenizing the string by the separators ' ', '!', '.', '?', and ','
		int cnt{};
		while (ch_ptr != nullptr)
		{
			cnt++;
			ch_ptr = strtok(nullptr, " !.?,"); // Get next token
		}
		cout << cnt;
	}
	return 0;
}