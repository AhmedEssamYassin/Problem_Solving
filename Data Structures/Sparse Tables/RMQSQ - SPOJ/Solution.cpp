#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// Can be used for GCD, LCM, Maximum, Minimum, OR, AND queries, this code is for Range Minimum Query AKA RMQ
struct sparseTable
{
    int size, LOG;
    vector<vector<ll>> m;

    sparseTable() {}
    sparseTable(const vector<ll> &arr, int lg)
    {
        build(arr, lg);
    }

    ll merge(const ll &a, const ll &b)
    {
        return min(a, b);
    }
    void build(const vector<ll> &arr, int lg)
    {
        int n = arr.size();
        LOG = lg;
        m.resize(n, vector<ll>(LOG, 0));
        int N = arr.size();
        for (int i{}; i < N; i++)
            m[i][0] = arr[i];
        for (int k = 1; k < LOG; k++)
        {
            for (int i{}; i + (1 << k) - 1 < N; i++)
                m[i][k] = merge(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }

    ll query(int L, int R) // 0-based
    {
        int len = R - L + 1;
        int k = 31 - __builtin_clz(len);
        return merge(m[L][k], m[R - (1 << k) + 1][k]);
    }
};

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
        vector<ll> a(N);
        for (int i{}; i < N; i++)
            cin >> a[i];
        sparseTable ST(a, 18);
        cin >> Q;
        while (Q--)
        {
            cin >> L >> R;
            cout << ST.query(L, R) << endl;
        }
    }
    return 0;
}