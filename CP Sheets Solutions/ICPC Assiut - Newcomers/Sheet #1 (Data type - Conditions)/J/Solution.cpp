#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
	if (A % B = 0)
	Then, it's said that:
	B divides A
	B|A
	B is a divisor of A
	A is a multiple of B

	Similarly, if (B % A = 0)
	then, it's said that:
	A divides B
	A|B
	A is a divisor of B
	B is a multiple of A
	*/
	long long int A, B;
	cin >> A >> B;
	if (A % B == 0 || B % A == 0)
		cout << "Multiples" << endl;
	else
		cout << "No Multiples" << endl;
	return 0;
}
