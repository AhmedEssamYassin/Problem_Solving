#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void printPyramid(int N, int space)
{
	if (N == 0)
		return;
	printPyramid(N - 1, space + 1);
	cout << string(space, ' ');
	cout << string(2 * (N - 1) + 1, '*') << endl;
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
		printPyramid(N, 0);
	}
	return 0;
}