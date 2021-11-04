#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

const int MAX = 987654321;

void	fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool	is_cycle_in_beintman_ford(int N, vector<vector<pii>> &graph)
{
	int			nextNode, nextCost;
	bool		isCycle;
	vector<int>	dist;
	
	dist.resize(N + 1, MAX);
	dist[1] = 0;
	isCycle = false;
	for (int i=1; i<=N; i++)
	{
		for (int j=1; j<=N; j++)
		{
			for (auto next: graph[j])
			{
				nextNode = next.first;
				nextCost = next.second + dist[j];
				if (dist[nextNode] > nextCost)
				{
					dist[nextNode] = nextCost;
					if (i == N)
						isCycle = true;
				}
			}
		}
	}
	return (isCycle);
}

void	get_solution(void)
{
	int					TestCase;
	int					N, M, W;
	int					S, E, T;
	bool				isCycle;
	vector<vector<pii>>	graph;

	cin >> TestCase;
	while (TestCase--)
	{
		cin >> N >> M >> W;
		graph.resize(N + 1);
		while (M or W)
		{
			cin >> S >> E >> T;
			if (M)
			{
				graph[S].push_back({E, T});
				graph[E].push_back({S, T});
				M--;
			}
			else
			{
				graph[S].push_back({E, -T});
				W--;
			}
		}
		isCycle = is_cycle_in_beintman_ford(N, graph);
		if (isCycle)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}

int	main(void)
{
	fastIO();
	get_solution();
}
