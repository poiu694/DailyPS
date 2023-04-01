#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

# define MAX 987654321

using namespace std;
using pii = pair<int, int>;

int	V, E, P;
vector<pii>	graph[5001];

vector<int>	dijkstra(int start)
{
	priority_queue<pii>	pq; // cost, node
	vector<int>	dist(V + 1, MAX); // 최단거리 저장

	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < cost)
			continue ;
		for (auto next: graph[node])
		{
			int nextCost = cost + next.second;
			int nextNode = next.first;

			if (dist[nextNode] > nextCost)
			{
				dist[nextNode] = nextCost;
				pq.push({ -nextCost, nextNode });
			}
		}
	}
	return (dist);
}

int	main(void)
{
	vector<int>	distFromOne;
	vector<int>	distFromP;

	cin >> V >> E >> P;
	while (E--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	distFromOne = dijkstra(1);
	distFromP = dijkstra(P);
	if (P == 1 || distFromOne[P] + distFromP[V] == distFromOne[V])
		cout << "SAVE HIM";
	else
		cout << "GOOD BYE";
}
