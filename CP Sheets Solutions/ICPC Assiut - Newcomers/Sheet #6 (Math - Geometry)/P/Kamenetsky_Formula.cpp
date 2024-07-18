#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define M_PI 3.14159265358979323846
#define M_E 2.71828182845904523536

long long countDigits(int N)
{
	// base case
	if (N <= 1)
		return 1;

	// Use Kamenetsky formula to calculate the number of digits
	double x = ((N * log10(N / M_E) + log10(2 * M_PI * N) / 2.0));
	return floor(x) + 1;
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		cout << "Number of digits of " << N << "! is " << countDigits(N);
	}
	return 0;
}