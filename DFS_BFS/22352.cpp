#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int	N, M;
int	original[31][31];
int after[31][31];
int	temp[31][31];
bool	visited[31][31];
int	dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void	copy_map(void)
{
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			temp[i][j] = original[i][j];
}

bool	is_same_map(void)
{
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			if (after[i][j] != temp[i][j])
				return (false);
	return (true);
}

bool	bfs(int startX, int startY)
{
	int	target;
	int	afterTarget;
	queue<pii>	q;

	target = temp[startX][startY];
	afterTarget = after[startX][startY];
	q.push({ startX,  startY });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		temp[x][y] = afterTarget;
		for (int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue ;
			if (temp[nx][ny] != target)
				continue ;
			if (visited[nx][ny])
				continue ;
			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}
	if (is_same_map())
		return (true);
	return (false);
}

int	main(void)
{
	cin >> N >> M;

	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			cin >> original[i][j];
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			cin >> after[i][j];
	for (int i=0; i<N; i++)
	{
		memset(visited, false, sizeof(visited));
		for (int j=0; j<M; j++)
		{
			if (!visited[i][j])
			{
				copy_map();
				if (bfs(i, j))
				{
					cout << "YES";
					return (0);
				}
			}
		}
	}
	cout << "NO";
	return (0);
}
