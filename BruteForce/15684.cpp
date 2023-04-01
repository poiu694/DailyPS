#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

#define MAX 987654321

using namespace std;

int	l, r;
int	N, M, H;
int	map[100][100];
int answer;

bool	is_finish(void)
{
	for (int i=1; i<=N; i++)
	{
		int col = i;
		for (int j=1; j<=H; j++)
		{
			if (map[j][col]) col++;
			else if (map[j][col-1]) col--;
		}
		if (col != i)
			return (false);
	}
	return (true);
}

void	dfs(int depth, int x, int y)
{
	if (depth > 3)
	{
		return ;
	}
	if (is_finish())
	{
		answer = min(answer, depth);
		return ;
	}
	for (int i=y; i<=H; i++)
	{
		for (int j=x; j<=N; j++)
		{
			if (map[i][j] || map[i][j - 1] || map[i][j + 1])
				continue ;
			map[i][j] = true;
			dfs(depth + 1, j, i);
			map[i][j] = false;
		}
		x = 1;
	}
}

int	main(void)
{
	cin >> N >> M >> H;
	memset(map, 0, sizeof(map));
	answer = MAX;
	while (M--)
	{
		cin >> l >> r;
		map[l][r] = true;
	}
	dfs(0, 1, 1);
	answer = answer == MAX ? -1 : answer;
	cout << answer;
}
