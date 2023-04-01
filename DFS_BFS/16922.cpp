#include <iostream>
#include <cstring>

using namespace std;

int	N;
int	visited[21][21][21][21];
int	sumVisited[1005];
int	cnt;

void	dfs(int depth, int i1, int i5, int i10, int i50)
{
	if (visited[i1][i5][i10][i50])
	{
		return ;
	}
	if (N == depth)
	{
		if (!visited[i1][i5][i10][i50] && !sumVisited[i1 + i5 * 5 + i10 * 10 + i50 * 50])
		{
			cnt++;
			visited[i1][i5][i10][i50] = true;
			sumVisited[i1 + i5 *5 + i10*10 + i50*50] = true;
		}
		return ;
	}
	visited[i1][i5][i10][i50] = true;
	dfs(depth + 1, i1 + 1, i5, i10, i50);
	dfs(depth + 1, i1, i5 + 1, i10, i50);
	dfs(depth + 1, i1, i5, i10 + 1, i50);
	dfs(depth + 1, i1, i5, i10, i50 + 1);
}

int	main(void)
{
	cin >> N;

	memset(visited, 0, sizeof(visited));
	memset(sumVisited, 0, sizeof(sumVisited));
	cnt = 0;
	dfs(0, 0, 0, 0, 0);
	cout << cnt;
}
