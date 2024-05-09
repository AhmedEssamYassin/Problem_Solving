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
	long long int a, b, k;
	cin >> a >> b >> k;
	if (a % k == 0 && b % k == 0)
		cout << "Both";
	else if (a % k == 0 && b % k != 0)
		cout << "Memo";
	else if (a % k != 0 && b % k == 0)
		cout << "Momo";
	else
		cout << "No One";
	return 0;
}