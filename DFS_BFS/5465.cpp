#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;
using pii = pair<int, int>;

vector<string>	updateMapWithBeeMoving(int N, vector<string> map)
{
	vector<string>	ret(map);

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			if (map[i][j] == 'H')
			{
				if (i > 0 && (ret[i - 1][j] == 'G' || ret[i - 1][j] == 'M'))
					ret[i - 1][j] = 'H';
				if (j > 0 && (ret[i][j - 1] == 'G' || ret[i][j - 1] == 'M'))
					ret[i][j - 1] = 'H';
				if (i < N && (ret[i + 1][j] == 'G' || ret[i + 1][j] == 'M'))
					ret[i + 1][j] = 'H';
				if (j < N && (ret[i][j + 1] == 'G' || ret[i][j + 1] == 'M'))
					ret[i][j + 1] = 'H';
			}
		}
	}
	return (ret);
}

int	bfs(int N, int S, vector<string> map)
{
	int	dx[4] = { 1, 0, -1, 0 };
	int	dy[4] = { 0, 1, 0, -1 };
	int	maxTime;
	int	size;
	int	visited[801][801];
	bool	flag;
	queue<pair<pii, int>>	q;

	memset(visited, 0, sizeof(visited));
	maxTime = -1;
	flag = false;
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			if (map[i][j] == 'M')
			{
				q.push({{ i, j }, 0 });
				visited[i][j] = 0;
			}
		}
	}
		cout << '\n';
	while (!q.empty())
	{
		size = q.size();
		for (int i=0; i<size; i++)
		{
			int	x = q.front().first.first;
			int	y = q.front().first.second;
			int	time = q.front().second;
			q.pop();

			if (map[x][y] == 'D')
			{
				flag = true;
				maxTime = maxTime > time ? maxTime : time;
				continue ;
			}
			else if (map[x][y] == 'M')
			{
				visited[x][y] = true;
				q.push({{ x, y }, time + 1});
			}
			for (int j=-S; j<=S; j++)
			{
				for (int k=-S; k<=S; k++)
				{
					if (abs(j) + abs(k) == S)
					{
						int nx = x + j;
						int ny = y + k;
						
						if (nx < 0 || ny < 0 || nx >= N || ny >= N)
							continue ;
						if (visited[nx][ny] > time)
							continue ;
						if (map[nx][ny] == 'T' || map[nx][ny] == 'H')
							continue ;
						visited[nx][ny] = time;
						q.push({{ nx, ny }, time });
					}
				}
			}
			/*
			for (int j=0; j<4; j++)
			{
				int	nx = x;
				int ny = y;

				for (int k=0; k<S; k++)
				{
					nx += dx[j];
					ny += dy[j];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N)
						continue ;
					if (visited[nx][ny] > time)
						continue ;
					if (map[nx][ny] == 'T' || map[nx][ny] == 'H')
						continue ;
					visited[nx][ny] = time;
					cout << "push : " << nx << " " << ny << " " << time << '\n';
					q.push({{ nx, ny }, time });
				}
			}
			*/
		}
		map = updateMapWithBeeMoving(N, map);
	}
	return (flag ? maxTime : -1);
}

int	main(void)
{
	int	N, S;
	vector<string>	map;

	cin >> N >> S;
	map.resize(N);
	for (int i=0; i<N; i++)
		cin >> map[i];
	cout << bfs(N, S, map);
}
