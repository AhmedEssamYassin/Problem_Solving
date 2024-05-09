#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Student
{
	string Name;
	int Total_grade;
};
bool predicate_function(const pair<Student, array<int, 4>> &P1, const pair<Student, array<int, 4>> &P2)
{
	if (P1.first.Total_grade == P2.first.Total_grade)
		return (P1.first.Name < P2.first.Name);
	else
		return (P1.first.Total_grade > P2.first.Total_grade);
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
	vector<pair<Student, array<int, 4>>> List(N);
	for (int i{}; i < N; i++)
	{
		cin >> List[i].first.Name;
		int Sum_of_grades{};
		for (int j{}; j < 4; j++)
		{
			cin >> List[i].second[j];
			Sum_of_grades += List[i].second[j];
		}
		List[i].first.Total_grade = Sum_of_grades;
	}
	sort(List.begin(), List.end(), predicate_function);
	for (const auto &student : List)
	{
		cout << student.first.Name << " " << student.first.Total_grade << " ";
		for (int i{}; i < 4; i++)
			cout << student.second[i] << " \n"[i == 3];
	}
	return 0;
}