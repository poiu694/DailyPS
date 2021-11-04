#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace	std;

void	ft_fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<int>	ft_get_dijkstra_dist(int N, int stCity, vector<vector<pair<int, int>> > &graph, vector<int> &path)
{
	int								nowNode, nowCost;
	int								nextNode, nextCost;
	priority_queue<pair<int, int> > pq;
	vector<int>						ret;

	ret.resize(N+1, INT_MAX);
	pq.push({0, stCity});
	ret[stCity] = 0;
	while (!pq.empty())
	{
		nowNode = pq.top().second;
		nowCost = -pq.top().first;
		pq.pop();

		if (ret[nowNode] < nowCost)
			continue ;
		for (auto next : graph[nowNode])
		{
			nextNode = next.first;
			nextCost = next.second + nowCost;
			if (nextCost < ret[nextNode])
			{
				path[nextNode] = nowNode;
				ret[nextNode] = nextCost;
				pq.push({-nextCost, nextNode});
			}
		}
	}
	return (ret);
}

vector<int>	ft_get_solution_path(int endCity, vector<int> &path)
{
	int			node;
	vector<int>	ret;

	node = endCity;
	while (node)
	{
		ret.push_back(node);
		node = path[node];
	}
	return (ret);
}

void	ft_print_solution(int endCity, vector<int> &dist, vector<int> &solutionPath)
{
	int	size;

	size = solutionPath.size()-1;
	cout << dist[endCity] << '\n';
	cout << solutionPath.size() << '\n';
	for (int i=size; i>=0; i--)
		cout << solutionPath[i] << " ";
}

void	ft_get_solution(void)
{
	int								N, M;
	int								a, b, cost;
	int								stCity, endCity;
	vector<int>						dist, path, solutionPath;
	vector<vector<pair<int, int>> >	graph;

	cin >> N >> M;
	graph.resize(N+1);
	path.resize(N+1);
	for (int i=0; i<M; i++)
	{
		cin >> a >> b >> cost;
		graph[a].push_back({b, cost});
	}
	cin >> stCity >> endCity;
	dist = ft_get_dijkstra_dist(N, stCity, graph, path);
	solutionPath = ft_get_solution_path(endCity, path);
	ft_print_solution(endCity, dist, solutionPath);
}

int	main(void)
{
	ft_fastIO();
	ft_get_solution();
}
