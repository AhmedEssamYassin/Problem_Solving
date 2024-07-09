#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

template <typename T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
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
	ll N, x, y;
	// cin >> t;
	while (t--)
	{
		cin >> x >> y;
		Swap(x, y);
		cout << x << " " << y;
	}
	return 0;
}