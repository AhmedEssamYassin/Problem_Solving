#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	double x, y;
	cin >> x >> y;
	if (x == 0 && y == 0)
		cout << "Origem";
	else if (y == 0)
		cout << "Eixo X";
	else if (x == 0)
		cout << "Eixo Y";
	if (x > 0 && y > 0)
		cout << "Q1";
	else if (x < 0 && y > 0)
		cout << "Q2";
	else if (x < 0 && y < 0)
		cout << "Q3";
	else if (x > 0 && y < 0)
		cout << "Q4";
	return 0;
}
