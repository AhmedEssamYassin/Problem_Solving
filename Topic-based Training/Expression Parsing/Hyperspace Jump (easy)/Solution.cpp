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
	int N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		string str;
		map<double, int> mp;
		vector<double> coordinate(N);
		for (int i{}; i < N; i++)
		{
			//(5+1)/7
			double a, b, c;
			cin >> str;
			int plusPos = str.find('+');
			int close = str.find(')', plusPos + 1);
			a = stod(str.substr(1, plusPos - 1));
			b = stod(str.substr(plusPos + 1, close - plusPos));
			c = stod(str.substr(close + 2)); // to the end
			coordinate[i] = (a + b) / c;
			mp[coordinate[i]]++;
		}
		for (int i{}; i < N; i++)
			cout << mp[coordinate[i]] << " ";
	}
	return 0;
}