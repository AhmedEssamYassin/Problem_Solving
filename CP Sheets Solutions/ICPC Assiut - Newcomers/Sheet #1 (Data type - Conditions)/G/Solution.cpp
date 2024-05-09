#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long N;
	cin >> N;
	/*
	Let   S = 1 + 2 + 3 + 4 + 5 + 6 + ... N
	also, S = N + (N - 1) + (N - 2) + ... 1
	Adding the two equations, we get:
	2S = (N + 1) + (N + 1) +(N + 1) + ... repeated N times
	2S = N * (N + 1)
	S = N * (N + 1) / 2
	*/
	cout << N * (N + 1) / 2;
	return 0;
}
