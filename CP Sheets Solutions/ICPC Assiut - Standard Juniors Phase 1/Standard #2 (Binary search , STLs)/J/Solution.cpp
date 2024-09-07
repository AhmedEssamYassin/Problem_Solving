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

	int N, Q, i;
	cin >> N;
	vector<int> Vec(N);
	for (int i{}; i < N; i++)
		cin >> Vec[i];

	/*
	Given an array Vec of N integers and Q queries.
	In each query given an integer i (1 <= i <= N), You must find the minimum integer j such that (i < j <= N) and Vec[i] < Vec[j]
	In other words, Find the Next Greater Element (NGE) of Vec[i]
	*/

	stack<int> St;

	// Elements can repeat but indices can NEVER, so instead of storing elements, store indices!
	vector<int> Ans(N, -1);
	// Indices of Ans[] represent indices of Vec[] and their values are the index of their NGE
	// Default value of all indices is -1 , so that if NO greater element found, they will be -1

	// 46 82 28 62 92
	St.push(0);
	for (int i{1}; i < N; i++)
	{
		if (St.empty())
			St.push(i);
		else
		{
			while (!St.empty() && Vec[i] > Vec[St.top()])
			{
				Ans[St.top()] = (i + 1); // To store the index of the next greater element in 1-based form
				St.pop();
			}
			St.push(i);
		}
	}

	cin >> Q;
	while (Q--)
	{
		cin >> i; // 1-based

		i--; // To make i be 0-based
		cout << Ans[i] << endl;
	}

	return 0;
}