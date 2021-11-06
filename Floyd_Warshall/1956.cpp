#include <iostream>
#include <vector>

using namespace std;

const int MAX = 987654321;

void	fastIO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void	update_dist_with_floyd(int V, vector<vector<int>> &dist)
{
	for (int k=1; k<=V; k++)
		for (int i=1; i<=V; i++)
			for (int j=1; j<=V; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}

int	get_min_cycle_dist(int V, vector<vector<int>> &dist)
{
	int	ret;

	ret = MAX;
	for (int i=1; i<=V; i++)
		for (int j=1; j<=V; j++)
			if (dist[i][j] != MAX and dist[j][i] != MAX)
				if (ret > dist[i][j] + dist[j][i])
					ret = dist[i][j] + dist[j][i];
	if (ret == MAX)
		return (-1);
	return (ret);
}

void	get_solution(void)
{
	int					V, E;
	int					st, ed, cost;
	int					ans;
	vector<vector<int>>	dist;

	cin >> V >> E;
	dist.resize(V + 1, vector<int>(V + 1, MAX));
	while (E--)
	{
		cin >> st >> ed >> cost;
		dist[st][ed] = cost;
	}
	update_dist_with_floyd(V, dist);
	ans = get_min_cycle_dist(V, dist);
	cout << ans;
} 

int	main(void)
{
	fastIO();
	get_solution();
}

