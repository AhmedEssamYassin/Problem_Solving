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

	int Freq_arr[100001] = {0};
	int N, A;
	cin >> N;
	while (N--)
	{
		cin >> A;
		Freq_arr[A]++;
	}
	for (int i{}; i < 100001; i++)
	{
		while (Freq_arr[i]--)
			cout << i << " ";
	}

	return 0;
}