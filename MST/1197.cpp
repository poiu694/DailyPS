#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

void	fast_io(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

int	get_answer(int V, vector<vector<pii>> &graph)
{
	int					nextNode, nextCost;
	int					nowNode, nowCost;
	int					ans;
	vector<bool>		visited;
	priority_queue<pii>	pq;

	visited.resize(V + 1, false);
	visited[1] = true;
	for (auto next: graph[1])
	{
		nextNode = next.first;
		nextCost = next.second;
		pq.push({-nextCost, nextNode});
	}
	ans = 0;
	while (!pq.empty())
	{
		nowCost = -pq.top().first;
		nowNode = pq.top().second;
		pq.pop();

		if (visited[nowNode])
			continue ;
		visited[nowNode] = true;
		ans = ans + nowCost;
		for (auto next: graph[nowNode])
		{
			nextNode = next.first;
			nextCost = next.second;
			pq.push({-nextCost, nextNode});
		}	
	}
	return (ans);
}

void	get_solution(void)
{
	int					a, b, c;
	int					V, E;
	int					ans;
	vector<vector<pii>>	graph;

	cin >> V >> E;
	graph.resize(V+1);
	while (E--)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	ans = get_answer(V, graph);
	cout << ans;
}

int	main(void)
{
	fast_io();
	get_solution();
}
