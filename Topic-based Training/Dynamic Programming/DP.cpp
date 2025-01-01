#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
DP Styles:
1- Counting
2- Minimization (Unbounded knapsack problem)
3- Memoization (Easy logic,but inefficient memory)
4- 01 knapsack (take or leave)


Row-major accessing and Column-major accessing
----------------------------------------------
Modern CPUs are designed to minimize the time it takes to access data.
To achieve this, CPUs use caches, which store chunks of memory (typically 64 bytes) close to the processor.
When a program accesses memory:
- The CPU loads nearby memory into the cache in one operation. This is called spatial locality.
- Accessing consecutive elements in memory is faster because they are likely already in the cache.

Row-major accessing is efficient because elements in the same row (dp[i][0] ... dp[i][x]) are accessed contiguously.
Column-major accessing is less efficient because jumping between rows for each dp[x][i] can cause cache misses.
Impact of Cache Misses
L1 Cache Access: Takes ~4 cycles.
L2 Cache Access: Takes ~10 cycles.
Main Memory Access: Can take hundreds of cycles.
----------------------------------------------
CSES
https://leetcode.com/problems/count-square-submatrices-with-all-ones/
https://leetcode.com/problems/burst-balloons/
https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
https://www.hackerrank.com/contests/cmp2030-f24-lab5-ssection1/challenges/superhero-teams-1/problem
https://codeforces.com/gym/104168/problem/D2
https://codeforces.com/contest/455/problem/A
https://codeforces.com/problemset/problem/476/B
https://codeforces.com/contest/977/problem/F
https://codeforces.com/problemset/problem/1547/E
https://codeforces.com/contest/5/submission/295945930
https://codeforces.com/gym/101020/problem/D
https://codeforces.com/problemset/problem/1974/E
https://codeforces.com/problemset/problem/1703/G
https://codeforces.com/group/Rilx5irOux/contest/527020/problem/B
https://codeforces.com/problemset/problem/2050/E
https://codeforces.com/contest/2050/problem/C
https://codeforces.com/contest/2050/problem/E


https://codeforces.com/contest/1946/problem/B --> Kaden's
*/

int cutRodIter(vector<int> &price)
{
    int n = price.size();
    vector<int> dp(price.size() + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
    }

    return dp[n];
}

int cutRodRecur(vector<int> &price, vector<int> &memo, int len)
{
    // Base case
    if (len == 0)
        return 0;
    int &ret = memo[len - 1];
    // If value is memoized
    if (~ret)
        return ret;

    int ans = 0;

    for (int j = 1; j <= len; j++)
        ans = max(ans, price[j - 1] + cutRodRecur(price, memo, len - j));

    return ret = ans;
}

// Push loop to parameter
int cutRodRecur(vector<int> &price, vector<vector<int>> &memo, int j, int len)
{
    // Base case
    if (len <= 0 || j > price.size())
        return 0;
    int &ret = memo[j][len - 1];
    // If value is memoized
    if (~ret)
        return ret;

    int cut = 0;
    if (len >= j)
        cut = price[j - 1] + cutRodRecur(price, memo, j, len - j);
    int notCut = cutRodRecur(price, memo, j + 1, len);

    return ret = max(cut, notCut);
}
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    return cutRodRecur(price, memo, 1, n);
}

int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<int> memo(price.size(), -1);
    return cutRodRecur(price, memo, n);
}

const int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N, m;
    // cin >> t;
    while (t--)
    {
    }
    return 0;
}