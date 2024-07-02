#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
#define endl "\n"

// Can be used for GCD, LCM, Maximum, Minimum queries, this code is for Range Minimum Query AKA RMQ
const int MAX_N = 300009;
const int LOG = 18;
int a[MAX_N];
int m[MAX_N][LOG];

int query(int L, int R)
{
    int len = R - L + 1;
    int k = 31 - __builtin_clz(len);
    return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    int N, Q, L, R;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        for (int i{}; i < N; i++)
        {
            cin >> a[i];
            m[i][0] = a[i];
        }

        // Preprocessing
        for (int k = 1; k < LOG; k++)
        {
            for (int i{}; i + (1 << k) - 1 < N; i++)
                m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }

        cin >> Q;
        while (Q--)
        {
            cin >> L >> R;
            cout << query(L, R) << endl;
        }
    }
    return 0;
}