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
	char C;
	// cin >> t;
	// 1,2,3,1,1,2,6,6,2
	int freq[10009] = {0};
	while (1)
	{
		if (cin.peek() == '\n' || cin.peek() == EOF)
			break;

		N = 0;
		while (cin.peek() != ',' && cin.peek() != '\n' && cin.peek() != EOF)
		{
			cin >> C;
			N = N * 10 + (C - '0');
		}
		freq[N]++;
		if (cin.peek() == '\n' || cin.peek() == EOF)
			break;
		cin.ignore(256, ',');
	}
	int L{-1}, R{-1};
	bool first = true;
	for (int i{1}; i < 10001; i++)
	{
		if (freq[i])
		{
			if (~L) // L != -1
				R = i;
			else
				L = i;
		}
		else
		{
			if (L != -1)
			{
				if (not first)
					cout << ',';
				if (R != -1)
					cout << L << '-' << R;
				else
					cout << L;
				first = false;
				L = -1, R = -1;
			}
		}
	}
	return 0;
}