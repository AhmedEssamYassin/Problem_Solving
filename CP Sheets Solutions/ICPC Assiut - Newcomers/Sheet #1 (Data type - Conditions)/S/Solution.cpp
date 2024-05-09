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

	double Number;
	cin >> Number;
	if (Number >= 0 && Number <= 25)
		cout << "Interval [0,25]";
	else if (Number > 25 && Number <= 50)
		cout << "Interval (25,50]";
	else if (Number > 50 && Number <= 75)
		cout << "Interval (50,75]";
	else if (Number > 75 && Number <= 100)
		cout << "Interval (75,100]";
	else
		cout << "Out of Intervals";
	return 0;
}