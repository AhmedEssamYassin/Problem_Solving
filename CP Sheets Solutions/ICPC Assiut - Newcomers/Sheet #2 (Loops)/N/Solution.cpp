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
	char C;
	int N, Occurrence;
	cin >> C >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Occurrence;
		cout << string(Occurrence, C) << endl;
	}
	return 0;
}