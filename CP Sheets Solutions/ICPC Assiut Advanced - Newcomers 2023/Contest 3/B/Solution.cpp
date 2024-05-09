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
	int R;
	cin >> R;
	// Required area = Area of Square - Area of Half circle
	// Required area = (2R)² - 0.5 * pi * R² = 4R² - 0.5 * pi * R²
	// Required area = (4 - 0.5 * pi) * R * R
	cout << fixed << setprecision(4) << (4 - 0.5 * 3.14159265358979323846) * R * R;

	return 0;
}