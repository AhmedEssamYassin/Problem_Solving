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

	int N;
	cin >> N;
	/*
	Assume we have a number of intervals:
	2 8
	5 7
	3 9
	12 18
	14 21
	19 20
	First, We need to sort ALL intervals in ascending order on basis of their Starts
	2 8
	3 9
	5 7
	12 18
	14 21
	19 20
	- Two intervals are said to be intersecting iff the Start of an interval is less than or equal to the End of its preceding interval
	push {2, 8}
	3 < 8 so, they overlap --> {2, max(8, 9)} --> {2, 9}
	5 < 9 so, they overlap --> {2, max(7, 9)} --> {2, 9}
	12 > 9 so, they do NOT overlap
	push {12, 18}
	14 < 18 so, they overlap --> {12, max(18, 21)} --> {12, 21}
	19 < 21 so, they overlap --> {12, max(21, 20)} --> {12, 21}
	Answer is: {{2, 9}, {12, 21}}
	*/
	vector<pair<int, int>> Intervals(N);
	for (int i{}; i < N; i++)
	{
		auto &[Start, End] = Intervals[i];
		cin >> Start >> End;
		// Start should be less than or equal to End
		// NO constraints are given to guarantee their order
		if (Start > End)
			swap(Start, End);
	}

	sort(Intervals.begin(), Intervals.end()); // To sort all pairs (intervals) in ascending order on basis of their first element (Start)

	deque<pair<int, int>> Ans; // To store pairs
	Ans.push_back(Intervals[0]);
	for (int i{1}; i < N; i++)
	{
		// If intervals overlap
		if (Intervals[i].first <= Ans.back().second)
			Ans.back().second = max(Intervals[i].second, Ans.back().second); // Choose their maximum End

		else // A new interval starts
			Ans.push_back(Intervals[i]);
	}

	while (!Ans.empty())
	{
		cout << Ans.front().first << " " << Ans.front().second << endl;
		Ans.pop_front();
	}

	return 0;
}