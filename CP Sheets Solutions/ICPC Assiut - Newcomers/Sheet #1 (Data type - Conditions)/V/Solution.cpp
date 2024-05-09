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

	int a, b;
	char Sign;
	cin >> a >> Sign >> b;
	if ((a > b && Sign == '>') || (a < b && Sign == '<') || (a == b && Sign == '='))
		cout << "Right";
	else
		cout << "Wrong";

	return 0;
}