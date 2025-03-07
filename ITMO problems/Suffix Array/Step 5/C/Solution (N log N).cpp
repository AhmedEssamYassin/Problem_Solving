#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll bitCeil(const ll &N)
{
	ll res{1};
	while (res < N)
		res <<= 1;
	return res;
}

constexpr char SENTINEL = '#'; // A character that is guaranteed to be less than all string characters

class SuffixArray
{
private:
	string S;
	int length;
	int gap;
	int LOG;
	vector<int> position;
	vector<int> tempArray;
	vector<vector<int>> sparseTable;

	void buildSuffixArray()
	{
		iota(suffixArray.begin(), suffixArray.end(), 0);
		sort(suffixArray.begin(), suffixArray.end(), [&](int i, int j)
			 { return S[i] < S[j]; });
		for (int i = 1; i < length; i++)
			position[suffixArray[i]] = position[suffixArray[i - 1]] + (S[suffixArray[i]] != S[suffixArray[i - 1]]);
		for (gap = 1; gap < length; gap <<= 1)
		{
			vector<int> freq(length + 2);
			for (int i = 0; i < length; i++)
				suffixArray[i] = (suffixArray[i] - gap + length) % length, freq[position[i] + 1]++;
			for (int i = 1; i <= length + 1; i++)
				freq[i] += freq[i - 1];

			vector<int> newSA(length);
			for (int i = 0; i < length; i++)
				newSA[freq[position[suffixArray[i]]]++] = suffixArray[i];
			suffixArray.swap(newSA);

			vector<int> newPos(length);
			for (int i = 1; i < length; i++)
			{
				newPos[suffixArray[i]] = newPos[suffixArray[i - 1]] +
										 (position[suffixArray[i]] != position[suffixArray[i - 1]] || position[(suffixArray[i] + gap) % length] != position[(suffixArray[i - 1] + gap) % length]);
			}
			position.swap(newPos);
		}
	}

	void buildLCPArray()
	{
		for (int i = 0, k = 0; i < length; ++i)
		{
			if (position[i] != length - 1)
			{
				int j = suffixArray[position[i] + 1];
				while (S[i + k] == S[j + k])
					++k;
				lcpArray[position[i]] = k;
				if (k)
					--k;
			}
		}

		// Build sparse table for RMQ
		for (int i = 0; i < length; i++)
			sparseTable[i][0] = lcpArray[i];

		for (int k = 1; k < LOG; k++)
		{
			for (int i = 0; i + (1 << k) - 1 < length; i++)
				sparseTable[i][k] = min(sparseTable[i][k - 1], sparseTable[i + (1 << (k - 1))][k - 1]);
		}
	}

public:
	vector<int> suffixArray;
	vector<int> lcpArray;

	SuffixArray(const string &input, bool buildLCP = false)
		: S(input),
		  LOG((ll)(log2l(bitCeil(input.length())) + 1) + 1),
		  length(input.length()),
		  suffixArray(input.length()),
		  position(input.length()),
		  tempArray(input.length()),
		  lcpArray(input.length()),
		  sparseTable(input.length(), vector<int>(LOG + 1, 0))
	{

		buildSuffixArray();
		if (buildLCP)
			buildLCPArray();
	}

	// Query LCP between two positions
	int queryLCP(int left, int right) const // 0-based
	{
		if (left == right)
			return length - left - 1;
		left = position[left];
		right = position[right];
		if (left > right)
			swap(left, right);
		right--;

		int rangeLength = right - left + 1;
		int k = 31 - __builtin_clz(rangeLength);
		return min(sparseTable[left][k], sparseTable[right - (1 << k) + 1][k]);
	}
	// Compare two substrings of the same string in O(1)
	bool compareSubstrings(const pair<int, int> &str1, const pair<int, int> &str2, bool equal = false) const
	{
		auto [i, j] = str1;
		auto [k, l] = str2;

		int len1 = j - i + 1;
		int len2 = l - k + 1;
		int LCP = queryLCP(i, k);
		// Check if LCP is sufficient to determine the ordering
		if (LCP >= min(len1, len2))
			return (equal ? len1 >= len2 : len1 > len2);

		// Otherwise, compare characters at the point of difference
		return S[i + LCP] > S[k + LCP];
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
		string str;
		cin >> str;
		str += (char(31));
		SuffixArray suffArr(str, true);

		cin >> Q;
		vector<pair<int, int>> vc;
		while (Q--)
		{
			int L, R;
			cin >> L >> R;
			vc.push_back({--L, --R});
		}

		auto compare = [&](const pair<int, int> &P1, const pair<int, int> &P2) // To compare two substrings `of the same string` in O(1)
		{
			const auto &[i, j] = P1;
			const auto &[k, l] = P2;

			int len1 = j - i + 1, len2 = l - k + 1;
			int LCP = suffArr.queryLCP(i, k);

			// Check if LCP is sufficient to determine the ordering
			if (LCP >= min(len1, len2))
			{
				if (len1 == len2)
				{
					// If lengths are equal, compare indices to ensure a strict order
					if (i != k)
						return i < k;
					return j < l;
				}
				return len1 < len2; // Shorter substring comes first
			}

			// Otherwise, compare characters at the point of difference
			return str[i + LCP] < str[k + LCP];
		};

		sort(vc.begin(), vc.end(), compare);
		for (auto &[l, r] : vc)
			cout << ++l << " " << ++r << endl;
	}
	return 0;
}