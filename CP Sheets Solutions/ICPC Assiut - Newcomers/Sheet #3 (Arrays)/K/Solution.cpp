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
	int t = 1, N;
	// cin >> t;
	while (t--)
	{
		ll Sum{};
		char Digit;
		cin >> N;
		while (N--)
		{
			cin >> Digit;
			Sum += (Digit - '0'); // Converting a character to the corresponding digit
		}
		cout << Sum;
	}

	return 0;
}