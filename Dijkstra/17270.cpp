#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
using pii = pair<int, int>;

int	V, M;
vector<pii>	graph[101];

vector<int>	dijkstra(int start_node)
{
	vector<int>	ret;
	priority_queue<pii>	pq; // -cost, node

	ret.resize(V + 1, INT_MAX);
	ret[start_node] = 0;
	pq.push({ 0, start_node });
	while (!pq.empty())
	{
		int	cost = -pq.top().first;
		int	node = pq.top().second;
		pq.pop();

		if (ret[node] < cost)
			continue ;
		for (pii next: graph[node])
		{
			int next_node = next.first;
			int next_cost = next.second;

			if (cost + next_cost < ret[next_node])
			{
				pq.push({ -(cost + next_cost), next_node });
				ret[next_node] = cost + next_cost;
			}
		}
	}
	return (ret);
}

int	main(void)
{
	int	J, S;
	int	answer_node, answer_cost, answer_jiheon_cost;
	vector<int>	jiheon_dist;
	vector<int>	seongha_dist;
	priority_queue<pii>	answer_list;

	cin >> V >> M;
	for (int i=0; i<M; i++)
	{
		int	A, B, C;

		cin >> A >> B >> C;
		graph[A].push_back({ B, C });
		graph[B].push_back({ A, C });
	}
	cin >> J >> S;

	jiheon_dist = dijkstra(J);
	seongha_dist = dijkstra(S);
	answer_node = -1;
	answer_cost = INT_MAX;
	answer_jiheon_cost = INT_MAX;
	for (int node=1; node<=V; node++)
	{
		if (node == J || node == S)
			continue ;
		if (jiheon_dist[node] + seongha_dist[node] > answer_cost)
			continue ;
		answer_cost = jiheon_dist[node] + seongha_dist[node];
	}
	for (int node=1; node<=V; node++)
	{
		if (node == J || node == S)
			continue ;
		if (jiheon_dist[node] + seongha_dist[node] == answer_cost)
		{
			answer_list.push({ -jiheon_dist[node], node });
		}
	}
	while (!answer_list.empty())
	{
		int cost = answer_list.top().first;
		int node = answer_list.top().second;
		answer_list.pop();

		if (jiheon_dist[node] > seongha_dist[node])
			continue ;
		cout << node;
		return (0);
	}
	cout << -1;
}
