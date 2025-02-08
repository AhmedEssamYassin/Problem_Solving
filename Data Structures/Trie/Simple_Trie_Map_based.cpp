#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Trie
{
    struct Node
    {
        map<char, Node *> character;
        ll prefix, isEnd; // To count prefixes and strings ending at each node
        Node()
        {
            prefix = 0;
            isEnd = 0;
        }
    };

    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(const string &str)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            int idx = (C - 'a'); // To be 0-based index
            if (cur->character[idx] == nullptr)
                cur->character[idx] = new Node();

            cur = cur->character[idx];
            cur->prefix++;
        }
        cur->isEnd++;
    }

    // Can return a boolean, or the actual number of string having `str` as a prefix
    ll checkPrefix(const string &str)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            int idx = (C - 'a');
            if (cur->character[idx] == nullptr)
                return 0;
            cur = cur->character[idx];
        }
        return cur->prefix;
    }

    ~Trie()
    {
        for (auto &[character, node] : root->character)
            delete (node);
        delete (root);
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
        Trie trie;
        for (int i{}; i < N; i++)
        {
            cin >> str;
            trie.insert(str);
        }
        while (Q--)
        {
            cin >> str;
            cout << trie.checkPrefix(str) << endl;
        }
    }
    return 0;
}