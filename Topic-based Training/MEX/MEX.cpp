#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> Prefix_Mex(const vector<ll> &A)
{
    bitset<1000000> seen;

    ll mex = 1;
    seen[0] = 1;
    vector<ll> result(A.size());

    for (ll i = 0; i < A.size(); i++)
    {
        seen[A[i]] = 1;

        while (seen[mex] == 1)
            mex++;
        result[i] = mex;
    }

    return result;
}

vector<ll> Suffix_Mex(const vector<ll> &A)
{
    bitset<1000000> seen;

    ll mex = 1;
    seen[0] = 1;

    vector<ll> result(A.size());

    for (ll i = A.size() - 1; i >= 0; i--)
    {
        seen[A[i]] = 1;

        while (seen[mex] == 1)
            mex++;
        result[i] = mex;
    }

    return result;
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
    ll N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        vector<ll> vc(N), pref(N, 0);
        for (int i{}; i < N; i++)
        {
            cin >> vc[i];
            if (!i)
                pref[0] = vc[0];
            else
                pref[i] = pref[i - 1] + vc[i];
        }
        vector<ll> prefMex = Prefix_Mex(vc);
        vector<ll> sufMex = Suffix_Mex(vc);
        vector<pair<ll, ll>> ans;
        for (int i{}; i < N - 1; i++) // Can't have an empty suffix
        {
            ll lenPref = i + 1;
            ll lenSuf = N - lenPref;
            ll sufSum = (pref[N - 1] - pref[i]);
            if (pref[i] == lenPref * (lenPref + 1) / 2 && prefMex[i] == lenPref + 1 && sufSum == lenSuf * (lenSuf + 1) / 2 && sufMex[i + 1] == lenSuf + 1)
                ans.push_back({lenPref, lenSuf});
        }
        cout << ans.size() << endl;
        for (const auto &[x, y] : ans)
            cout << x << " " << y << endl;
    }
    return 0;
}