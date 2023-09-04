#include <iostream>
#include <cstring>
#include <cmath>

# define SUCCESS	1

using namespace std;

int	N;
int	board[16];

bool	check_position(int depth)
{
	for (int i=0; i<depth; i++)
	{
		if (board[depth] == board[i])
			return (false);
		if (depth - i == abs(board[depth] - board[i]))
			return (false);
	}
	return (true);
}

int	n_queen_search(int depth)
{
	int	count;

	if (depth == N)
	{
		return (SUCCESS);
	}
	count = 0;
	for (int i=0; i<N; i++)
	{
		board[depth] = i;
		if (check_position(depth))
			count += n_queen_search(depth + 1);
	}
	return (count);
}

// o x x x x
// x x o x x
// x x x x o
// x o x x x
// x x x o x
int	main(void)
{
	memset(board, -1, sizeof(board));

	cin >> N;
	cout << n_queen_search(0);
}
