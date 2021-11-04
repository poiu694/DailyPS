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

vector<vector<int>> get_floyd_warshall_dist(int N, vector<vector<int>> &dist)
{
	for (int k=1; k<=N; k++)
		for (int i=1; i<=N; i++)
			for (int j=1; j<=N; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	return (dist);			
}

void	print_dist(int N, vector<vector<int>> &dist)
{
	for (int i=1; i<=N; i++)
	{
		for (int j=1; j<=N; j++)
		{
			if (dist[i][j] == MAX)
				cout << 0 << " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}

void	get_solution(void)
{
	int					N, M;
	int					A, B, C;
	vector<vector<int>>	dist;

	cin >> N >> M;
	dist.resize(N + 1, vector<int>(N + 1, MAX));
	while (M--)
	{
		cin >> A >> B >> C;
		if (dist[A][B] > C)
			dist[A][B] = C;
	}
	for (int i=1; i<=N; i++)
		dist[i][i] = 0;
	dist = get_floyd_warshall_dist(N, dist);
	print_dist(N, dist);
}

int	main(void)
{
	fastIO();
	get_solution();
}
