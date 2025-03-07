#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Trie
{
	struct Node
	{
		map<char, Node *> mp;
		ll prefix, end;
		Node()
		{
			prefix = 0;
			end = 0;
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
			if (cur->mp[C] == nullptr)
				cur->mp[C] = new Node();
			cur = cur->mp[C];
			cur->prefix++;
		}
		cur->end++;
	}
	ll checkPrefix(const string &str)
	{
		Node *cur = root;
		for (const char &C : str)
		{
			if (cur->mp[C] == nullptr)
				return 0;
			cur = cur->mp[C];
		}
		return cur->prefix;
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<string> vc(N);
		Trie trie;
		for (int i{}; i < N; i++)
		{
			cin >> vc[i];
			reverse(vc[i].begin(), vc[i].end());
			trie.insert(vc[i]);
		}
		for (int i{}; i < N; i++)
		{
			if (trie.checkPrefix(vc[i]) == N)
			{
				string str = vc[i];
				reverse(str.begin(), str.end());
				cout << str;
				return 0;
			}
		}
		cout << "Not found";
	}
	return 0;
}