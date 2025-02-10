#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct dynamicSegmentTree
{
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll Value;
		Node *LeftChild, *RightChild; // Pointers to left child and right child

		Node() // Constructor
		{
			Value = 0;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
		Node(const ll &val)
		{
			Value = val;
			LeftChild = nullptr;
			RightChild = nullptr;
		}

		void createChildren() // Construct Childs
		{
			if (LeftChild == nullptr)
				LeftChild = new Node();
			if (RightChild == nullptr)
				RightChild = new Node();
		}
		~Node() // Destructor. Notice the "~" character before the struct name.
		{
			delete LeftChild;
			delete RightChild;
			LeftChild = nullptr;
			RightChild = nullptr;
		}
	};
	ll N;
	Node *root;
	void merge(Node *&segNode)
	{
		segNode->Value = segNode->LeftChild->Value + segNode->RightChild->Value;
	}
	void update(ll left, ll right, Node *Current, ll idx, const ll &newValue)
	{
		// idx is not in range [left, right]
		if (left > idx || right < idx)
			return;

		// Current is the Node that manage only ith element
		if (left == right)
		{
			Current->Value += newValue;
			return;
		}

		Current->createChildren();
		update(left, mid, Current->LeftChild, idx, newValue);
		update(mid + 1, right, Current->RightChild, idx, newValue);
		merge(Current);
	}
	ll query(ll left, ll right, Node *Current, ll leftQuery, ll rightQuery)
	{
		// [left, right] doesn't intersect with [leftQuery, rightQuery]
		if (left > rightQuery || right < leftQuery)
			return 0;

		// [left, curR] is inside [leftQuery, rightQuery]
		if (leftQuery <= left && right <= rightQuery)
			return Current->Value;

		Current->createChildren();
		ll leftSegment = query(left, mid, Current->LeftChild, leftQuery, rightQuery);
		ll rightSegment = query(mid + 1, right, Current->RightChild, leftQuery, rightQuery);
		return (leftSegment + rightSegment);
	}
	ll kthOne(ll left, ll right, Node *Current, ll k)
	{
		if (left == right)
			return (Current != nullptr && Current->Value == 1 ? left : -1);
		Current->createChildren();
		ll sumR = Current->RightChild->Value;
		if (sumR >= k)
			return kthOne(mid + 1, right, Current->RightChild, k);
		else
			return kthOne(left, mid, Current->LeftChild, k - sumR);
	}

public:
	dynamicSegmentTree(ll rangeSize = 2e9)
	{
		root = new Node();
		N = rangeSize + 1;
	}
	void update(ll idx, const ll &val)
	{
		update(0, N, root, idx, val);
	}
	ll query(ll left, ll right)
	{
		ll ans = query(0, N, root, left, right);
		return ans;
	}
	ll kthOne(ll k)
	{
		ll ans = kthOne(0, N, root, k);
		return ans;
	}
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
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> vc(N);
		ll cnt[10]{};
		auto addDigits = [&](ll N)
		{
			while (N)
				cnt[N % 10]++, N /= 10;
		};
		auto removeDigits = [&](ll N)
		{
			while (N)
				cnt[N % 10]--, N /= 10;
		};
		dynamicSegmentTree segTree;
		for (auto &x : vc)
			cin >> x, addDigits(x), segTree.update(x, 1);
		while (Q--)
		{
			char type;
			ll k;
			cin >> type >> k;
			if (type == '+')
			{
				if (segTree.query(k, k))
				{
					removeDigits(k);
					segTree.update(k, -1);
				}
				else
				{
					addDigits(k);
					segTree.update(k, +1);
				}
			}
			else if (type == '-')
			{
				ll pos = segTree.kthOne(k);
				if (~pos)
				{
					removeDigits(pos);
					segTree.update(pos, -1);
				}
			}
			else // '?'
			{
				if (segTree.query(k, k))
				{
					ll ans{};
					while (k)
						ans += cnt[k % 10], k /= 10;
					cout << ans << endl;
				}
				else
					cout << -1 << endl;
			}
		}
	}
	return 0;
}