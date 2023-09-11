#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

# define START	1
# define GOAL	100

using namespace std;
using pii = pair<int, int>;

int	N, M;
int	visited[101];
vector<int>	ladder[101];
vector<int>	snake[101];

int	bfs(void)
{
	priority_queue<pii>	pq; // min heap(count, x)

	memset(visited, 1, sizeof(visited));
	pq.push({ 0, START });
	visited[START] = 0;
	while (!pq.empty())
	{
		int	count = -pq.top().first;
		int	x = pq.top().second;
		bool flag = false;
		pq.pop();

		if (x == GOAL)
		{
			return (count);
		}
		// ladder move
		for (int nx: ladder[x])
		{
			visited[nx] = count;
			pq.push({ -count, nx });
			flag = true;
		}
		// snake move
		for (int nx: snake[x])
		{
			visited[nx] = count;
			pq.push({ -count, nx });
			flag = true;
		}
		if (flag)
			continue ;
		// dice move
		for (int dx=1; dx<=6; dx++)
		{
			int	nx = x + dx;

			if (nx > GOAL)
				continue ;
			if (visited[nx] <= count + 1)
				continue ;
			visited[nx] = count + 1;
			pq.push({ -(count + 1), nx });
		}
	}
	return (-1);
}

int	main(void)
{
	cin >> N >> M;

	int x, y;
	for (int i=0; i<N; i++)
	{
		cin >> x >> y;
		ladder[x].push_back(y);
	}
	int	u, v;
	for (int i=0; i<M; i++)
	{
		cin >> u >> v;
		snake[u].push_back(v);
	}
	cout << bfs();
}
