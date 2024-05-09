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
	int N;
	cin >> N;
	double ODD, Probability;
	// If N is ODD,number of ODD numbers is greater than number of EVEN numbers by 1 (which is the number N itself)
	if (N & 1)
		ODD = N / 2 + 1;

	// Whereas if N is EVEN,number of ODD numbers is equal to number of EVEN numbers
	else // N is EVEN
		ODD = N / 2;

	Probability = ODD / N;
	cout << fixed << setprecision(6) << Probability;
	return 0;
}