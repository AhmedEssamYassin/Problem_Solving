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
		string key = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
		string original = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		int s = 62;
		string Q;
		cin >> N >> Q;
		if (N == 1)
		{
			for (int i = 0; i < Q.size(); i++)
			{
				int pos = original.find(Q[i]);
				Q[i] = key[pos];
			}
		}
		else
		{
			for (int i = 0; i < Q.size(); i++)
			{
				int pos = key.find(Q[i]);
				Q[i] = original[pos];
			}
		}
		cout << Q;
	}
	return 0;
}