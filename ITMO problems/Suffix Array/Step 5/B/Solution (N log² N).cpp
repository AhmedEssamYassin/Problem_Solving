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

int pound;
int adjust(int x) // To guarantee it is NOT the suffix starting with the '#'
{
	if (x == pound)
		return INT_MAX;
	return x;
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
	ll N;
	// cin >> t;
	while (t--)
	{
		string arr[2];
		cin >> arr[0] >> arr[1];
		string str;
		str = arr[0] + '#' + arr[1] + '$';
		pound = arr[0].length();

		SuffixArray suffArr(str, true);

		// Classifying the SA[i], whether it belongs to the first or second string
		vector<int> Class(str.length());
		for (int i{}; i < str.length(); i++)
			Class[i] = 1 ^ (3 * (suffArr.suffixArray[i] > arr[0].length()));

		int maxLen = 0, idx = INT_MAX;
		for (int i{1}; i < str.length(); i++)
		{
			if (Class[i] != Class[i - 1]) // Suffixes of different strings
			{
				int cur = INT_MAX;
				if (suffArr.lcpArray[i - 1] > maxLen) // LCP of two suffixes gives a common substring between them
				{
					maxLen = suffArr.lcpArray[i - 1];
					cur = min(adjust(suffArr.suffixArray[i]), adjust(suffArr.suffixArray[i - 1]));
					if (cur != INT_MAX) // Checks if valid index
						idx = cur;
				}
				else if (suffArr.lcpArray[i - 1] == maxLen && cur < idx)
					idx = cur;
			}
		}
		if (idx != INT_MAX)
			cout << str.substr(idx, maxLen);
		else
			cout << "";
	}
	return 0;
}