#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long Number;
	cin >> Number;

	int Number_of_digits = floor(log10(Number) + 1); // in order to add 1 to number of digits for multiples of 10

	int First_Digit = Number / pow(10, Number_of_digits - 1);
	if (First_Digit % 2)
		cout << "ODD";
	else
		cout << "EVEN";
	return 0;
}
