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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> arr(N);
		for (int i{}; i < N; i++)
			cin >> arr[i];
		/*
		After making all of the array elements equal to some 'x', its product will be x^N
		So, x^N MUST be greater than (arr[i] * arr[i+1] *..... * arr[N - 1])
		x^N > (arr[i] * arr[i+1] *.....* arr[N - 1])
		Taking Log to both sides: N * Log(x) > Log(arr[i] * arr[i+1] * .....* arr[N - 1])
		since Log(a * b) = Log(a) + Log(b), we conclude that:
		N * Log(x) > Log(arr[i]) + Log(arr[i + 1]) +.....+ Log(arr[N - 1])
		let's call Log(arr[i]) + Log(arr[i + 1]) +.....+ Log(arr[N - 1]) = Sum
		Our problem is to find the smallest x > 10^(Sum / N)
		*/
		long double Sum{};
		for (int i{}; i < N; i++)
			Sum += log10(arr[i]);
		long double Val = pow(10, Sum / N);
		ll l{1}, r{20000000000LL};
		ll Ans;
		while (l <= r)
		{
			ll mid = l + (r - l) / 2;
			if (mid > Val)
			{
				Ans = mid;
				r = mid - 1; // Search for a better solution
			}
			else
				l = mid + 1;
		}
		cout << Ans;
	}
	return 0;
}
