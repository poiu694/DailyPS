#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void	fast_IO(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

bool	is_square_number(int n)
{
	int	root;

	root = (int)sqrt(n);
	if (root * root == n)
		return (true);
	return (false);
}

int	get_answer(int N, int M, vector<vector<int>> &board)
{
	int	x, y;
	int	now;
	int	ans;

	ans = -1;
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			for (int dx=-N; dx<N; dx++)
				for (int dy=-M; dy<M; dy++)
				{
					if (dx == 0 and dy == 0)
						continue;
					x = i;
					y = j;
					now = 0;
					while (x > 0 and x <= N and y > 0 and y <= M)
					{
						now = now * 10;
						now = now + board[x][y];
						if (is_square_number(now) and ans < now)
							ans = now;
						x = x + dx;
						y = y + dy;
					}
					if (is_square_number(now) and ans < now)
						ans = now;	
				}
	return (ans);
}

void	get_solution(void)
{
	int					N, M;
	int					ans;
	string				temp;
	vector<vector<int>>	board;

	cin >> N >> M;
	board.resize(N + 1, vector<int>(M + 1, 0));
	for (int i=1; i<=N; i++)
	{
		cin >> temp;
		for (int j=1; j<=M; j++)
			board[i][j] = temp[j-1] - '0';
	}
	ans = get_answer(N, M, board);
	cout << ans;
}

int	main(void)
{
	fast_IO();
	get_solution();
}
