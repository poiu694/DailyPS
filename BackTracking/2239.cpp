#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using pii=pair<int, int>;

string	board[9];

// 0 1 2 => 0
// 3 4 5 => 3
// 6 7 8 => 6
pii	get_top_left_position(int x, int y)
{
	int	sx, sy;

	sx = (x / 3) * 3;
	sy = (y / 3) * 3;
	return { sx, sy };
}

bool	check_cell_sudoku(int x, int y, char value)
{
	pii	start_position;

	start_position = get_top_left_position(x, y);
	for (int i=start_position.first; i<start_position.first + 3; i++)
	{
		for (int j=start_position.second; j<start_position.second + 3; j++)
		{
			if (board[i][j] == value)
				return (false);
		}
	}
	return (true);
}

bool	check_horizon_sudoku(int x, char value)
{
	for (int i=0; i<9; i++)
	{
		if (board[x][i] == value)
			return (false);
	}
	return (true);
}

bool	check_vertical_sudoku(int y, char value)
{
	for (int i=0; i<9; i++)
	{
		if (board[i][y] == value)
			return (false);
	}
	return (true);
}

void	print_board(void)
{
	for (int i=0; i<9; i++)
		cout << board[i] << "\n";

	cout << '\n';
}

void	make_full_sudoku_board(int x, int y)
{
	if (x == 9)
	{
		print_board();
		exit(0);
	}

	if (y == 9)
	{
		make_full_sudoku_board(x + 1, 0);
		return ;
	}

//	cout << x << " " <<  y << '\n';
//	print_board();

	if (board[x][y] == '0')
	{
		for (char cell: { '1', '2', '3', '4', '5', '6', '7', '8', '9' })
		{
			if (check_cell_sudoku(x, y, cell) && check_horizon_sudoku(x, cell) && check_vertical_sudoku(y, cell))
			{
				board[x][y] = cell;
				make_full_sudoku_board(x, y + 1);
			}
		}
		board[x][y] = '0';
	}
	else
	{
		make_full_sudoku_board(x, y + 1);
	}
}

int	main(void)
{
	for (int i=0; i<9; i++)
		cin >> board[i];
	make_full_sudoku_board(0, 0);
}
