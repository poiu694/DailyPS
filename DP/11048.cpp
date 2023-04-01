#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;
using pii = pair<int, int>;

int	N, M;
int map[1001][1001];
int	visited[1001][1001];
int	dp[1001][1001];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int	bfs(void)
{
	int	ans;
	queue<pair<pii, int>>	q;

	memset(visited, 0, sizeof(visited));
	q.push({{ 0, 0 }, map[0][0]});
	visited[0][0] = map[0][0];
	ans = -1;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			ans = max(ans, cnt);
			continue ;
		}
		for (int i=0; i<2; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= N || ny >= M)
				continue ;
			if (visited[nx][ny] < map[nx][ny] + cnt)
			{
				q.push({{ nx, ny }, cnt + map[nx][ny]});
				visited[nx][ny] = map[nx][ny] + cnt;
			}
		}
	}
	return (ans);
}

int	dynamic_programming(void)
{
	memset(dp, -1, sizeof(dp));
	dp[0][0] = map[0][0];
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			if (i - 1 >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + map[i][j]);
			if (j - 1 >= 0)
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + map[i][j]);
		}
	}
	return (dp[N - 1][M -1]);
}

int	main(void)
{
	cin >> N >> M;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			cin >> map[i][j];
	cout << dynamic_programming();
}
