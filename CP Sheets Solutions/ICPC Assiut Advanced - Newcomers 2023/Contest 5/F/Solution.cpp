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
	Your task is to calculate the most fair division
	i.e., the minimum difference between the animal that ate the most and the animal that ate the least
	That means we need the least maximum share of slices and the greatest minimum share of slices
	*/
	int N;
	cin >> N;
	vector<int> Slices(2 * N);
	for (int i{}; i < 2 * N; i++)
		cin >> Slices[i];
	sort(Slices.begin(), Slices.end());

	vector<int> Share(N);
	int L{}, R = 2 * N - 1;
	while (L <= R)
		Share[L - 1] = Slices[L++] + Slices[R--];
	// L++ evaluates first, So it will assigns each Val[i] to Share[i + 1], thus we wrote Share[L - 1]
	sort(Share.begin(), Share.end());

	cout << Share.back() - Share.front();

	return 0;
}