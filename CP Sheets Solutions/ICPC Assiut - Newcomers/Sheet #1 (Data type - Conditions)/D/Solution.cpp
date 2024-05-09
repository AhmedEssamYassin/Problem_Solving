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
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	// A, B, C and D themselves are of type int (<= 2³­­¹ - 1) but the multiplication (A * B) and (C * D) is likely to overflow
	cout << "Difference = " << (1LL * A * B) - (1LL * C * D);
	return 0;
}
