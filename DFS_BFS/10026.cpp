#include <iostream>
#include <cstring>

# define RED	'R'
# define GREEN	'G'
# define BLUE	'B'

using namespace std;

int	N;
int	dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string	board[101];
bool	visited[101][101];

bool	is_red_or_green(char cell)
{
	return (cell == RED || cell == GREEN);
}

void	dfs(int x, int y, bool color_blind_mode)
{
	if (visited[x][y])
		return ;
	visited[x][y] = true;

	for (int i=0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue ;
		if (color_blind_mode)
			if (is_red_or_green(board[x][y]) && is_red_or_green(board[nx][ny]))
				dfs(nx, ny, color_blind_mode);
		if (board[x][y] == board[nx][ny])
			dfs(nx, ny, color_blind_mode);
	}
}

int	get_count_of_block(bool color_blind_mode)
{
	int	result;

	result = 0;
	memset(visited, false, sizeof(visited));
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			if (!visited[i][j])
			{
				result++;
				dfs(i, j, color_blind_mode);
			}
		}
	}
	return (result);
}

int	main(void)
{
	cin >> N;

	for (int i=0; i<N; i++)
		cin >> board[i];
	
	int	blind_count = get_count_of_block(true);
	int	non_blind_count = get_count_of_block(false);
	cout << non_blind_count << " " << blind_count << "\n";
}
