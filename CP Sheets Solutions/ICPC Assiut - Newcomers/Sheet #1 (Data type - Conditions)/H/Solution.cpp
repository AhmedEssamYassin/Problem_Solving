#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long double X, Y;
	cin >> X >> Y;
	cout << "floor " << X << " / " << Y << " = " << floor(X / Y) << endl;
	cout << "ceil " << X << " / " << Y << " = " << ceil(X / Y) << endl;
	cout << "round " << X << " / " << Y << " = " << round(X / Y) << endl;
	return 0;
}
