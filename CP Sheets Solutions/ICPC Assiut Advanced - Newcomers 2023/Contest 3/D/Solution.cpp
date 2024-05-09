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
	int N;
	ll Number;
	int Max_ans = INT_MIN;
	cin >> N;
	while (N--)
	{
		cin >> Number;
		int cnt{};
		while (Number % 2 == 0)
		{
			cnt++;
			Number /= 2;
		}
		Max_ans = max(Max_ans, cnt);
	}
	cout << Max_ans;
	return 0;
}