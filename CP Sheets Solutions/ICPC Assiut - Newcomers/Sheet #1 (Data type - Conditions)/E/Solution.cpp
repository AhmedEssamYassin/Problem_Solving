#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	const long double pi = 3.141592653;
	double Radius;
	cin >> Radius;
	cout << fixed << setprecision(9);
	/*
	- Write floating-point values in fixed-point notation.
	- When floatfield is set to fixed, floating-point values are written using fixed-point notation:
	the value is represented with exactly as many digits in the decimal part as specified by the precision field (precision) and with NO exponent part.
	*/
	cout << pi * Radius * Radius;
	return 0;
}
