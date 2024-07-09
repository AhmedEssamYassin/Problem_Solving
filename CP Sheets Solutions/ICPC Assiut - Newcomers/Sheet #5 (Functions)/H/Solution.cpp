#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void printNTimes(ll N, char C)
{
	while (N--)
		cout << C << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, X;
	cin >> t;
	while (t--)
	{
		char C;
		cin >> N >> C;
		printNTimes(N, C);
		cout << endl;
	}
	return 0;
}