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
#endif // !ONLINE_JUDGE

	int Q, X;
	cin >> Q;
	set<int> St;
	// Sets store Unique, in-ascending-order sorted elements
	// set member functions find(), lower_bound() and upper_bound() are way faster than the NON-member functions (std functions)

	string Query;
	while (Q--)
	{
		cin >> Query >> X;
		if (Query == "insert")
			St.insert(X);

		else if (Query == "find")
		{
			if (St.find(X) != St.end())
				cout << "found\n";
			else
				cout << "not found\n";
		}

		else if (Query == "lower_bound")
		{
			auto it = St.lower_bound(X);
			if (it != St.end())
				cout << *it << endl;
			else
				cout << -1 << endl;
		}

		else if (Query == "upper_bound")
		{
			auto it = St.upper_bound(X);
			if (it != St.end())
				cout << *it << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}