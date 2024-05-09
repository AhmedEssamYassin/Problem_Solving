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

	int N, number;
	cin >> N;
	int Pos{}, Neg{}, Even{}, Odd{};
	for (int i = 1; i <= N; i++)
	{
		cin >> number;
		if (number > 0)
			Pos++;
		else if (number < 0)
			Neg++;
		if (number % 2 == 0)
			Even++;
		else
			Odd++;
	}
	cout << "Even: " << Even << endl
		 << "Odd: " << Odd << endl
		 << "Positive: " << Pos << endl
		 << "Negative: " << Neg << endl;

	return 0;
}