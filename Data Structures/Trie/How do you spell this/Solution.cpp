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
		ll remaining;	  // To count remaining characters to form a complete existing word
		Node()
		{
			prefix = 0;
			isEnd = 0;
			remaining = LLONG_MAX;
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
		ll curLen = str.length();
		cur->remaining = min(cur->remaining, curLen);
		for (const char &C : str)
		{
			if (cur->character[C] == nullptr)
				cur->character[C] = new Node();

			cur = cur->character[C];
			cur->prefix++;
			cur->remaining = min(cur->remaining, --curLen);
		}
		cur->remaining = min(cur->remaining, 0LL); // End of a word
		cur->isEnd++;
	}

	// Can return a boolean, or the actual number of string having `str` as a prefix
	ll checkPrefix(const string &str)
	{
		Node *cur = root;
		for (const char &C : str)
		{
			if (cur->character[C] == nullptr)
				return -1;
			cur = cur->character[C];
		}
		return cur->remaining;
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
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		Trie trie;
		string str;
		for (int i{}; i < N; i++)
		{
			cin >> str;
			trie.insert(str);
		}
		for (int i{}; i < Q; i++)
		{
			cin >> str;
			ll ans = trie.checkPrefix(str);
			cout << ans << endl;
		}
	}
	return 0;
}