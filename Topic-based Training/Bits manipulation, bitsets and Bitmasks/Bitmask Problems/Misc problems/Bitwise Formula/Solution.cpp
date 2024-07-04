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
		map<string, ll> mp;
		// 2d array of bitmasks, i.e., An array for all N numbers, where each number has 2 possible bitmasks
		bitset<1007> bitmask[5007][2];

		// 2d array of bits, i.e., An array for all M bits, where each bit has 2 possible results
		ll res[1001][2] = {0};
		mp["?"] = 0;
		bitmask[0][0].reset();
		bitmask[0][1].set();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) // Processing N variables
		{
			string variable, eq, exp;
			cin >> variable >> eq >> exp;
			mp[variable] = i; // The order (index) of the variable

			if (isdigit(exp.front())) // If the expression is just a constant value
				bitmask[i][0] = bitmask[i][1] = bitset<1007>(exp);

			else // This variable depends on previous variables
			{
				string op, d;
				cin >> op >> d;
				for (const int &j : {0, 1})
				{
					if (op == "AND")
						bitmask[i][j] = (bitmask[mp[exp]][j] & bitmask[mp[d]][j]);
					if (op == "OR")
						bitmask[i][j] = (bitmask[mp[exp]][j] | bitmask[mp[d]][j]);
					if (op == "XOR")
						bitmask[i][j] = (bitmask[mp[exp]][j] ^ bitmask[mp[d]][j]);
				}
			}

			for (const int &j : {0, 1})
			{
				for (int k = 0; k < M; k++)
					res[k][j] += bitmask[i][j][k];
			}
		}

		for (int i = M - 1; i >= 0; i--)
			cout << (res[i][0] > res[i][1]);
		cout << endl;

		for (int i = M - 1; i >= 0; i--)
			cout << (res[i][0] < res[i][1]);
		cout << endl;
	}
	return 0;
}