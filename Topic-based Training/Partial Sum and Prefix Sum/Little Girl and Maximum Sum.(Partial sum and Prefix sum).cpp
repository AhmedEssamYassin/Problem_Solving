/*
Little Girl and Maximum Sum.(Partial sum and Prefix sum)
reorder the array elements before replying to each of the queries in a way that makes the sum of that query replies maximum possible.
Your task is to find the value of this maximum sum.
Link: https://codeforces.com/problemset/problem/276/C
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q, l, r;
	cin >> n >> q; // 5 3
	ll *arr = new ll[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	// 5 2 4 1 3
	sort(arr, arr + n);
	// 1 2 3 4 5
	ll *P_sum{new ll[n]{0}};
	while (q--)
	{
		cin >> l >> r;
		l--;
		r--;
		P_sum[l]++;
		if (r < n - 1)
			P_sum[r + 1]--;
	}
	// 0 0 0 0  0
	// 1 0 0 0  0
	// 1 1 0 -1 0
	// 1 2 0 -2 0
	for (int i = 1; i < n; i++)
		P_sum[i] += P_sum[i - 1];

	// 1 3 3 1 1
	sort(P_sum, P_sum + n);
	// 1 1 1 3 3
	ll sum{};
	for (int i = 0; i < n; i++)
		sum += arr[i] * P_sum[i];

	// making numbers of highest frequency in the sum to be greatest as possible by sorting both frequency array and numbers array in an ascending order
	// 1*1 + 1*2 + 1*3 + 3*4 +3*5=33
	cout << sum;
	delete[] P_sum;
	delete[] arr;
	return 0;
}