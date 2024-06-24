#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

inline void Set_ith_bit(ll &N, uint16_t i) // 0-based
{
	N = N | (1LL << i);
}

int primes[100];
map<int, int> pos;
void primeFactorize(ll N, ll &primeSet)
{
	if (N <= 1)
		return;
	if (not(N & 1))
		Set_ith_bit(primeSet, pos[2]);

	while (not(N & 1))
		N >>= 1;

	for (ll p = 3; p * p <= N && N > 1; p += 2)
	{
		if (N % p == 0)
			Set_ith_bit(primeSet, pos[p]);
		while (N % p == 0)
			N /= p;
	}
	if (N > 1)
		Set_ith_bit(primeSet, pos[N]);
}

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll primeSet;
		Node() {}
		Node(const ll &N)
		{
			if (N == 0)
				primeSet = -1;
			else
				primeSet = 0;
			primeFactorize(N, primeSet);
		}
		Node operator*(const Node &RHS)
		{
			this->primeSet |= RHS.primeSet;
			return *this;
		}
	};
	int size;
	vector<Node> seg, lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.primeSet = (leftNode.primeSet & rightNode.primeSet);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// Initialize the lazy array with ones
		lazy[node] = 1;
		// If the segment has only one element
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
		}
		else
		{
			// Recursively build the left child
			build(left, mid, L, arr);
			// Recursively build the right child
			build(mid + 1, right, R, arr);

			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}
	void push(int left, int right, int node)
	{
		// Propagate the value
		seg[node] = (seg[node] * lazy[node]);
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for
			// the left child
			lazy[L] = (lazy[L] * lazy[node]);
			// Update the lazy values
			// for the right child
			lazy[R] = (lazy[R] * lazy[node]);
		}
		// Reset the lazy value
		lazy[node] = 1;
	}
	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (leftQuery > rightQuery)
			return;
		// If the range matches the segment
		if (leftQuery == left && rightQuery == right)
		{
			// Update the lazy value
			lazy[node] = (lazy[node] * val);

			// Apply the update immediately
			push(left, right, node);
		}
		else
		{
			// Recursively update the left child
			update(left, mid, L, leftQuery, min(rightQuery, mid), val);
			// Recursively update the right child
			update(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery, val);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Apply the pending updates if any
		push(left, right, node);
		// If the range is invalid, return set bits NOT to affect other queries
		if (leftQuery > rightQuery || right < leftQuery || left > rightQuery)
			return 0; // The node constructor will make it -1

		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];
		Node getLeftQuery = query(left, mid, L, leftQuery, min(rightQuery, mid));
		Node getRightQuery = query(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery);
		return merge(getLeftQuery, getRightQuery);
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;

		seg = vector<Node>(2 * size, 0);
		lazy = vector<Node>(2 * size, 1);
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.primeSet;
	}

	void print()
	{
		for (int i{15}; i < 31; i++)
			cout << seg[i].primeSet << " ";
		cout << endl;
	}
#undef L
#undef R
#undef mid
};

void sieveOfEratosthenes()
{
	bitset<401> isPrime;
	isPrime.set();
	isPrime[0] = 0;
	isPrime[1] = 0;
	int idx = 0;
	for (int i{2}; i * i <= 400; i++)
	{
		if (isPrime[i])
		{
			primes[idx] = i;
			pos[i] = idx;
			idx++;
			for (int j = i * i; j <= 400; j += i)
				isPrime[j] = 0;
		}
	}
	int maxPrime = primes[idx - 1];
	for (int i = maxPrime + 1; i < 401; i++)
	{
		if (isPrime[i])
			primes[idx] = i, pos[i] = idx, idx++;
	}
}

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
	sieveOfEratosthenes();
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];

		segmentTree segTree(vc);
		while (Q--)
		{
			string query;
			ll L, R, val;
			cin >> query >> L >> R;
			L--, R--;
			if (query == "MULTIPLY")
			{
				cin >> val;
				segTree.update(L, R, val);
			}
			else
			{
				ll primeSet = segTree.query(L, R);
				int idx = 62;
				for (int i{}; i < 62; i++)
				{
					if ((primeSet & (1LL << i)) == 0)
					{
						idx = i;
						break;
					}
				}
				cout << primes[idx] << endl;
			}
		}
	}
	return 0;
}
