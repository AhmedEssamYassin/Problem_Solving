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

	int Number, First_digit, Second_digit;
	cin >> Number;

	First_digit = Number % 10;
	Number /= 10;
	Second_digit = Number % 10;
	if (First_digit % Second_digit == 0 || Second_digit % First_digit == 0)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}