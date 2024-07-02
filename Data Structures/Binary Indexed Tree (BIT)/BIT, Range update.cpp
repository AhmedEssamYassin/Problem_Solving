#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// INVERSION COUNT IN AN ARRAY
// Fenwick Tree: Binary Indexed Tree (BIT)
// Fenwick tree, AKA Binary Indexed Tree
int N = 100005;
__int128_t BIT[100005], BIT1[100005], BIT2[100005];

int Low_bit(int X)
{
    return (X & -X);
}

void updateElement(__int128_t *ft, int pos, const int &delta)
{
    for (int i = pos; i <= N; i += Low_bit(i))
        ft[i] += delta;
}

// Range update, Point queries
void updateRangeForPointQueries(int left, int right, const int &delta)
{
    updateElement(BIT, left, +delta);
    updateElement(BIT, right + 1, -delta);
}

// Range updates, Range queries
void updateRangeForRangeQueries(int left, int right, const int &delta)
{
    updateElement(BIT1, left, delta);
    updateElement(BIT1, right + 1, -delta);
    updateElement(BIT2, left, delta * (left - 1));
    updateElement(BIT2, right + 1, -delta * right);
}

// Computes the prefix sum from [1, pos], O(log(n))
ll Sum(__int128_t *ft, int pos)
{
    ll sum = 0;
    for (int i = pos; i > 0; i -= Low_bit(i))
        sum += ft[i];

    return sum;
}

ll prefixSum(int idx)
{
    return Sum(BIT1, idx) * idx - Sum(BIT2, idx);
}

ll Range_sum(int L, int R)
{
    return (Sum(BIT, R) - Sum(BIT, L - 1)) + (prefixSum(R) - prefixSum(L - 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE

    // Building tree
    /*
    // original elements are A[]
    for (int i{1}; i <= N; i++)
        updateElement(BIT, i, A[i]);
    */
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> N;
        int *arr = new int[N + 1];
        // Inputting and initializing
        for (int i = 1; i <= N; i++)
            cin >> arr[i], BIT[i] = 0;

        int res = 0;
        ll ans = 0;
        for (int i = 1; i <= N; i++)
        {
            ans += i - 1 - Sum(BIT, arr[i] - 1);
            updateElement(BIT, arr[i], 1);
        }
        cout << ans << endl;
    }
    return 0;
}