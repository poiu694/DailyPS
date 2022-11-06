#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define	INF	987654321

using namespace std;
using pii = pair<int, int>;

int	N, M, K;
int	dx[4] = { 1, 0, -1, 0 };
int	dy[4] = { 0, 1, 0, -1 };

int	bfs(vector<string> map, int sX, int sY, int eX, int eY)
{	
	queue<pii>	q;
	int	visited[1001][1001];

	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			visited[i][j] = INF;
	q.push({ sX, sY });
	visited[sX][sY] = 0;
	while (!q.empty())
	{
		int	x = q.front().first;
		int	y = q.front().second;
		q.pop();

		if (x == eX && y == eY)
		{
			return (visited[x][y]);
		}
		for (int i=0; i<4; i++)
		{
			int nx = x;
			int ny = y;

			// 1 ~ K move
			for (int j=0; j<K; j++)
			{
				nx += dx[i];
				ny += dy[i];

				// out of bounds
				if (nx < 0 || nx >= N)
					break ;
				if (ny < 0 || ny >= M)
					break ;
				// wall check
				if (map[nx][ny] == '#')
					break ;
				// visited time check
				if (visited[nx][ny] < visited[x][y] + 1)
					break ;
				if (visited[nx][ny] == INF)
				{
					q.push({ nx, ny });
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
	}	
	return (-1);
}

int	main(void)
{
	int	sX, sY, eX, eY;
	string	input;
	vector<string>	map;

	cin >> N >> M >> K;
	map.resize(N);
	for (int i=0; i<N; i++)
	{
		cin >> input;
		map[i].resize(M);
		map[i] = input;
	}
	cin >> sX >> sY >> eX >> eY;
	cout << bfs(map, sX - 1, sY - 1, eX - 1, eY - 1);
}
