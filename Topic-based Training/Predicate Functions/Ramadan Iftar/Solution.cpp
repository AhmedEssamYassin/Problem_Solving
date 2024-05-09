#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Data
{
	int numberOfMembers;
	int income;
	long double incomePerPerson;
	int index;
};
bool predicateFunc(Data &P1, Data &P2)
{
	if (P1.incomePerPerson < P2.incomePerPerson)
		return true;

	else if (P1.incomePerPerson == P2.incomePerPerson)
	{
		if (P1.numberOfMembers > P2.numberOfMembers)
			return true;
		else if (P1.numberOfMembers == P2.numberOfMembers)
		{
			if (P1.index < P2.index)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
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
	int N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<Data> families(N);
		for (int i{}; i < N; i++)
		{
			cin >> families[i].numberOfMembers >> families[i].income;
			families[i].incomePerPerson = (((long double)families[i].income) / families[i].numberOfMembers);
			families[i].index = i + 1;
		}
		sort(families.begin(), families.end(), predicateFunc);
		for (const Data &Family : families)
			cout << Family.index << " ";
		// cout << Family.numberOfMembers << " " << Family.income << " " << Family.incomePerPerson << " " << Family.index << endl;
	}
	return 0;
}