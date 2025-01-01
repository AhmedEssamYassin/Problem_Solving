#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll n;
    // cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> lcp;

        stack<int> St;

        // Elements can repeat but indices can NEVER, so instead of storing elements, store indices!
        vector<int> NGE(n, -1), NSE(n, -1), PSE(n, -1); // Next Smaller Element, Previous Smaller Element

        // Indices of NSE[], PSE[] represent indices of lcp[] and their values are the index of their NSE, PSE
        // Default value of all indices is -1 , so that if NO greater element found, they will be -1

        // Compute Next Smaller Element (NSE)
        for (int i = 0; i < n; i++)
        {
            while (!St.empty() && lcp[i] < lcp[St.top()])
            {
                NSE[St.top()] = i; // Store the index of the next smaller element
                St.pop();
            }
            St.push(i);
        }

        // Clear the stack for the next computation
        while (!St.empty())
            St.pop();

        // Compute Previous Smaller Element (PSE)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!St.empty() && lcp[i] < lcp[St.top()])
            {
                PSE[St.top()] = i; // Store the index of the previous smaller element
                St.pop();
            }
            St.push(i);
        }

        // Clear the stack for the next computation
        while (!St.empty())
            St.pop();

        // Compute Next Greater Element (NGE)
        for (int i = 0; i < n - 1; i++)
        {
            while (!St.empty() && lcp[i] > lcp[St.top()])
            {
                NGE[St.top()] = i; // Store the index of the next greater element
                St.pop();
            }
            St.push(i);
        }
    }
    return 0;
}