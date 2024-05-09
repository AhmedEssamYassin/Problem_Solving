#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool predicateFunc(const string &str1, const string &str2)
{
	if (str2.find(str1) != -1)
		return true;
	return false;
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
	ll A, B;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<string> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		sort(vc.begin(), vc.end(), predicateFunc);
		bool flag = true;
		for (int i{1}; i < N; i++)
		{
			if (vc[i].find(vc[i - 1]) == -1)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			return cout << "NO\n", 0;
		for (int i{}; i < N; i++)
			cout << vc[i] << endl;
	}
	return 0;
}