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
	vector<int> Divisors;
	int N;
	cin >> N;
	for (ll i{1}; i * i <= N; i++)
	{
		if (N % i == 0)
		{
			if (i * i == N) // i = sqrt(N), then it's one repeated factor
				Divisors.push_back(i);
			else // It's NOT sqrt(N), i.e., they are two distinct divisors
				Divisors.push_back(i), Divisors.push_back(N / i);
		}
	}
	sort(Divisors.begin(), Divisors.end());
	for (const int divisor : Divisors)
		cout << divisor << endl;
	return 0;
}