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

	int N, cnt = 1, t;
	cin >> N;
	for (int i = 1; i <= N; i++) // Number of lines
	{
		t = 3;
		while (t--)
		{
			cout << cnt << " ";
			cnt++;
		}
		cout << "PUM" << endl;
		cnt += 1;
	}
	return 0;
}