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

	int t, N;
	cin >> t;
	// A method for big Factorials
	while (t--)
	{
		cin >> N;
		int *Fact{new int[10000]{0}};
		Fact[0] = 1;
		int len{1};
		for (int i = 2; i <= N; i++)
		{
			for (int j = 0; j < len; j++)
				Fact[j] *= i;

			for (int j = 0; j < len; j++)
			{
				if (Fact[j] >= 10)
				{
					Fact[j + 1] += Fact[j] / 10; // Carry

					Fact[j] %= 10; // Remainder
				}
			}
			while (Fact[len])
				Fact[len + 1] += Fact[len] / 10, Fact[len++] %= 10;
		}
		for (int j = len - 1; j >= 0; j--)
			cout << Fact[j];
		cout << endl;
		delete[] Fact;
	}
	return 0;
}