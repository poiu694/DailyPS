#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

void	fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int	is_possible(vector<pair<int, int> > &list, int p)
{
	int	sum;

	sum = 0;
	for (int i=0; i<list.size(); i++)
		sum += list[i].first;
	if (sum < p)
		return (0);
	return (1);
}

vector<pii>	get_quota_list(vector<pii> &list, int p)
{
	vector<pii>	ret;
	int			sum;

	ret.resize(list.size());
	sum = p;
	for (int i=0; i<list.size(); i++)
	{
		ret[i] = { min(list[i].first, (int) (sum / (list.size() - i))), list[i].second };
		sum = sum - ret[i].first;
	}
	return (ret);
}

bool	cmp2(pii a, pii b)
{
	if (a.first == b.first)
		return (a.second > b.second);
	return (a.first < b.first);
}

bool	cmp(pii a, pii b)
{
	return (a.second < b.second);
}

void	solution(void)
{
	int			t;
	int			p, n;
	int			input;
	vector<pii>	list, ans;

	cin >> t;
	while (t--)
	{
		list.clear();
		cin >> p >> n;
		list.resize(n);
		for (int i=0; i<n; i++)
		{
			cin >> input;
			list[i] = {input, i};
		}
		if (!is_possible(list, p))
		{
			cout << "IMPOSSIBLE\n";
			continue ;
		}
		sort(list.begin(), list.end(), cmp2);
		ans = get_quota_list(list, p);
		sort(ans.begin(), ans.end(), cmp);
		for (int i=0; i<n; i++)
			cout << ans[i].first << " ";
		cout << '\n';
	}
}

int	main(void)
{
	fast_io();
	solution();
}
