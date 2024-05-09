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
	long long int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + b - c == d) || (a + b * c == d) || (a - b + c == d) || (a - b * c == d) || (a * b + c == d) || (a * b - c == d))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}