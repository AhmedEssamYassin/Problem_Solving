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
#endif //! ONLINE_JUDGE
	/*
	1. If N: the length of array is EVEN
	{a[0], a[1], a[2], a[3], ..., a[N - 1]}
	If we XOR them all we get, X = (a[0] ^ a[1] ^ a[2] ^ a[3] ^ ... ^ a[N - 1])
	i.e., {X, X, X, X, ..., Nth X}, which are all equal
	So, if we XOR them again, all of them will be zero!
	So XORing the whole array twice is enough.

	2. If N: the length of array is ODD
	{a[0], a[1], a[2], a[3], ..., a[N - 1]}
	If we XOR them all we get, X = (a[0] ^ a[1] ^ a[2] ^ a[3] ^ ... ^ a[N - 1])
	{X, X, X, X, ..., Nth X}, which are all equal
	But, if we XOR them again, they will equal (X) NOT 0 !
	We can take the first (N - 1) elements, which would be of EVEN length and apply case number 1
	Now we have something like {0, 0, 0, 0, ..., Nth X}
	Now take the second (N - 1) elements, which would be also of EVEN length and apply case number 1
	*/
	int t = 1;
	int N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		int *arr = new int[N];

		for (int i{}; i < N; i++)
			cin >> arr[i];

		if (N & 1) // ODD
		{
			cout << 4 << endl;
			cout << 1 << " " << N - 1 << endl;
			cout << 1 << " " << N - 1 << endl;
			cout << 2 << " " << N << endl;
			cout << 2 << " " << N << endl;
		}
		else // EVEN
		{
			cout << 2 << endl;
			cout << 1 << " " << N << endl;
			cout << 1 << " " << N << endl;
		}
		delete[] arr;
	}
	return 0;
}