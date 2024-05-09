#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	/*
	ONLY asterisks

	input: N
	- Number of lines = 2 * N

	First N lines of them:
	----------------------
	Starting at i = 1
	- Number of spaces on each line is (N - 1), (N - 2), ..., 0
	  which is an arithmetic sequence whose general term: G.T =  N - i

	- Number of characters to be printed on each line is 1, 3, 5, 7, ...
	  which is an arithmetic sequence whose general term: G.T =  (2 * i - 1)

	Last N lines of them:
	---------------------
	Starting at i = N
	- Number of spaces on each line is 0, 1, 2, ..., (N - 1)
	  which is an arithmetic sequence whose general term: G.T =  N - i

	- Number of characters to be printed on each line is 7, 5, ..., 1
	  which is an arithmetic sequence whose general term: G.T =  (2 * i - 1)
	*/
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cout << string(N - i, ' ') << string(2 * i - 1, '*') << endl;

	for (int i = N; i >= 1; i--)
		cout << string(N - i, ' ') << string(2 * i - 1, '*') << endl;
	return 0;
}