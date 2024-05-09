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

	Starting at i = 1
	- Number of lines = N

	- Number of spaces on each line is 0

	- Number of characters to be printed on each line is N, N-1, ..., 2, 1
	  which is an arithmetic sequence whose general term: G.T =  N - i + 1
	*/
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cout << string(N - i + 1, '*') << endl;
	return 0;
}