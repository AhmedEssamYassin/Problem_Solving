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
	// cin >> t;
	while (t--)
	{
		int x, T;
		cin >> T;
		/*
		If T = 1 then Convert N from base x representation to decimal
		If T = 2 then Convert N from decimal to base x representation
		As 2 =< x <= 35 may exceed base 10 then the number N can contain digits from 0 to 9 and from A to Z
		Such that Value of A = 10, value of B = 11 and so on.
		*/
		ll num{};
		if (T == 1)
		{
			string N;
			cin >> N >> x;
			reverse(N.begin(), N.end());
			for (int i = 0; i < N.size(); i++)
			{
				if (N[i] != '0')
				{
					if (isdigit(N[i]))
					{
						int L = N[i] - '0'; // converts the character digit to the corresponding number
						while (L--)
							num += pow(x, i);
					}
					else
					{
						int L = N[i] - 'A' + 10;
						while (L--)
							num += pow(x, i);
					}
				}
			}
			cout << num;
		}

		else if (T == 2)
		{
			ll N;
			cin >> N >> x;
			vector<int> v;
			while (N != 0)
			{
				int L = N % x;
				if (L < 10)
					v.push_back(N % x);
				else
					v.push_back(L + 'A' - 10); // stores the integer ASCII code value of the character 'A','B',etc.
				N /= x;
			}
			reverse(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
			{
				if (isalpha(v[i])) // represents the integer ASCII code value of the character 'A','B',etc.
					cout << char(v[i]);
				else
					cout << v[i];
			}
		}
	}
	return 0;
}