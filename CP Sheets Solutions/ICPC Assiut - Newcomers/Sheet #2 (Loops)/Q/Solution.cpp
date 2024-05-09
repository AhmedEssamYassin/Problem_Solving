#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void Print_digits(ll N)
{
	if (N == 0)
		return;

	cout << (N % 10) << " ";
	Print_digits(N / 10);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int t, N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		if (N == 0)
			cout << 0;
		else
			Print_digits(N);
		cout << endl;
	}
	return 0;
}