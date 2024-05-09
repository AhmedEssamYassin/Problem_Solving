#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long int Number;
	cin >> Number;

	int quotient, digit;
	quotient = Number;
	while (quotient)
	{
		digit = quotient % 10;
		quotient /= 10;
	}
	if (digit % 2 == 0)
		cout << "EVEN";
	else
		cout << "ODD";
	return 0;
}
