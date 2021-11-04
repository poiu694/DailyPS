#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAX = 987654321;

void	fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

vector<ll>	get_bellman_ford_dist(int N, vector<vector<pii>> &graph)
{
	ll			nextNode, nextCost;
	bool		is_cycle;
	vector<ll>	dist;

	dist.resize(N + 1, MAX);
	dist[1] = 0;
	is_cycle = false;
	for (int i=1; i<=N; i++)
	{
		for (int j=1; j<=N; j++)
		{
			for (auto next: graph[j])
			{
				nextNode = next.first;
				nextCost = next.second + dist[j];
				if (dist[j] != MAX and dist[nextNode] > nextCost)
				{
					dist[nextNode] = nextCost;
					if (i == N)
						is_cycle = true;
				}
			}
		}
	}
	if (is_cycle)
		return {};
	for (int i=1; i<=N; i++)
		if (dist[i] == MAX)
			dist[i] = -1;
	return (dist);
}

void	print_solution(int N, vector<ll> &dist)
{
	if (dist.empty())
		cout << "-1";
	else
	{
		for (int i=2; i<=N; i++)
			cout << dist[i] << '\n';
	}
}

void	get_solution(void)
{
	int					N, M;
	int					A, B, C;
	vector<ll>			dist;
	vector<vector<pii>>	graph;

	cin >> N >> M;
	graph.resize(N + 1);
	while (M--)
	{
		cin >> A >> B >> C;
		graph[A].push_back({B, C});
	}
	dist = get_bellman_ford_dist(N, graph);
	print_solution(N, dist);
}

int	main(void)
{
	fastIO();
	get_solution();
}
