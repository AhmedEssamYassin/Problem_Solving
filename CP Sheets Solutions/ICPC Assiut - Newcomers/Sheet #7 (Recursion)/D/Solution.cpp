#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void printDigits(long long N)
{
	if (N < 10)
	{
		cout << N << " ";
		return;
	}
	printDigits(N / 10);
	cout << N % 10 << " ";
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
	int N;
	cin >> t;
	while (t--)
	{
		cin >> N; // Number of lines
		printDigits(N);
		cout << endl;
	}
	return 0;
}