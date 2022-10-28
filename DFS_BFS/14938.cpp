#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

int	dp[101][101];

void	dijsktra(vector<pii> graph[101], int startNode)
{
	priority_queue<pii>	pq;

	pq.push({ 0, startNode });
	dp[startNode][startNode] = 0;
	while (!pq.empty())
	{
		int currentLen = -pq.top().first;
		int	currentNode = pq.top().second;
		pq.pop();

		if (dp[startNode][currentNode] < currentLen)
			continue ;
		for (auto next: graph[currentNode])
		{
			int	nextLen = next.second + currentLen;
			int nextNode = next.first;

			if (nextLen < dp[startNode][nextNode])
			{
				pq.push({ -nextLen, nextNode });
				dp[startNode][nextNode] = nextLen;
			}
		}

	}
}

int	get_sum_from_node_with_dijkstra(vector<int> item, int node, int n, int m)
{
	int	sum;

	sum = 0;
	for (int i=1; i<=n; i++)
	{
		if (dp[node][i] <= m)
			sum += item[i - 1];
	}
	return (sum);
}

int	main(void)
{
	int	n, m, r;
	int	answer;
	vector<int>	item;
	vector<pii>	graph[101];

	cin >> n >> m >> r;
	item.resize(n + 1);
	memset(dp, 1, sizeof(dp));
	for (int i=0; i<n; i++)
		cin >> item[i];
	for (int i=0; i<r; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[a].push_back({ b, cost });
		graph[b].push_back({ a, cost });
	}

	for (int i=1; i<=n; i++)
	{
		dijsktra(graph, i);
	}
	answer = 0;
	for (int i=1; i<=n; i++)
	{
		answer = max(answer, get_sum_from_node_with_dijkstra(item, i, n, m));
	}
	cout << answer;
}
