#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int N, X;
	ll D;
	cin >> N >> D;
	char op;
	while (N--)
	{
		cin >> op >> X;
		if (op == '+')
			D += X;
		else if (op == '-')
		{
			if (D >= X)
				D -= X;
		}
	}
	cout << D;
	return 0;
}