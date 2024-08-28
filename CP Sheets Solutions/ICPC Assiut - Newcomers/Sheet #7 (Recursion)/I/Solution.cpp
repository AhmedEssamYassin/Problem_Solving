#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

string vowels("auioe");
ll countVowels(const string &str, int idx)
{
	if (idx == str.length())
		return 0;
	return (vowels.find(str[idx]) != -1) + countVowels(str, idx + 1);
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
	int N;
	// cin >> t;
	while (t--)
	{
		string str;
		getline(cin, str);
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		cout << countVowels(str, 0);
	}
	return 0;
}