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

	/*
	The 4 numbers has been generated using the following operations: (A + B), (A + C), (B + C) and (A + B + C)
	X1 = A + B
	X2 = A + C
	X3 = B + C
	X4 = A + B + C

	Note:
	The numbers will be given in a random order
	It's obvious that (A + B + C) is the greatest among all inputs
	Subtracting the other values of that greatest value will give A, B and C NOT respectively
	But since the required is to output A, B and C in any order, we don't care about which is which
	*/
	vector<int> Inputs(4);
	cin >> Inputs[0] >> Inputs[1] >> Inputs[2] >> Inputs[3];
	sort(Inputs.begin(), Inputs.end());
	cout << Inputs.back() - Inputs[0] << " " << Inputs.back() - Inputs[1] << " " << Inputs.back() - Inputs[2];

	return 0;
}