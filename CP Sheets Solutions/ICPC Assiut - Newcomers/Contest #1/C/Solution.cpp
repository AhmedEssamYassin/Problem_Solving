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
	char C, Next_C;
	cin >> C;
	if (C == 122) // If C = 'z'
		Next_C = 97;

	else
		Next_C = C + 1;

	cout << Next_C;
	return 0;
}