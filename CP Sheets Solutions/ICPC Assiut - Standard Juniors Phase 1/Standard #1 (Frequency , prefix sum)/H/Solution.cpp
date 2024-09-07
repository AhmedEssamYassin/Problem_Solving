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
#endif // !ONLINE_JUDGE

	int Q, L, R;
	string Input;
	cin >> Input;

	uint64_t *Prefix_Freq_arr{new uint64_t[Input.length()]{0}};
	Prefix_Freq_arr[0] = (Input.front() == 'a');
	for (int i{1}; i < Input.length(); i++)
		Prefix_Freq_arr[i] += Prefix_Freq_arr[i - 1] + (Input[i] == 'a');

	cin >> Q;
	while (Q--)
	{
		cin >> L >> R; // 1-based

		L--, R--; // To make them 0-based
		cout << Prefix_Freq_arr[R] - (L > 0 ? Prefix_Freq_arr[L - 1] : 0) << endl;
	}
	delete[] Prefix_Freq_arr;
	return 0;
}