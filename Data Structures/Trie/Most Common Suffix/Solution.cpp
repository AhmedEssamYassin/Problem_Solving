#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> LCP;
struct Trie
{
	struct Node
	{
		map<char, Node *> character; // To use ONLY the exact needed memory

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
		int len = 1;
		for (const char &C : str)
		{
			if (!cur->character[C])
				cur->character[C] = new Node();

			cur = cur->character[C];
			LCP[len] = max(LCP[len], ++cur->prefix);
			len++;
		}
		cur->isEnd++;
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
	cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		Trie trie;
		int maxLen{};
		vector<string> vc(N);
		for (int i{}; i < N; i++)
		{
			cin >> vc[i];
			maxLen = max(maxLen, int(vc[i].length()));
		}
		LCP.assign(maxLen + 1, 1);
		for (string &str : vc)
		{
			// We need to count maximum number of strings having the Longest Common Suffix,
			// If we reverse all strings the problem will be counting maximum number of strings having the Longest Common Prefix
			reverse(str.begin(), str.end());
			trie.insert(str);
		}
		while (Q--)
		{
			ll x; // Longest Common Suffix
			cin >> x;
			cout << LCP[x] << endl;
		}
	}
	return 0;
}