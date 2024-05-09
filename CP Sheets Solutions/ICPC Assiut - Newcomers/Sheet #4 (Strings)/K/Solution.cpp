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
		string S, T;
		cin >> S >> T;
		int i;
		for (i = 0; i < min(S.length(), T.length()); i++)
			cout << S[i] << T[i];
		if (S.length() > T.length())
			cout << S.substr(i); // From i to the end
		else
			cout << T.substr(i); // From i to the end
		cout << endl;
	}
	return 0;
}