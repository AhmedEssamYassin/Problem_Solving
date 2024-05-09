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
	int S, K, cnt = 0;
	cin >> K >> S;

	for (int X = 0; X <= K; X++)
	{
		for (int Y = 0; Y <= K; Y++)
		{
			if (S - X - Y >= 0 && S - X - Y <= K)
				cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}