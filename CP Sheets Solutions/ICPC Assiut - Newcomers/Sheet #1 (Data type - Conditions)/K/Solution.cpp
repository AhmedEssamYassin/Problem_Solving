#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int a, b, c;
	cin >> a >> b >> c;
	cout << min({a, b, c}) << " ";
	cout << max({a, b, c});
	return 0;
}
