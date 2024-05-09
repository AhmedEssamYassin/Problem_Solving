#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void Mult(ll N[2][2], ll M[2][2])
{
	ll x00 = N[0][0] * M[0][0] + N[0][1] * M[1][0];
	ll x01 = N[0][0] * M[1][0] + N[0][1] * M[1][1];
	ll x10 = N[1][0] * M[0][0] + N[1][1] * M[1][0];
	ll x11 = N[1][0] * M[1][0] + N[1][1] * M[1][1];
	N[0][0] = x00, N[0][1] = x01, N[1][0] = x10, N[1][1] = x11;
}

void Matrix_bin_exp(ll Fib[2][2], int N)
{
	ll M[][2] = {{1, 1}, {1, 0}};
	if (N < 2)
		return;
	Matrix_bin_exp(Fib, N / 2);
	Mult(Fib, Fib);
	if (N % 2 != 0)
		Mult(Fib, M);
}
ll Nth_Fib(int N)
{
	if (N < 2)
		return N;
	ll F[2][2] = {{1, 1}, {1, 0}};
	Matrix_bin_exp(F, N);
	return F[0][1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	int N;
	cin >> N;
	for (int i{}; i < N; i++)
		cout << Nth_Fib(i) << " ";

	/*
	A naive solution:
	int N, Prev_Prev, Prev, Current;
	cin >> N;
	Prev_Prev = 0;
	Prev = 1;
	if (N == 1)
		cout << Prev_Prev;
	else if (N == 2)
		cout << Prev_Prev << " " << Prev << " ";
	else
	{
		cout << Prev_Prev << " " << Prev << " ";
		for (int i = 3; i <= N; i++)
		{
			cout << (Current = Prev_Prev + Prev) << " ";
			Prev_Prev = Prev;
			Prev = Current;
		}
	}
	*/
	return 0;
}