#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
using pii=pair<int, int>;

int	N;
int	dx[4] = { 1, 0, -1, 0 };
int	dy[4] = { 0, 1, 0, -1 };
int	visited[55][55];
char	map[55][55];
pii	d1, d2;

pii	next_dir(int dir)
{
	if (dir == 0 || dir == 2)
		return { 1, 3 };
	return { 0, 2 };
}

int	bfs(void)
{
	int	result;
	priority_queue<pair<int, pair<pii, int>>> pq;

	result = INT_MAX;
	memset(visited, 0, sizeof(visited));
	for (int dir=0; dir<4; dir++)
		pq.push({ 0, { d1, dir }});
	while (!pq.empty())
	{
		int	cnt = -pq.top().first;
		int x = pq.top().second.first.first;
		int y = pq.top().second.first.second;
		int dir = pq.top().second.second;
		pq.pop();

//		cout << map[x][y] << " " << x << " " << y << " dir: " << dir << " cnt: " << cnt << '\n';
		if (x == d2.first && y == d2.second)
		{
			result = cnt;
			break ;
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue ;
		if (map[nx][ny] == '*')
			continue ;
		else if (map[nx][ny] == '!')
		{
			pii ndir = next_dir(dir);
			for (int next_dir: { ndir.first, ndir.second })
				pq.push({ -(cnt + 1), {{ nx, ny }, next_dir }});
		}
		pq.push({ -cnt, {{ nx, ny }, dir }});
	}
	return (result);
}

int	main(void)
{
	string	temp;

	d1 = d2 = { -1, -1 };
	cin >> N;
	for (int i=0; i<N; i++)
	{
		cin >> temp;
		for (int j=0; j<N; j++)
		{
			map[i][j] = temp[j];
			if (map[i][j] == '#' && d1.first == -1)
				d1 = { i, j };
			else if (map[i][j] == '#')
				d2 = { i, j };
		}
	}
	cout << bfs();
}


