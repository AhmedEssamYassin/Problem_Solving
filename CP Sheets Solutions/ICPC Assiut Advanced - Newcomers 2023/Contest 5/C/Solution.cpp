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
	an array with N elements and the summation of all elements in it is exactly S.
	Also, the numbers in the array must be NON-negative (0 and positive) and NOT more than 1000'000'000

	- If S <= 1000'000'000, then it's possible to build an array with just one element = S and nullify ALL remaining elements
	- Otherwise, if S > 1000'000'000
			   - If (N * 1000'000'000 < S) which means that the maximum possible sum to obtain is less than required S
				 then, it's impossible to obtain such array
			   - Otherwise, it's possible, print (S / 1000'000'000) times of 1000'000'000 then print (S % 1000'000'000)
				 and nullify ALL remaining elements
	*/
	int N;
	ll S;
	cin >> N >> S;
	constexpr int MAX_VAL = 1000'000'000;
	if (S <= MAX_VAL)
	{
		cout << "YES\n"
			 << S << " ";
		for (int i{1}; i <= N - 1; i++)
			cout << 0 << " ";
	}
	else //(S > MAX_VAL)
	{
		if ((S / MAX_VAL) + (S % MAX_VAL != 0) > N)
			return cout << "NO", 0;

		else
		{
			cout << "YES\n";
			for (int i{1}; i <= (S / MAX_VAL); i++) // How many 1000'000'000s are in S
				cout << 1000'000'000 << " ";

			int Remaining_S = S % MAX_VAL;

			if (Remaining_S != 0)
				cout << Remaining_S << " "; // What remains of S after subtracting ALL 1000'000'000s

			for (int i{1}; i <= (N - (S / MAX_VAL) - (Remaining_S != 0)); i++) // Nullifying ALL remaining elements
				cout << 0 << " ";
		}
	}

	return 0;
}