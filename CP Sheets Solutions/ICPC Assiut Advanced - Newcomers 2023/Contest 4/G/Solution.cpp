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

	/*
	He gave him an array consists of N numbers and asked him to print the front element then remove it,
	then print the end element then remove it and so on until the array becomes empty.
	*/
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i{}; i < N; i++)
		cin >> arr[i];

	// Two-pointer technique
	int Left{}, Right = N - 1;
	bool gate{};
	while (Left <= Right)
	{
		if (gate = !gate) // Flips the gate state (From true to false and from false to true) each iteration
			cout << arr[Left++] << " ";
		else
			cout << arr[Right--] << " ";
	}

	return 0;
}