#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// Counting inversions using merge Sort
ll countInversions{};
void merge(vector<ll> &vc, int left, int mid, int right)
{
    int p = left, q = mid + 1; // To traverse the left and the right segment respectively
    vector<ll> temp;
    for (int i{left}; i <= right; i++)
    {
        if (p > mid) // First segment comes to an end
            temp.push_back(vc[q++]);
        else if (q > right) // Second segment comes to an end
            temp.push_back(vc[p++]);
        else if (vc[p] <= vc[q]) // The first segment has the smaller element
            temp.push_back(vc[p++]);
        else // The second segment has the smaller element
        {
            countInversions += (mid - p + 1);
            temp.push_back(vc[q++]);
        }
    }

    // Overwriting the original elements in a sorted manner
    for (int i = 0; i < temp.size(); i++)
        vc[left++] = temp[i];
}

void mergeSort(vector<ll> &vc, int left, int right) // left and right are 0-based
{
    if (left < right)
    {
        int mid = ((left + right) >> 1);
        mergeSort(vc, left, mid);
        mergeSort(vc, mid + 1, right);
        merge(vc, left, mid, right);
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
    int N;
    cin >> N;
    vector<ll> vc(N);
    for (int i{}; i < N; i++)
        cin >> vc[i];
    mergeSort(vc, 0, N - 1);
    cout << countInversions;
    return 0;
}