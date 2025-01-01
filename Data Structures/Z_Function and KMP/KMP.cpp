#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<int> b;

void KMP_Preprocess(string &p) // Takes pattern string
{
    b.assign(p.size() + 1, -1);
    int i = 0, j = -1;
    b[i] = j;
    while (i < p.size())
    {
        while (j >= 0 && p[i] != p[j])
            j = b[j];
        i++;
        j++;
        b[i] = j;
    }
}
vector<int> pos;
ll KMP_Search(string &t, string &p, int m) // {text, pattern, length of pattern}
{
    ll i = 0, j = 0, ans = 0;
    while (i < t.size())
    {
        while (j >= 0 && t[i] != p[j])
            j = b[j];
        i++;
        j++;

        if (j == m)
        {
            pos.push_back(i - j);
            ans++;
            j = b[j];
        }
    }

    return ans;
}
////////////////////////////////////////////////////////////////////////////////////

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
    string pat, text;
    ll len;
    // cin >> t;
    while (cin >> len >> pat >> text)
    {
        pos.clear();
        b.clear();
        KMP_Preprocess(pat);
        ll occ = KMP_Search(text, pat, pat.size());
        if (occ == 0)
        {
            cout << "\n";
            continue;
        }
        for (auto &i : pos)
            cout << i << "\n";
    }
    return 0;
}
