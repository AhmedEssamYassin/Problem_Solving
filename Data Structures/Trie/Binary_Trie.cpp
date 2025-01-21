#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct binaryTrie
{
    struct Node
    {
        Node *child[2];
        int freq[2];
        Node()
        {
            child[0] = child[1] = 0;
            freq[0] = freq[1] = 0;
        }
    };
    Node *root = new Node();

    binaryTrie()
    {
        insert(0);
    }
    void insert(ll n)
    {
        Node *cur = root;
        for (int i = 30; i >= 0; i--) // change 30 based on number of bits in maximum number
        {
            int idx = ((n >> i) & 1); // same as (n & (1 << i)), but this avoids any overflow
            if (cur->child[idx] == 0)
                cur->child[idx] = new Node();
            cur->freq[idx]++;
            cur = cur->child[idx];
        }
    }
    void erase(ll n, int i, Node *cur)
    {
        if (i == -1)
            return;
        int idx = ((n >> i) & 1);
        erase(n, i - 1, cur->child[idx]);
        cur->freq[idx]--;
        if (cur->freq[idx] == 0)
        {
            delete cur->child[idx];
            cur->child[idx] = NULL;
        }
    }
    ll maxXor(ll n)
    {
        Node *cur = root;
        ll ret = 0;
        for (int i = 30; i >= 0; i--) // change 30 based on number of bits in maximum number
        {
            ll idx = ((n >> i) & 1); // same as (n & (1 << i)), but this avoids any overflow
            if (cur->child[idx ^ 1] != 0)
                cur = cur->child[idx ^ 1], ret |= (1 << i);
            else
                cur = cur->child[idx];
        }
        return ret;
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
    ll N, Q;
    // cin >> t;
    while (t--)
    {
    }
    return 0;
}