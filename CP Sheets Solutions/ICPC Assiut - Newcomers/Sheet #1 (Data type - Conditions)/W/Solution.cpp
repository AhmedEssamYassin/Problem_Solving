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

	int a, b, c;
	char Sign, Equal;
	cin >> a >> Sign >> b >> Equal >> c;

	if (Sign == '+')
	{
		if (a + b == c)
			cout << "Yes";
		else
			cout << a + b;
	}
	else if (Sign == '-')
	{
		if (a - b == c)
			cout << "Yes";
		else
			cout << a - b;
	}
	else if (Sign == '*')
	{
		if (a * b == c)
			cout << "Yes";
		else
			cout << a * b;
	}

	return 0;
}