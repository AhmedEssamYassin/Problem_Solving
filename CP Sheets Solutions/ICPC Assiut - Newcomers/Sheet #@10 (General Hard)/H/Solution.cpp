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
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		string Number;
		cin >> Number;
		// For each digit d, (9 - d) < d for each 4 < d <= 9
		// Since Leading zeros are NOT allowed, the interval for the first digit becomes: 4 < d < 9 (because 9 - 9 is 0 which is NOT allowed)
		for (int i{}; i < Number.length(); i++)
		{
			if (i == 0 && Number[i] == 9 + '0')
				continue;
			if (9 - (Number[i] - '0') < (Number[i] - '0'))
				Number[i] = 9 - (Number[i] - '0') + '0';
		}
		cout << Number;
	}
	return 0;
}
