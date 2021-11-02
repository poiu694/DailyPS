#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

void fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<ll> get_prefix_sum_list(ll N, vector<ll> &list)
{
	vector<ll> sumList;

	sumList.resize(N + 1, 0);
	sumList[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		sumList[i] = sumList[i - 1] + list[i];
	}
	return (sumList);
}

vector<ll> get_prefix_pow_sum_list(ll N, vector<ll> &list)
{
	vector<ll> powSumList;

	powSumList.resize(N + 1, 0);
	powSumList[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		powSumList[i] = powSumList[i - 1] + (list[i] * list[i]);
	}
	return (powSumList);
}

ll get_ans(ll l, ll r, vector<ll> &sumList, vector<ll> &powSumList)
{
	return ((((sumList[r] - sumList[l - 1]) * (sumList[r] - sumList[l - 1])) - (powSumList[r] - powSumList[l - 1])) / 2);
}

void get_solution(void)
{
	ll N, Q;
	ll l, r;
	ll ans;
	vector<ll> list;
	vector<ll> sumList, powSumList;

	cin >> N >> Q;
	list.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> list[i];
	sumList = get_prefix_sum_list(N, list);
	powSumList = get_prefix_pow_sum_list(N, list);
	while (Q--)
	{
		cin >> l >> r;
		ans = get_ans(l, r, sumList, powSumList);
		cout << ans << '\n';
	}
}

int main(void)
{
	fastIO();
	get_solution();
}
