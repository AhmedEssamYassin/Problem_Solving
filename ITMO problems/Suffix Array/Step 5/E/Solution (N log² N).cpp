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

	bool comparePositions(int i, int j) const
	{
		if (position[i] != position[j])
			return position[i] < position[j];
		i += gap;
		j += gap;
		return (i < length && j < length) ? position[i] < position[j] : i > j;
	}

	void buildSuffixArray()
	{
		for (int i = 0; i < length; i++)
		{
			suffixArray[i] = i;
			position[i] = S[i];
		}

		auto comparator = [&](int a, int b)
		{
			return comparePositions(a, b);
		};
		for (gap = 1;; gap <<= 1)
		{
			sort(suffixArray.begin(), suffixArray.begin() + length, comparator);

			for (int i = 0; i < length - 1; i++)
				tempArray[i + 1] = tempArray[i] + comparePositions(suffixArray[i], suffixArray[i + 1]);

			for (int i = 0; i < length; i++)
				position[suffixArray[i]] = tempArray[i];

			if (tempArray[length - 1] == length - 1)
				break;
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

pair<ll, string> findRefrain(const SuffixArray &suffArr, const string &str)
{
	stack<int> monoStack;
	const int n = suffArr.lcpArray.size();
	ll maxArea = str.length() - 1;
	string res = str;
	res.pop_back(); // Removing the SENTINEL
	for (int i = 0; i <= n; i++)
	{
		ll x = (i == n ? 0 : suffArr.lcpArray[i]);
		while (!monoStack.empty() && suffArr.lcpArray[monoStack.top()] > x)
		{
			ll tp = monoStack.top();
			monoStack.pop();
			ll h = suffArr.lcpArray[tp], w = (monoStack.empty() ? i : i - 1 - monoStack.top());
			ll area = h * (w + 1); // because it's LCP, actually it's `w + 1` substrings
			if (area > maxArea)
			{
				maxArea = area;
				res = str.substr(suffArr.suffixArray[i - w], h);
			}
		}
		monoStack.push(i);
	}
	return {maxArea, res};
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
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		string str("");
		for (int i{}; i < N; i++)
		{
			ll d; // note that 1 <= d <= 10, so using char would lead to WA
			cin >> d;
			str += char(d + 'a');
		}
		str += SENTINEL;
		SuffixArray suffArr(str, true);

		auto refrainResult = findRefrain(suffArr, str);
		cout << refrainResult.first << endl;
		cout << refrainResult.second.length() << endl;
		for (const auto &c : refrainResult.second)
		{
			int digit = c - 'a';
			cout << digit << " ";
		}
		cout << endl;
	}
	return 0;
}