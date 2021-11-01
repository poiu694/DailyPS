#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

long long	ft_get_next(long long now, int i)
{
	if (i == 0) return (now * now);
	if (i == 1) return (now + now);
	if (i == 2) return (now - now);
	return (now / now);
}

string	ft_go_bfs(long long s, long long t)
{
	queue<pair<long long, string>>	q;
	long long						nowValue, nextValue;
	set<long long>					visited;
	string							nowString;

	q.push({s, ""});
	visited.insert(s);
	while(!q.empty())
	{
		nowValue = q.front().first;
		nowString = q.front().second;
		q.pop();

		if (nowValue == t)
		{
			return (nowString);
		}
		for (int i=0; i<4; i++)
		{
			nextValue = ft_get_next(nowValue, i);
			if (nextValue < 1) continue;
			if (visited.find(nextValue) != visited.end()) continue;
			visited.insert(nextValue);
			q.push({nextValue, nowString + "*+-/"[i]});
		}
	}
	return ("no");
}

bool	ft_is_zero(long long s, long long t)
{
	if (s == t)
		return (true);
	return (false);
}

void	ft_get_solution(void)
{
	long long	s, t;
	string		ans;

	cin >> s >> t;
	ans = ft_go_bfs(s, t);
	if (ft_is_zero(s, t))
		cout << "0";
	else if (ans == "no")
		cout << "-1";
	else
		cout << ans;
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}
