#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void print(int N)
{
	if (N == 0)
		return;
	return cout << "I love Recursion" << "\n", print(N - 1);
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
	// cin >> t;
	while (t--)
	{
		cin >> N; // Number of lines
		print(N);
	}
	return 0;
}