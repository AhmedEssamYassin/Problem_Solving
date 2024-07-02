#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Trie
{
    struct Node
    {
        Node *character[26];
        int prefix, end;
        Node()
        {
            prefix = 0;
            end = 0;
            memset(character, NULL, sizeof(character));
        }
    };
    Node *root = new Node();
    void insert(const string &str)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            int idx = (C - 'a'); // To be 0-based index
            if (cur->character[idx] == 0)
                cur->character[idx] = new Node();
            cur = cur->character[idx];
            cur->prefix++;
        }
        cur->end++;
    }
    int count(const string &str)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            int idx = (C - 'a');
            if (cur->character[idx] == 0)
                return 0;
            cur = cur->character[idx];
        }
        return cur->prefix;
    }
};

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
    void insert(int n)
    {
        Node *cur = root;
        for (int i = 30; i >= 0; i--)
        {
            int idx = ((n >> i) & 1); // same as (n & (1 << i)), but this avoids any overflow
            if (cur->child[idx] == 0)
                cur->child[idx] = new Node();
            cur->freq[idx]++;
            cur = cur->child[idx];
        }
    }
    void erase(int n, int i, Node *cur)
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
    int maxXor(int n)
    {
        Node *cur = root;
        int ret = 0;
        for (int i = 30; i >= 0; i--)
        {
            int idx = ((n >> i) & 1);
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
    string str;
    // cin >> t;
    while (t--)
    {
        cin >> N >> Q;
        Trie letterTree;
        while (N--)
        {
            cin >> str;
            letterTree.insert(str);
        }
        while (Q--)
        {
            cin >> str;
            cout << letterTree.count(str) << endl;
        }
    }
    return 0;
}