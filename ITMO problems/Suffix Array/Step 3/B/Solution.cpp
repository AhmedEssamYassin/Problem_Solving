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
};

ll countSubstrings(const SuffixArray &suffArr, const string &str, const string &subStr)
{
	// A substring is a prefix of some suffix
	int last = str.length(), first = -1;
	// Upper bound
	{
		int L{}, R = str.length() - 1;
		while (L <= R)
		{
			int mid = ((L + R) >> 1);
			if (str.substr(suffArr.suffixArray[mid], subStr.size()) > subStr)
				last = mid, R = mid - 1;
			else
				L = mid + 1;
		}
	}
	// Lower bound
	{
		int L{}, R = str.length() - 1;
		while (L <= R)
		{
			int mid = ((L + R) >> 1);
			if (str.substr(suffArr.suffixArray[mid], subStr.size()) >= subStr)
				first = mid, R = mid - 1;
			else
				L = mid + 1;
		}
	}
	if (~first)
		return last - first;
	else
		return 0;
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
		string str;
		cin >> str;
		str += SENTINEL;
		SuffixArray suffArr(str);
		cin >> N;
		while (N--)
		{
			string s;
			cin >> s;
			cout << countSubstrings(suffArr, str, s) << endl;
		}
	}
	return 0;
}