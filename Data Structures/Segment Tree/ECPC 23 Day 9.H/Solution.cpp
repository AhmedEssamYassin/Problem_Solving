#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll invCount;
		int freq[26];
		// Constructors
		Node()
		{
			memset(freq, 0, sizeof(freq));
			invCount = 0;
		}
		Node(const char &val)
		{
			memset(freq, 0, sizeof(freq));
			invCount = 0;
			freq[val - 'a'] = 1;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.invCount = (leftNode.invCount + rightNode.invCount);

		for (int i = 0; i < 26; i++)
			res.freq[i] = leftNode.freq[i] + rightNode.freq[i];

		ll sum = 0;
		for (int i = 25; i >= 0; i--)
		{
			res.invCount += sum * rightNode.freq[i];
			sum += leftNode.freq[i];
		}
		return res;
	}
	void build(int left, int right, int node, const string &arr)
	{
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
			return;
		}

		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}

	void update(int left, int right, int node, int idx, const char &val)
	{
		if (left == right)
		{
			seg[node] = val;
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, val);
		else
			update(mid + 1, right, R, idx, val);

		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		if (left > rightQuery || right < leftQuery)
			return Node();
		if (leftQuery >= left && rightQuery <= right)
			return seg[node];

		Node getLeftQuery = query(left, mid, L, leftQuery, rightQuery);
		Node getRightQuery = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(getLeftQuery, getRightQuery);
	}

public:
	segmentTree(const string &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node());
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const char &val)
	{
		update(0, size - 1, 0, idx, val);
	}

	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.invCount;
	}

#undef L
#undef R
#undef mid
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
	cin >> t;
	while (t--)
	{
		cin >> N;
		cin >> str;
		segmentTree segTree(str);
		cin >> Q;
		while (Q--)
		{
			ll query, L, R, pos;
			char C;
			cin >> query;
			if (query == 1)
			{
				cin >> pos >> C;
				pos--;
				str[pos] = C;
				segTree.update(pos, C);
			}
			else if (query == 2)
			{
				cin >> L >> R;
				L--, R--;
				char C = str[L];
				char K = str[R];
				swap(str[L], str[R]);
				segTree.update(L, K);
				segTree.update(R, C);
			}
			else
				cout << segTree.query(0, N - 1) << endl;
		}
	}
	return 0;
}