#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Employee
{
	string Name;
	int Salary;
};
bool predicate_function(const Employee &E1, const Employee &E2)
{
	if (E1.Salary == E2.Salary)
		return (E1.Name < E2.Name);
	else
		return (E1.Salary > E2.Salary);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int N;
	cin >> N;
	vector<Employee> List(N);
	for (int i{}; i < N; i++)
		cin >> List[i].Name >> List[i].Salary;

	sort(List.begin(), List.end(), predicate_function);
	for (const auto &employee : List)
		cout << employee.Name << " " << employee.Salary << "\n";

	return 0;
}