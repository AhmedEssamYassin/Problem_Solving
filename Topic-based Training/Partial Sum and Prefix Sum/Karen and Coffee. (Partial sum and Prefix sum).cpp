/*
Partial sum and Prefix sum

She knows n coffee recipes. The i-th recipe suggests that coffee should be brewed between li and ri degrees, inclusive, to achieve the optimal taste.

Karen thinks that a temperature is ADMISSIBLE if at least k recipes recommend it.

In each question, given that she only wants to prepare coffee with a temperature between a and b, inclusive, can you tell her how many admissible integer temperatures fall
within the range?

Link: https://codeforces.com/group/T3p02rhrmb/contest/334361/problem/I
*/
#include <iostream>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q; // 3 2 4
	int l, r, a, b;
	int NumOfOccurrences[2000000], Admissible_Temp_till_now[2000000];
	while (n--)
	{
		cin >> l >> r;
		NumOfOccurrences[l]++;
		NumOfOccurrences[r + 1]--;
	}
	// 91 94
	// 92 97
	// 97 99
	// partial sum on the whole range to count the number of occurrences in all intervals
	// 90 91 92 93 94 95 96 97 98 99 100
	// 0  1  0  0  0  -1  0  0  0  0  0
	// 0  1  1  0  0  -1  0  0 -1  0  0
	// 0  1  1  0  0  -1  0  1 -1  0 -1
	for (int i = 1; i < 2000000; i++)
	{
		NumOfOccurrences[i] += NumOfOccurrences[i - 1];
		// 0  1  2  2  2   1  1  2  1  1  0
		Admissible_Temp_till_now[i] += Admissible_Temp_till_now[i - 1] + (NumOfOccurrences[i] >= m);
	}
	while (q--)
	{
		cin >> a >> b;
		cout << Admissible_Temp_till_now[b] - Admissible_Temp_till_now[a - 1] << "\n";
	}

	return 0;
}