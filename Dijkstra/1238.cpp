#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#include <queue>

using namespace std;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int> ft_get_dijkstra(int node, int N, vector<pair<int, int> > graph[])
{
	int								nowNode, nowDist;
	int								nextNode, nextDist;
	vector<int>						ret;
	priority_queue<pair<int, int> >	pq;

	ret.resize(N+1, INT_MAX);
	pq.push({0, node});
	ret[node] = 0;
	while (!pq.empty())
	{
		nowDist = -pq.top().first;
		nowNode = pq.top().second;
		pq.pop();

		if (nowDist > ret[nowNode])
			continue;
		for (auto next : graph[nowNode])
		{
			nextNode = next.first;
			nextDist = next.second;
			if (nowDist + nextDist < ret[nextNode])
			{
				ret[nextNode] = nowDist + nextDist;
				pq.push({-ret[nextNode], nextNode});
			}
		}
	}
	return (ret);
}

int	ft_get_max_dist(int N, vector<int> list1, vector<int> list2)
{
	int	ret;

	ret = -1;
	for (int i=1; i<=N; i++)
	{
		if (ret < list1[i] + list2[i])
			ret = list1[i] + list2[i];
	}
	return (ret);
}

void	ft_get_solution(void)
{
	int						a, b, cost;
	int						N, M, X;
	vector<int>				dist, reverseDist;
	vector<pair<int, int> >	path[1001], reversePath[1001];
	
	cin >> N >> M >> X;
	for (int i=0; i<M; i++)
	{
		cin >> a >> b >> cost;
		path[a].push_back({b, cost});
		reversePath[b].push_back({a, cost});
	}
	dist = ft_get_dijkstra(X, N, path);
	reverseDist = ft_get_dijkstra(X, N, reversePath);
	cout << ft_get_max_dist(N, dist, reverseDist);
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}
