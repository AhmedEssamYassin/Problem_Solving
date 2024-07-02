#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// Kadane's Algorithm to Maximum Sum Sub_array
// At each element: Either start a new contiguous sub_array or continue the previous sum
tuple<int, int, int> Max_sub_array_sum(int *arr, int size)
{
    int Max_sub_sum = INT_MIN, curr_sum = 0, L = 0, R = 0, temp = 0;
    for (int i{}; i < size; i++)
    {
        curr_sum += arr[i];
        if (curr_sum > Max_sub_sum)
        {
            Max_sub_sum = curr_sum;
            L = temp + 1;
            R = i + 1;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
            temp = i + 1;
        }
    }
    return {Max_sub_sum, L, R};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE

    int t = 1, N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        int *arr = new int[N];
        for (int i{}; i < N; i++)
            cin >> arr[i];

        tuple<int, int, int> Ans = Max_sub_array_sum(arr, N); //{Max_sum, L, R}

        cout << get<0>(Ans) << " " << get<1>(Ans) << " " << get<2>(Ans) << endl;

        delete[] arr;
    }
    return 0;
}