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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		char mark;
		vector<vector<int>> Std_Marks(N, vector<int>(M));
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < M; j++)
			{
				cin >> mark;
				Std_Marks[i][j] = mark - '0'; // Converting a digit character to the corresponding number
			}
		}
		int cnt{};
		for (int i{}; i < N; i++) // Traversing Students
		{
			for (int j{}; j < M; j++) // Traversing Subjects
			{
				bool flag = true;
				for (int k{}; k < N; k++) // Traversing the same subject for all other students
				{
					if (Std_Marks[i][j] < Std_Marks[k][j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					cnt++;
					goto Out;
				}
			}

		Out:
			continue;
		}
		cout << cnt;
	}
	return 0;
}
