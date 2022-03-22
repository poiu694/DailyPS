#include <iostream>
#include <vector>

using namespace std;

typedef	enum
{
	EAST = 1,
	WEST,
	NORTH,
	SOUTH
}	Direction;

bool	is_inmap(int N, int M, int x, int y)
{
	return (0 <= x && x < N && 0 <= y && y < M);
}

void	move_dice(int dice_index[], int op)
{
	int	top;

	top = dice_index[0];
	switch (op)
	{
		case EAST:
			dice_index[0] = dice_index[4];
			dice_index[4] = dice_index[5];
			dice_index[5] = dice_index[2];
			dice_index[2] = top;
			break ;
		case WEST:
			dice_index[0] = dice_index[2];
			dice_index[2] = dice_index[5];
			dice_index[5] = dice_index[4];
			dice_index[4] = top;
			break ;
		case NORTH:
			dice_index[0] = dice_index[1];
			dice_index[1] = dice_index[5];
			dice_index[5] = dice_index[3];
			dice_index[3] = top;
			break ;
		case SOUTH:
			dice_index[0] = dice_index[3];
			dice_index[3] = dice_index[5];
			dice_index[5] = dice_index[1];
			dice_index[1] = top;
			break ;
		default:
			break;
	}
}

int	main(void)
{
	int	N, M, x, y, K;
	int	op;
	int	map[21][21];
	int	dice_num[6]	= {0};
	int	dice_index[6] = {1, 5, 3, 2, 4, 6};
	int	dx[4] = {0, 0, -1, 1};
	int	dy[4] = {1, -1, 0, 0};

	cin >> N >> M >> x >> y >> K;
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			cin >> map[i][j];
	while (K--)
	{
		cin >> op;
		x += dx[op - 1];
		y += dy[op - 1];
		if (!is_inmap(N, M, x, y))
		{
			x -= dx[op - 1];
			y -= dy[op - 1];
			continue ;
		}
		move_dice(dice_index, op);
		cout << dice_num[dice_index[0] - 1] << '\n';
		if (map[x][y] != 0)
		{
			dice_num[dice_index[5] - 1] = map[x][y];
			map[x][y] = 0;
		}
		else
		{
			map[x][y] = dice_num[dice_index[5] - 1];
		}
	}
}
