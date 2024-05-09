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
	This time he enjoys the sorting function.
	Let arr is a permutation of integers from 1 to N, inclusive, and arr[i] denotes the i-th element of the permutation.
	The Little Elephant's recursive function F(x), that sorts the first x permutation's elements, works as follows:
	If x = 1, exit the function.
	Otherwise, call F(x - 1), and then make swap(arr[x - 1], arr[x]) (swap the x-th and (x - 1)-th elements of arr).
	i.e.,
	void F(int arr[], int N)
	{
		if (N == 0)//because we represent the permutation in an array which is 0-based
			return;
		F(arr, N - 1);
		swap(arr[N - 1], arr[N]);
	}

	The Little Elephant's teacher believes that this function does NOT work correctly.
	But that-be do NOT get an F, the Little Elephant wants to show the performance of its function.
	Help him, find a permutation of numbers from 1 to N, such that after performing the Little Elephant's function (that is call F(n)),
	the permutation will be sorted in ascending order (1, 2, 3, 4, ...).

	Let's simulate what the function does on a permutation of {1, 2, 3, 4, 5}
	F(4) --> F(3) --> F(2) --> F(1) --> F(0) is base case
	back to F(1) --> swap(arr[0], arr[1]) : {2, 1, 3, 4, 5}
	back to F(2) --> swap(arr[1], arr[2]) : {2, 3, 1, 4, 5}
	back to F(3) --> swap(arr[2], arr[3]) : {2, 3, 4, 1, 5}
	back to F(4) --> swap(arr[3], arr[4]) : {2, 3, 4, 5, 1}

	So, obviously, what the function does is that it moves the first element to the end of the permutation
	A permutation that after calling F(x) would be sorted in ascending order (1, 2, 3, 4, ..., N),
	must be {N, 1, 2, 3, ..., N-1}
	*/
	int N;
	cin >> N;
	cout << N << " ";
	for (int i{1}; i <= N - 1; i++)
		cout << i << " ";

	return 0;
}