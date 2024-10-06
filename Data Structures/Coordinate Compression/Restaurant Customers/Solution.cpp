#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class compressedRange
{
private:
	vector<ll> init;
	void compress(vector<ll> &vec)
	{
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
	}

public:
	compressedRange(vector<ll> &vec)
	{
		init = vec;
		compress(init);
	}
	int index(ll val)
	{
		return lower_bound(init.begin(), init.end(), val) - init.begin();
	}
	ll initVal(int idx)
	{
		return init[idx];
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
	int N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> L(N), R(N), idx;
		for (int i{}; i < N; i++)
		{
			cin >> L[i] >> R[i];
			idx.push_back(L[i]);
			idx.push_back(R[i]);
		}

		compressedRange comp(idx);

		for (int i{}; i < N; i++)
		{
			L[i] = comp.index(L[i]);
			R[i] = comp.index(R[i]);
		}

		int *scanLine{new int[2 * N + 1]{0}};
		for (int i{}; i < N; i++)
		{
			scanLine[L[i]]++;
			scanLine[R[i] + 1]--;
		}

		int maxAns{scanLine[0]};
		for (int i{1}; i < 2 * N + 1; i++)
		{
			scanLine[i] += scanLine[i - 1];
			if (scanLine[i] > maxAns)
				maxAns = scanLine[i];
		}

		cout << maxAns;
	}
	return 0;
}