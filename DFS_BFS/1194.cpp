#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

# define MINSIK	'0'
# define WALL	'#'
# define EXIT	'1'

using namespace std;
using pii = pair<int, int>;

int	N, M;
int	dx[4] = { 1, 0, -1, 0 };
int	dy[4] = { 0, 1, 0, -1 };
bool	visited[51][51][65];
string	board[51];

bool	is_key(char ch)
{
	return ('a' <= ch && ch <= 'f');
}

bool	is_door(char ch)
{
	return ('A' <= ch && ch <= 'F');
}

int	ch_key_to_int(char ch)
{
	return (pow(2, (ch - 'a')));
}

// fedcba
// 101001 = 41
bool	has_target_key(char ch, int keys)
{
	switch (ch)
	{
		case 'a':
		case 'A':
			return (keys % 2 == 1);
		case 'b':
		case 'B':
			return ((keys / 2) % 2 == 1);
		case 'c':
		case 'C':
			return ((keys / 4) % 2 == 1);
		case 'd':
		case 'D':
			return ((keys / 8) % 2 == 1);
		case 'e':
		case 'E':
			return ((keys / 16) % 2 == 1);
		case 'f':
		case 'F':
			return ((keys / 32) % 2 == 1);
		default:
			return (false);
	}
}

int	bfs(int sx, int sy)
{
	queue<pair<pii, pii>>	q; // position(x, y), (time, has_key)

	memset(visited, false, sizeof(visited));
	visited[sx][sy][0] = true;
	q.push({{ sx, sy }, { 0, 0 }});
	while (!q.empty())
	{
		int	x = q.front().first.first;
		int	y = q.front().first.second;
		int time = q.front().second.first;
		int	keys = q.front().second.second;
		q.pop();

		if (board[x][y] == EXIT)
		{
			return (time);
		}

		for (int i=0; i<4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// OOB
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue ;
			char ncell = board[nx][ny];
			// WALL
			if (ncell == WALL)
				continue ;
			if (visited[nx][ny][keys])
				continue ;
			// DOOR, has not proper key
			if (is_door(ncell) && !has_target_key(ncell, keys))
				continue ;

			if (is_key(ncell) && !has_target_key(ncell, keys))
			{
				visited[nx][ny][keys + ch_key_to_int(ncell)] = true;
				q.push({{ nx, ny }, { time + 1, keys + ch_key_to_int(ncell) }});
			}
			else
			{
				visited[nx][ny][keys] = true;
				q.push({{ nx, ny }, { time + 1, keys }});
			}
		}
	}
	return (-1);
}

int	main(void)
{
	int	sx, sy;

	cin >> N >> M;
	for (int i=0; i<N; i++)
	{
		cin >> board[i];
		for (int j=0; j<board[i].length(); j++)
		{
			if (board[i][j] == MINSIK)
			{
				sx = i;
				sy = j;
			}
		}
	}
	
	cout << bfs(sx, sy);
}
