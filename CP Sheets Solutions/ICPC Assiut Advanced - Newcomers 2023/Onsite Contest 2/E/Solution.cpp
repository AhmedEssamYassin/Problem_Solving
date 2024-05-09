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
	Given an array consisting of N numbers,
	your task is to replace the numbers that are less than or equal to 0 with the Smallest Positive number that exists on the Right of its position.

	It's guaranteed that the last element in the array is a positive number.
	*/
	int N;
	cin >> N;
	int *arr = new int[N];
	int *RSP = new int[N]; // Rightmost Smallest Positive number
	for (int i{}; i < N; i++)
		cin >> arr[i];

	int SPN = arr[N - 1]; // The Smallest Positive Number is initially the last element in the array because It's guaranteed that it's a positive number

	RSP[N - 1] = SPN; // The Rightmost Smallest Positive number is initially the last element in the array because there are NO other candidates yet.
	for (int i{N - 2}; i >= 0; i--)
	{
		if (arr[i] > 0 and arr[i] < SPN)
			SPN = arr[i];
		RSP[i] = SPN;
	}
	for (int i{}; i < N; i++)
	{
		if (arr[i] <= 0)
			arr[i] = RSP[i];
	}
	for (int i{}; i < N; i++)
		cout << arr[i] << " ";

	return 0;
}