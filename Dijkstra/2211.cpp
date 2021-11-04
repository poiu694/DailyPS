#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits.h>

using namespace std;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>	ft_get_path_from_dijkstra(vector<vector<pair<int, int>> > &graph, int node, int N)
{
	int								nowNode, nowCost;
	int								nextNode, nextCost;
	priority_queue<pair<int, int> > pq;
	vector<int>						dist, ret;

	dist.resize(N + 1, INT_MAX);
	ret.resize(N + 1, -1);
	pq.push({0, node});
	dist[node] = 0;
	while (!pq.empty())
	{
		nowCost = -pq.top().first;
		nowNode = pq.top().second;
		pq.pop();

		if (dist[nowNode] < nowCost)
			continue ;
		for (auto next : graph[nowNode])
		{
			nextNode = next.first;
			nextCost = next.second + nowCost;
			if (dist[nextNode] > nextCost)
			{
				dist[nextNode] = nextCost;
				ret[nextNode] = nowNode;
				pq.push({-nextCost, nextNode});
			}
		}
	}
	return (ret);
}

vector<pair<int, int> >	ft_get_answer_from_path(vector<int> &path, int N)
{
	vector<pair<int, int> >	ret;
	int						index;

	ret.resize(N - 1);
	index = 0;
	for (int i=1; i<=N; i++)
	{
		if (path[i] != -1)
		{
			ret[index] = {i, path[i]};
			index++;
		}
	}
	return (ret);
}

void	ft_print_solution(vector<pair<int, int> > &ans)
{
	cout << ans.size() << '\n';
	for (int i=0; i<ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
}

void	ft_get_solution(void)
{
	int								N, M;
	int								a, b, cost;
	vector<vector<pair<int, int>> >	graph;
	vector<pair<int, int> >			ans;
	vector<int>						path;

	cin >> N >> M;
	graph.resize(N + 1);
	for (int i=0; i<M; i++)
	{
		cin >> a >> b >> cost;
		graph[a].push_back({b, cost});
		graph[b].push_back({a, cost});
	}
	path = ft_get_path_from_dijkstra(graph, 1, N);
	ans = ft_get_answer_from_path(path, N);
	ft_print_solution(ans);
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}
