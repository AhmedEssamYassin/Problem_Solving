#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isPrime(const ll &N)
{
	if (N < 2)
		return false;
	if (N < 4)
		return true;
	if (N % 2 == 0 || N % 3 == 0)
		return false;
	for (ll i{5}; i * i <= N; i += 6)
	{
		if (N % i == 0 || N % (i + 2) == 0)
			return false;
	}
	return true;
}

bool isPalindrome(const ll &N)
{
	ll rev = 0;
	ll k = N;
	while (k)
	{
		rev = (rev * 10) + (k % 10);
		k /= 10; // drop last digit
	}

	return (N == rev);
}

ll minElement(const vector<ll> &vc)
{
	ll mn = LLONG_MAX;
	for (int i{}; i < vc.size(); i++)
		mn = min(mn, vc[i]);
	return mn;
}

ll maxElement(const vector<ll> &vc)
{
	ll mx = LLONG_MIN;
	for (int i{}; i < vc.size(); i++)
		mx = max(mx, vc[i]);
	return mx;
}

ll countPrimes(const vector<ll> &vc)
{
	int cnt{};
	for (int i{}; i < vc.size(); i++)
		cnt += isPrime(vc[i]);
	return cnt;
}

ll countPalindromes(const vector<ll> &vc)
{
	int cnt{};
	for (int i{}; i < vc.size(); i++)
		cnt += isPalindrome(vc[i]);
	return cnt;
}

int maxNumberOfDivisors(const vector<ll> &vc)
{
	int max{}, ans{};
	for (int i = 0; i < vc.size(); i++)
	{
		int cnt{};
		for (int j = 1; j * j <= vc[i]; j++)
		{
			if (vc[i] % j == 0)
			{
				if (vc[i] / j == j)
					cnt++;
				else
					cnt += 2;
			}
		}

		if (cnt > max)
		{
			max = cnt;
			ans = vc[i];
		}
		else if (cnt == max)
		{
			if (vc[i] > ans)
				ans = vc[i];
		}
	}
	return ans;
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
		cin >> N;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		cout << "The maximum number : " << maxElement(a) << endl;
		cout << "The minimum number : " << minElement(a) << endl;
		cout << "The number of prime numbers : " << countPrimes(a) << endl;
		cout << "The number of palindrome numbers : " << countPalindromes(a) << endl;
		cout << "The number that has the maximum number of divisors : " << maxNumberOfDivisors(a);
	}
	return 0;
}