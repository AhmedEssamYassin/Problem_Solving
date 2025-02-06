#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // For less<T> or less_equal<T>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
// Be careful with less<T> or less_equal<T>
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N, K;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        // a[i] + a[j] > b[i] + b[j]
        // a[i] - b[i] > b[j] - a[j]
        vector<ll> a(N), b(N), diff(N);
        for (int i{}; i < N; i++)
            cin >> a[i];
        for (int i{}; i < N; i++)
            cin >> b[i];
        for (int i{}; i < N; i++)
            diff[i] = a[i] - b[i];
        ll cnt{};
        ordered_multiset<ll> X;
        for (int i{}; i < N; i++)
        {
            ll lessThanMe = 0;
            lessThanMe += X.order_of_key(diff[i]);
            cnt += lessThanMe;
            X.insert(-diff[i]);
        }
        cout << cnt;
    }
    return 0;
}