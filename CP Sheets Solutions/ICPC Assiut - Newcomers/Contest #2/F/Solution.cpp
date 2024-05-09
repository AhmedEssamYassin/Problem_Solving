#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int F(uint64_t X)
{
	return __countr_zero(X);
}

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
	int ans = 0;
	uint64_t X;
	while (N--)
	{
		cin >> X;
		ans = max(ans, F(X));
	}
	cout << ans;
	return 0;
}