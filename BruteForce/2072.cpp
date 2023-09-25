#include <iostream>
#include <cstring>

# define WHITE	1
# define BLACK	2
# define SIZE	20

using namespace std;

int	N;
int	board[25][25];

bool	is_vertical_omok(int x, int y)
{
	int	nx;
	int	cnt;

	cnt = 0;
	nx = x;
	while (nx > 0 && board[nx - 1][y] == board[x][y])
		nx--;
	while (nx < SIZE && board[nx][y] == board[x][y])
	{
		nx++;
		cnt++;
	}
	if (cnt == 5)
		return (true);
	return (false);
}

bool	is_horizon_omok(int x, int y)
{
	int	ny;
	int	cnt;

	cnt = 0;
	ny = y;
	while (ny > 0 && board[x][ny - 1] == board[x][y])
		ny--;
	while (ny < SIZE && board[x][ny] == board[x][y])
	{
		ny++;
		cnt++;
	}
	if (cnt == 5)
		return (true);
	return (false);
}

bool	is_diagonal_omok(int x, int y)
{
	int	nx, ny;
	int	cnt;

	cnt = 0;
	nx = x; ny = y;
	while (nx > 0 && ny > 0 && board[nx - 1][ny - 1] == board[x][y])
	{
		nx--; ny--;
	}
	while (nx < SIZE && nx < SIZE && board[nx][ny] == board[x][y])
	{
		nx++; ny++;
		cnt++;
	}
	if (cnt == 5)
		return (true);
	cnt = 0;
	nx = x; ny = y;
	while (nx < SIZE - 1 && ny > 0 && board[nx + 1][ny - 1] == board[x][y])
	{
		nx++; ny--;
	}
	while (nx > 0 && ny < SIZE && board[nx][ny] == board[x][y])
	{
		nx--; ny++;
		cnt++;
	}
	if (cnt == 5)
		return (true);
	return (false);
}

bool	is_finish_game(int x, int y)
{
	if (is_vertical_omok(x, y) || is_horizon_omok(x, y) || is_diagonal_omok(x, y))
		return (true);
	return (false);
}

int	main(void)
{
	int	answer;

	answer = -1;
	memset(board, 0, sizeof(board));
	cin >> N;
	for (int count=1; count<=N; count++)
	{
		int	x, y;
		int	type;

		cin >> x >> y;
		type = count % 2 == 1 ? WHITE : BLACK;
		board[x][y] = type;
		if (is_finish_game(x, y))
		{
			answer = count;
			break ;
		}
	}
	cout << answer;
}
