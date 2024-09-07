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

	int N, Q;
	cin >> N >> Q;
	uint64_t *arr = new uint64_t[N];
	uint64_t *Scan_line{new uint64_t[N + 1]{0}};
	for (size_t i{}; i < N; i++)
		cin >> arr[i];
	/*
	arr[] = {1, 0, 1, 0, 1}
	Scan_line[] = {0, 0, 0, 0, 0, 0}
	1 2 1: 1 0 -1 0 0 0
	3 5 3: 1 0 2 0 0 -3
	1 5 2: 3 0 2 0 0 -5
	Desired: 4 3 6 5 6
	Output: 3 3 5 5 5 0
	+arr[]: 1 0 1 0 1
	-------------------
	Ans: 	4 3 6 5 6
	*/
	int L, R, Val;
	while (Q--)
	{
		cin >> L >> R >> Val; // 1-based

		R--, L--; // To make them 0-based
		Scan_line[L] += Val;
		Scan_line[R + 1] -= Val;
	}
	for (size_t i{1}; i < N; i++)
		Scan_line[i] += Scan_line[i - 1];

	for (size_t i{}; i < N; i++)
		cout << arr[i] + Scan_line[i] << " ";
	delete[] arr;
	delete[] Scan_line;
	return 0;
}