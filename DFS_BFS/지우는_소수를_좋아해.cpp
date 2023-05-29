#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;
using pii = pair<int, int>;

int	N, M;
vector<pii>	graph[10005];
int	visited[10005];

int	bfs(void)
{
	int	result;
	queue<pii>	q; // node, cost

	result = INT_MAX;
	q.push({ 1, 0 });
	for (int i=1; i<=N; i++)
		visited[i] = INT_MAX;
	visited[1] = 0;
	while (!q.empty())
	{
		int	node = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (node == N)
		{
			result = min(result, cost);
		}
		for (pii next: graph[node])
		{
			int nextNode = next.first;
			int nextCost = next.second;
			int c = max(cost, nextCost);

			if (visited[nextNode] > c)
			{
				visited[nextNode] = c;
				q.push({ nextNode, c });
			}
		}
	}
	return (result);
}

int	find_next_prime(int num)
{
	int	target;
	bool	flag;

	target = num + 1;
	while (target - num < 300)
	{
		flag = true;
		if (target % 2 != 0)
		{
			for (int i=3; i<=sqrt(target); i+=2)
			{
				if (target % i == 0)
				{
					flag = false;
					break ;
				}
			}
			if (flag)
				return (target);
		}
		target++;
	}
	return (target);
}

int	main(void)
{
	cin >> N >> M;

	for (int i=0; i<M; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		graph[a].push_back({ b, cost });
		graph[b].push_back({ a, cost });
	}
	cout << find_next_prime(bfs());
}
