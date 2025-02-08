#define ll long long
struct Trie
{
	struct Node
	{
		map<ll, Node *> character;
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
		int n = str.length();
		for (int i{}; i < n; i++)
		{
			int idx = str[i] * 128 + str[n - i - 1];
			if (cur->character[idx] == nullptr)
				cur->character[idx] = new Node();

			cur = cur->character[idx];
			cur->prefix++;
		}
		cur->isEnd++;
	}

	ll search(const string &str)
	{
		Node *cur = root;
		ll cnt{};
		int n = str.length();
		for (int i = 0; i < n; i++)
		{
			int idx = str[i] * 128 + str[n - i - 1];
			if (!cur->character.count(idx))
				break;
			cur = cur->character[idx];
			cnt += cur->isEnd;
		}
		return cnt;
	}

	~Trie()
	{
		for (auto &[character, node] : root->character)
			delete (node);
		delete (root);
	}
};
class Solution
{
public:
	long long countPrefixSuffixPairs(vector<string> &words)
	{
		Trie trie;
		ll ans = 0;
		trie.insert(words[0]);
		int n = words.size();
		for (int i = 1; i < n; i++)
		{
			ans += trie.search(words[i]);
			trie.insert(words[i]);
		}
		return ans;
	}
};