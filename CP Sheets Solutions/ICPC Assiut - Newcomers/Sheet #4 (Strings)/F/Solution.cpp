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
	cin >> t;
	while (t--)
	{
		string S;
		cin >> S;
		if (S.length() > 10)
			cout << S.front() << S.length() - 2 << S.back() << endl;
		else
			cout << S << endl;
	}
	return 0;
}