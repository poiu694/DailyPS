#include <iostream>
#include <cstring>

# define CELL	1

using namespace std;

int	N, M;
int	board[501][501];
int	maxCount;
int	width;
bool	visited[501][501];

void	search(int x, int y)
{
	if (visited[x][y])
		return ;
	width++;
	visited[x][y] = true;
	if (x + 1 < N && board[x + 1][y] == CELL)
		search(x + 1, y);
	if (x > 0 && board[x - 1][y] == CELL)
		search(x - 1, y);
	if (y + 1 < M && board[x][y + 1] == CELL)
		search(x, y + 1);
	if (y > 0 && board[x][y - 1] == CELL)
		search(x, y - 1);
}

int	main(void)
{
	int	count;

	cin >> N >> M;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			cin >> board[i][j];

	maxCount = 0;
	count = 0;
	memset(visited, false, sizeof(visited));
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			if (board[i][j] == CELL && !visited[i][j])
			{
				count++;
				width = 0;
				search(i, j);
				maxCount = maxCount > width ? maxCount : width;
			}
		}
	}
	cout << count << '\n' << maxCount << '\n';
}
