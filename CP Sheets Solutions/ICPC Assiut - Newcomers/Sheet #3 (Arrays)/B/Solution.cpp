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
	int N, X;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> X;
	int pos = -1;
	for (int i = 0; i < N; i++)
	{
		if (X == arr[i])
		{
			pos = i;
			break;
		}
	}
	cout << pos;
	delete[] arr;
	return 0;
}