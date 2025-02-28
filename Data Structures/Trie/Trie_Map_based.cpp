#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int n;
struct Trie
{
    struct Node
    {
        map<char, Node *> character;
        set<int> idxPref, idxEnd; // To maintain indices of strings having prefixes or ending at each node
        int prefix, isEnd;        // To count prefixes and strings ending at each node
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

    void insert(const string &str, int j)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            if (cur->character[C] == nullptr)
                cur->character[C] = new Node();

            cur = cur->character[C];
            cur->prefix++;
            cur->idxPref.insert(j); // A string of index j has a prefix at this node
        }
        cur->isEnd++;
        cur->idxEnd.insert(j); // A string of index j is ending at this node
    }

    // Is there any prefix of `str` occurs in a string in range [L, R]
    bool searchPrefix(const string &str, int L, int R)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            if (cur->character[C] == nullptr)
                return false;
            // Character exists, but is it end of word?
            cur = cur->character[C];
            auto &st = cur->idxEnd;
            if (st.lower_bound(L) != st.end() && *st.lower_bound(L) <= R)
                return true;
        }
        return false;
    }

    // Checks if `str` is a prefix of any string (or in range [L, R])
    // Can also return a boolean, or even the actual number of string having `str` as a prefix
    ll checkPrefix(const string &str, int L = 0, int R = n - 1)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            if (cur->character[C] == nullptr)
                return false;
            cur = cur->character[C];
        }
        // auto &st = cur->idxPref;
        // return (st.lower_bound(L) != st.end() && *st.lower_bound(L) <= R);
        return cur->prefix;
    }

    // Checks if a node is a leaf node (doesn't have any children)
    bool isLeaf(Node *root)
    {
        return root->character.empty();
    }

    // Recursive function to delete a word from given Trie (Assuming it's been inserted before)
    void erase(const string &str, int pos)
    {
        Node *cur = root;
        for (const char &C : str)
        {
            cur = cur->character[C];
            cur->prefix--;
            cur->idxPref.erase(pos);
        }
        cur->isEnd--;
        cur->idxEnd.erase(pos);
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
        n = N;
        Trie trie;
        for (int i{}; i < N; i++)
        {
            cin >> str;
            trie.insert(str, i);
        }
        while (Q--)
        {
            cin >> str;
            cout << trie.checkPrefix(str) << endl;
        }
    }
    return 0;
}