#include <iostream>
#include <cstring>

using namespace std;

int	zero_count;
int	board[10][10];
bool	flag = false;

bool	check_horizon(int line, int target)
{
	for (int i=0; i<9; i++)
	{
		if (board[line][i] == target)
			return (false);
	}
	return (true);
}

bool	check_vertical(int line, int target)
{
	for (int i=0; i<9; i++)
	{
		if (board[i][line] == target)
			return (false);
	}
	return (true);
}

bool	check_zone(int x, int y, int target)
{
	for (int i=x*3; i<x*3+3; i++)
	{
		for (int j=y*3; j<y*3+3; j++)
		{
			if (board[i][j] == target)
				return (false);
		}
	}
	return (true);
}

void	go(int depth)
{
	if (zero_count == depth)
	{
		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
		flag = true;
		return ;
	}
	/*
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			if (board[i][j] == 0)
			{
				for (int k=1; k<=9; k++)
				{
					if (check_horizon(i, k) && check_vertical(j, k) && check_zone(i/3, j/3, k))
					{
						board[i][j] = k;
						go(depth + 1);
					}
					if (flag)
						return ;
				}
				board[i][j] = 0;
				return ;
			}
		}
	}
}

int	main(void)
{
	for (int i=0; i<9; i++)
	{
		for (int j=0; j<9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
				zero_count++;
		}
	}
	go(0);
}
