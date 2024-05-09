#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y;
	cin >> x >> y;
	cout << x << " + " << y << " = " << x + y << endl;
	cout << x << " * " << y << " = " << 1LL * x * y << endl; // To prevent signed integer overflow
	cout << x << " - " << y << " = " << x - y << endl;
	return 0;
}
