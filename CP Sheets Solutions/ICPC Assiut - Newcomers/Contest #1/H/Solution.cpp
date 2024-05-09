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

	long double n, k, a, Expr;
	cin >> n >> k >> a;
	Expr = (n * k) / (a);
	long long int_part = Expr;

	if (Expr - int_part == 0)
	{
		if ((Expr >= -2147483647 && Expr <= 2147483647))
			cout << "int";
		else
			cout << "long long";
	}
	else
		cout << "double";

	return 0;
}