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
	int t = 1, N, X;
	// cin >> t;
	while (t--)
	{
		/*
		The number of times a number X can be divided by 2 is the number of trailing 0's in X
		Let's store the number of trailing 0's of ALL given numbers in an array Cnt_tz[]
		We know that the operations continue until there is NO any number that is divisible by 2
		That means, the first number to be NOT divisible by 2 after some operations will cause the process to stop
		The first number to be NOT divisible by 2 is that number who has the least number of trailing 0's (least number of being divisible by 2)
		Hence, the answer is the minimum of Cnt_tz[]
		*/
		cin >> N;
		int *Cnt_tz = new int[N];

		for (int i{}; i < N; i++)
		{
			cin >> X;
			Cnt_tz[i] = __builtin_ctz(X);
		}
		cout << *min_element(Cnt_tz, Cnt_tz + N);
		delete[] Cnt_tz;
	}

	return 0;
}