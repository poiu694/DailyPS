#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <deque>

# define	DANGER	1
# define	HELL	2

using namespace std;
using pii = pair<int, int>;

int	map[501][501];
int	dx[4] = { 1, 0, -1, 0 };
int	dy[4] = { 0, 1, 0, -1 };

int	bfs()
{
	deque<pair<pii, int>> q;
	bool	visited[501][501];

	memset(visited, false, sizeof(visited));
	q.push_front({{ 0, 0 }, 0 });
	visited[0][0] = true;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int	life = q.front().second;
		q.pop_front();

		if (x == 500 && y == 500)
			return (life);

		for (int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx > 500 | ny > 500)
				continue ;
			if (map[nx][ny] == HELL)
				continue ;
			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				if (map[nx][ny] == DANGER)
				{
					q.push_back({{ nx, ny }, life + 1 });
				}
				else
				{
					q.push_front({{ nx, ny }, life });
				}
			}
		}
	}
	return (-1);
}

int	main(void)
{
	int	N, M;
	int x1, x2, y1, y2;

	memset(map, 0, sizeof(map));
	cin >> N;
	while (N--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i=min(x1, x2); i<=max(x1, x2); i++)
		{
			for (int j=min(y1, y2); j<=max(y1, y2); j++)
			{
				map[i][j] = DANGER;
			}
		}
	}
	cin >> M;
	while (M--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i=min(x1, x2); i<=max(x1, x2); i++)
		{
			for (int j=min(y1, y2); j<=max(y1, y2); j++)
			{
				map[i][j] = HELL;
			}
		}
	}

	cout << bfs();
}
