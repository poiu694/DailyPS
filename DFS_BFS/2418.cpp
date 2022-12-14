#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int	dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int	dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
string	map[201];

long long	bfs(string target, int W, int H)
{
	long long	cnt;
	queue<pair<pii, int>>	q;
	bool	visited[201][201][101];

	memset(visited, false, sizeof(visited));
	for (int i=0; i<W; i++)
	{
		for (int j=0; j<H; j++)
		{
			if (map[i][j] == target[0])
			{
				visited[i][j][0] = true;
				q.push({{ i, j }, 1 });
			}
		}
	}
	cnt = 0;
	while (!q.empty())
	{
		int	x = q.front().first.first;
		int y = q.front().first.second;
		int	targetIndex = q.front().second;
		q.pop();

		if (targetIndex == target.length())
		{
			cnt++;
			continue ;
		}
		for (int i=0; i<8; i++)
		{
			int	nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= W || ny >= H)
				continue ;
			if (visited[nx][ny][targetIndex])
				continue ;
			if (map[nx][ny] == target[targetIndex])
			{
				q.push({{ nx, ny }, targetIndex + 1 });
				visited[nx][ny][targetIndex + 1] = true;
			}
		}
	}
	return (cnt);
}

int	main(void)
{
	int	W, H, L;
	string	target;

	cin >> W >> H >> L;
	for (int i=0; i<W; i++)
		cin >> map[i];
	cin >> target;
	cout << bfs(target, W, H);
}
