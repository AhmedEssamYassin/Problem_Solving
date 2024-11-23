#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
//////////////////////////////////////////////////////////////////////////////////
// For Binary trees
class Node
{
public:
	ll val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(ll _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(ll _val, Node *_left, Node *_right, Node *_next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

void BFS(Node *root)
{
	if (root == nullptr)
		return;
	queue<Node *> q;
	q.push(root);
	while (!q.empty())
	{
		int sz = q.size();
		vector<Node *> vc; // To maintain all nodes of current level
		for (int i{}; i < sz; i++)
		{
			Node *cur = q.front();
			q.pop();
			vc.push_back(cur);
			if (cur->left != nullptr)
				q.push(cur->left);

			if (cur->right != nullptr)
				q.push(cur->right);
		}
		// Now `vc` contains all siblings of this level
	}
}
//////////////////////////////////////////////////////////////////////////////////
// For adjacency list representation of Graph

void BFS(const vector<vector<ll>> &adj)
{
	int s; // source vertex
	int n; // number of nodes
	queue<ll> q;
	vector<bool> used(n);
	vector<int> depth(n), parent(n);

	q.push(s);
	used[s] = true;
	parent[s] = -1; // The root has NO parent
	while (!q.empty())
	{
		ll u = q.front();
		q.pop();
		for (const ll &v : adj[u])
		{
			if (!used[v])
			{
				used[v] = true;
				q.push(v);
				depth[v] = depth[u] + 1;
				parent[v] = u;
			}
		}
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
	ll N, M;
	cin >> t;
	while (t--)
	{
	}
	return 0;
}
