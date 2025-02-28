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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		string Keys = "qwertyuiopasdfghjkl;zxcvbnm,./";
		int val;
		char c;
		string word;
		cin >> c >> word;
		if (c == 'R')
			val = -1;
		else
			val = 1;
		for (int i{}; i < word.length(); i++)
		{
			int pos = Keys.find(word[i]);
			word[i] = Keys[pos + val];
		}
		cout << word;
	}
	return 0;
}
