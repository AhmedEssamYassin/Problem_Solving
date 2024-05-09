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
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] < 0)
			arr[i] = 2;
		else if (arr[i] > 0)
			arr[i] = 1;
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	delete[] arr;
	return 0;
}