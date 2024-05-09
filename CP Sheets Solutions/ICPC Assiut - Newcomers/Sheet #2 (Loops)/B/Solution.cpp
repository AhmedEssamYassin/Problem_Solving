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

	int N;
	cin >> N;
	if (N == 1)
		cout << -1;
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (i % 2 == 0)
				cout << i << endl;
		}
	}

	return 0;
}