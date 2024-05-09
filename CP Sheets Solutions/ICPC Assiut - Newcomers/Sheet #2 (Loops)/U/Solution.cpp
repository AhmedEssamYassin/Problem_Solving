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
	int N, a, b, quo, Sub_sum, Sum = 0;
	cin >> N >> a >> b;

	for (int i = 1; i <= N; i++)
	{

		quo = i, Sub_sum = 0;
		while (quo)
		{
			Sub_sum += (quo % 10);
			quo /= 10;
		}
		if (Sub_sum >= a && Sub_sum <= b) // In interval [a, b]
			Sum += i;
	}

	cout << Sum;
	return 0;
}